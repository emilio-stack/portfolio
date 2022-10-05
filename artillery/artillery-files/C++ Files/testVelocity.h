/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Preston Millward
 * Summary:
 *    All the unit tests for Velocity
 ************************************************************************/


#pragma once

#include <iostream>
#include <cassert>
#include "velocity.h"
#include "accelerationMock.h"

using namespace std;

class TestVelocity
{
public:

   // Runs all the test cases
   void run()
   {
      testTwoComponentConstructor();
      testMagAngleConstructor();
   }

   // Determines if the left floating point number is close enough to the right one.
   bool decimalCloseEnough(double lDecimal, double rDecimal, double minDiff = 0.0005) const
   {
      return abs(lDecimal - rDecimal) < minDiff;
   }

   void testTwoComponentConstructor()
   {
      // setup
      // exercise
      Velocity vel = Velocity(5.0, 7.0);
      // verify
      assert(vel.horizontalComponent == 5.0);
      assert(vel.verticalComponent == 7.0);
   }  // teardown

   void testMagAngleConstructor()
   {
      // setup
      // exercise
      Velocity vel = Velocity(AngleMock(45), 2.0);
      // verify
      assert(decimalCloseEnough(vel.horizontalComponent, 1.4142135623730950));
      assert(decimalCloseEnough(vel.verticalComponent, 1.4142135623730950));
   }  // teardown

   void testGetSpeed()
   {
      // setup
      Velocity vel = Velocity();
      vel.horizontalComponent = 3.0;
      vel.verticalComponent = 4.0;
      // exercise
      double speed = vel.getSpeed();
      // verify
      assert(speed == 5.0);
   }  // teardown

   void testApplyAcceleration()
   {
      // setup
      Velocity vel = Velocity();
      vel.horizontalComponent = -23.0;
      vel.verticalComponent = 4.5;
      AccelerationMock accel = AccelerationMock(-2, 5);
      // exercise
      vel.applyAcceleration(accel, 2);
      // verify
      assert(vel.horizontalComponent == -27.0);
      assert(vel.verticalComponent == 14.5);
   }  // teardown
};