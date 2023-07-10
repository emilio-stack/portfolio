/***********************************************************************
 * Source File:
 *    Simulator : Represents all the moving parts we need to keep track
 *    of, and how they interact over time.
 * Author:
 *    Emilio Regino
 * Summary:
 *    Operates the movement, drawing, and interaction of the simulation.
 ************************************************************************/

#pragma once

const int NUM_STARS = 40;                       // number of stars in simulator
const double SECONDS_PER_FRAME = 1.0/10.0;      // number of seconds per frames

/**********************************************************************
 * SIMULATOR
 * A program to run the Lunar Lander Simulator
 * draw something on the window, accept user input, and
 * update the window.
 **********************************************************************/
class Simulator
{
public:
   Simulator(const Point& ptUpperRight):
         ptUpperRight(ptUpperRight),
         landerStartingPoint(Point(ptUpperRight.getX() / 2.0,           /* half the max X position */
                                   ptUpperRight.getY() * 3.0 / 4.0,     /* 3/4 the max Y position */
                                   ptUpperRight)),                      /* boundry point */
         lander(LunarLander(landerStartingPoint)),
         ground(Ground(ptUpperRight))
         {
            for (int i = 0; i < NUM_STARS; i++)
               stars[i] = Star(ptUpperRight);              // initialize the stars with a boundary point
         }
   
   // Simulator methods
   void getInput(const Interface *pUI);
   void update();
   void draw(ogstream& gout);

private:
   Point ptUpperRight;              // the size of the screen
   Point landerStartingPoint;       // the spawn point of the lander
   LunarLander lander;              // the lander object
   Ground ground;                   // the ground object
   Star stars[NUM_STARS];           // an array of star objects
};
