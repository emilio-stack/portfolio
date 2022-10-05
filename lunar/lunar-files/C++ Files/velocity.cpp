/***********************************************************************
 * Source File:
 *    Velocity : Represents an object's velocity in the lunar lander game.
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about a velocity of an object.
 ************************************************************************/

#include "velocity.h"
#include <cmath> // sqrt

/*********************************************
 * VELOCITY : CONSTRUCTOR WITH DX,DY
 * Initialize the velocity to the passed velocity.
 ********************************************/
Velocity::Velocity(double dx, double dy) : dx(0.0), dy(0.0)
{
   setDx(dx);
   setDy(dy);
}

/*********************************************
 * GET SPEED 
 * Calculate the speed represented by this velocity
 * via pythagorean theorem.
 * C^2 = A^2 + B^2
 ********************************************/
double Velocity::getSpeed() const
{
   return sqrt(dx * dx + dy * dy);
}