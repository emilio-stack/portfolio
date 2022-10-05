/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include <cassert>

double Position::metersFromPixels = 40.0;

/******************************************
* POINT : non-default constructor
* create a point in x,y in meters
*****************************************/
Position::Position(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

/******************************************
* POINT: ADD ACCELERATION VELOCITY
* Adds acceleration and velocity to this
* point using the equation
* x1 = x0 + t*vx + 1/2 * ax * t * t
* y1 = y0 + t*vy + 1/2 * ay * t * t
******************************************/
void Position::applyAccelerationVelocity(Acceleration accel, Velocity vel, double time)
{
   double inertiaX = time * vel.getDX();
   double inertiaY = time * vel.getDY();
   double accelX   = 0.5 * accel.getDDX() * time * time;
   double accelY   = 0.5 * accel.getDDY() * time * time;
   addMetersX(inertiaX + accelX);
   addMetersY(inertiaY + accelY);
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Position& Position::operator = (const Position& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}

/******************************************
 * POSITION insertion
 *       Display position on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << ",)";
   return out;
}

/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pos)
{
   double x;
   double y;
   in >> x >> y;

   pos.setMetersX(x);
   pos.setMetersY(y);

   return in;
}
