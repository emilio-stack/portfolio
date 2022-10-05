/***********************************************************************
 * Source File:
 *    Ground : Represents the ground in the artillery simulation
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Where the ground is located and where the target is drawn
 ************************************************************************/

#include "ground.h"   // for the Ground class definition
#include "helpers.h"   // for random() and drawLine()
#include <cassert>
#include <iostream>

#include <iostream>
using namespace std;

const int WIDTH_HOWITZER = 14;

const double MIN_ALTITUDE = 300.0;  // min altitude is at 984'
const double MAX_ALTITUDE = 3000.0; // max altitude is 3,000m or 9842.52ft
const double MAX_SLOPE = 1.0; // steapness of the features. Smaller number is flatter
const double LUMPINESS = 0.15; // size of the hills. Smaller number is bigger features
const double TEXTURE = 3.0;   // size of the small features such as rocks

Ground::Ground(const Position & posUpperRight) :
   posUpperRight(posUpperRight),
   iHowitzer(0),
   ground(NULL)
{
   // allocate the array
   ground = new double[(int)posUpperRight.getPixelsX()];
}

/************************************************************************
 * RESET
 * Create a new ground
 ************************************************************************/
 void Ground :: reset(Position & posHowitzer)
 {
   // remember the integer width for later. It will come in handy
   int width = (int)posUpperRight.getPixelsX();
   assert(width > 0);

   // determine the location of the target
   iHowitzer = (int)(posHowitzer.getPixelsX());
   if (iHowitzer > width / 2)
      posTarget.setPixelsX(random((int)(width * 0.05), (int)(width * 0.45)));
   else
      posTarget.setPixelsX(random((int)(width * 0.55), (int)(width * 0.95)));
   assert(iHowitzer >= 0 && iHowitzer < width);

   // determine the maximum and minimum altitude
   Position posMinimum(0.0, MIN_ALTITUDE);
   Position posMaximum(posUpperRight.getMetersX(), MAX_ALTITUDE);

   // give each location on the ground an elevation
   ground[0] = posMinimum.getPixelsY(); // the initial elevation is low
   double dy = MAX_SLOPE / 2.0;  // the initial slope is heavily biased to up
   for (int i = 1; i < width; i++)
   {
      // put the howitzer on flat ground
      if (i > iHowitzer - WIDTH_HOWITZER / 2 &&
         i < iHowitzer + WIDTH_HOWITZER / 2)
      {
         ground[i] = ground[i - 1];
      }
      else
      {
         // what percentage of the elevation were we at?
         double percent = (ground[i - 1] - posMinimum.getPixelsY()) /
                          (posMaximum.getPixelsY() - posMinimum.getPixelsY());

         // set the slope of the ground
         dy += (1.0 - percent) * random(0.0, LUMPINESS) +
               (percent) * random(-LUMPINESS, 0.0);
         if (dy > MAX_SLOPE)
            dy = MAX_SLOPE;
         if (dy < -MAX_SLOPE)
            dy = -MAX_SLOPE;

         // determine the elevation according to the slope
         ground[i] = ground[i - 1] + dy + random(-TEXTURE, TEXTURE);
      }
   }

   // Place the target on top of the ground
   assert((int)posTarget.getPixelsX() >= 0 && (int)posTarget.getPixelsX() < width);
   posTarget.setPixelsY(ground[(int)posTarget.getPixelsX()]);

   // set the howitzer's elevation
   posHowitzer.setPixelsY(ground[iHowitzer]);
}

/*****************************************************************
 * HIT GROUND
 * Determine if a position has hit the ground.
 ****************************************************************/
bool Ground::hitGround(double x, double y) const
{
   int ix = (int)x;
   if (y == ground[ix])
   {
      return true;
   }
   else
   {
      return false;
   }
}
