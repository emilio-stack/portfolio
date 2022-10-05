/***********************************************************************
 * Source File:
 *    Thrusters : The representation of the thrusters on the Lander
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about the thrusters on the Lander.
 ************************************************************************/

#include "thrusters.h"

const double Thrusters::MAIN_THRUST_AMOUNT = 45000.0;
const double Thrusters::ANGLE_CHANGE_AMOUNT = 0.1;
const char   Thrusters::MAIN_FUEL_PER_IGNITION = 10;
const char   Thrusters::AUXILIARY_FUEL_PER_IGNITION = 1;

/************************************************
* IGNITE THRUSTERS
* Attempts to ignite the thrusters specified
* by the three booleans passed in. If there
* isn't enough fuel, then they won't turn on.
* If there is enough fuel, then fuel is spent
* to turn them on.
*************************************************/
void Thrusters::igniteThrusters(bool main, bool left, bool right)
{
   // Set them to off by default.
   this->main = false;
   this->left = false;
   this->right = false;

   // Check if the main thruster ignites.
   if (getFuel() > 0 && main)
   {
      this->main = true;
      useFuel(this->MAIN_FUEL_PER_IGNITION);
   }
   // Check if the auxiliary thrusters ignite.
   if (getFuel() > 0)
   {
      if (left)
      {
         this->left = true;
         useFuel(this->AUXILIARY_FUEL_PER_IGNITION);
      }
      if (right)
      {
         this->right = true;
         useFuel(this->AUXILIARY_FUEL_PER_IGNITION);
      }
   }
}

/*******************************************
 * GET THRUST
 * Returns the amount of thrust being provided
 * by the main thruster at the moment. If the
 * main thruster is firing, then it returns
 * MAIN_THRUST_AMOUNT, else 0.
 ******************************************/
int Thrusters::getThrust() const
{
   if (main)
      return MAIN_THRUST_AMOUNT;
   else
      return 0;
}

/********************************************
 * GET ROTATION
 * Returns the change in angle provided by the
 * auxiliary thrusters. The left thruster gives
 * positive ANGLE_CHANGE_AMOUNT and the right
 * thruster gives negative ANGLE_CHANGE_AMOUNT.
 *******************************************/
double Thrusters::getRotation() const
{
   // If they're both on or both off, no rotation.
   if (isLeftThrusterOn() == isRightThrusterOn())
      return 0.0;
   else
   {
      if (isLeftThrusterOn())
         return ANGLE_CHANGE_AMOUNT;
      else
         return -ANGLE_CHANGE_AMOUNT;
   }
}
