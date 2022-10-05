/***********************************************************************
 * Source File:
 *    Fuel : Represents how much fuel the thrusters have in the lunar lander game.
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about the thruster's fuel.
 ************************************************************************/

#include "fuel.h"

/************************************************
* SET FUEL
* Sets the fuel available to the given amount.
* If the amount is greater than the max, simply
* sets it to the max amount of fuel. If the
* amount is less than zero, simply sets it to
* zero.
*************************************************/
void Fuel::setFuel(int amount)
{
   fuel = (short)amount;
   if (fuel < 0)
      fuel = 0;
   else if (fuel > this->MAX_FUEL)
      fuel = this->MAX_FUEL;
}