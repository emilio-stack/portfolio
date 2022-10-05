/***********************************************************************
 * Header File:
 *    Thrusters : The representation of the thrusters on the Lander
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about the thrusters on the Lander.
 ************************************************************************/

#pragma once
#include "fuel.h"

/****************************************
 * THRUSTERS
 * The three thrusters of the Lander
 ***************************************/
class Thrusters
{
public:
   // constructor
   Thrusters() : main(false), left(false), right(false), fuel() {}
   
   // setter
   void igniteThrusters(bool main, bool left, bool right);

   // getters
   short getFuel() const { return fuel.getFuel(); }
   bool isMainThrusterOn() const { return main; }
   bool isLeftThrusterOn() const { return left; }
   bool isRightThrusterOn() const { return right; }
   int getThrust() const;          // The amount of thrust these thrusters are supplying
   double getRotation() const;     // The number of radians by which these thrusters are rotating the lander

private:
   static const double MAIN_THRUST_AMOUNT;        // newtons of force provided by the main thruster
   static const double ANGLE_CHANGE_AMOUNT;       // how much a single thruster can rotate the lander
   static const char MAIN_FUEL_PER_IGNITION;      // how much fuel the main engine uses per second
   static const char AUXILIARY_FUEL_PER_IGNITION; // how much fuel the auxiliary engines use per second
   bool main;                                     // whether the main thruster is on
   bool left;                                     // whether the left thruster is on
   bool right;                                    // whether the right thruster is on
   Fuel fuel;                                     // how much fuel the lander has
   void useFuel(int amount) { fuel.useFuel(amount); }
};



