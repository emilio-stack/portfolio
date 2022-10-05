/***********************************************************************
 * Header File:
 *    Test Howitzer : Test the Howitzer class
 * Author:
 *    Preston Millward
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/

#pragma once

#include "howitzer.h"
#include "projectileMock.h"
#include <cassert>

using namespace std;

class TestHowitzer
{
public:

   // Runs all the test cases
   void run()
   {
      // Test position modifiers.
      testPositionConstructor();
      testSetPosition();

      // Test the raise function
      testRaiseNormal();
      testRaiseMin();
      testRaiseMax();
      testRaiseZero();
      testRaiseToZeroNeg();
      testRaiseToZeroPos();
      testRaisePastZeroPos();
      testRaisePastZeroNeg();

      // Test the lower function
      testLowerNormal();
      testLowerMin();
      testLowerMax();
      testLowerZero();
      testLowerToMin();
      testLowerToMax();
      testLowerPastMin();
      testLowerPastMax();

      // Test the clockwise function
      testClockwiseNormal();
      testClockwiseMin();
      testClockwiseMax();
      testClockwiseToMax();
      testClockwisePastMax();

      // Test counterclockwise function
      testCounterClockwiseNormal();
      testCounterClockwiseMin();
      testCounterClockwiseMax();
      testCounterClockwiseToMax();
      testCounterClockwisePastMax();

      // Test the fire function
      testFireUp();
      testFireFirstQuadrant();
      testFireFourthQuadrant();
   }

   // Determines if the left floating point number is close enough to the right one.
   bool decimalCloseEnough(double lDecimal, double rDecimal, double minDiff = 0.0005) const
   {
      return abs(lDecimal - rDecimal) < minDiff;
   }

   void testPositionConstructor()
   {
      // setup
      Position start = Position(125, 256);
      // exercise
      Howitzer how = Howitzer(start);
      // verify
      assert(how.position.getMetersX() == 125);
      assert(how.position.getMetersY() == 256);
      assert(decimalCloseEnough(how.angle.getDegrees(), 0.0));
   }  // teardown

   void testSetPosition()
   {
      // setup
      Position moveTo = Position(125, 256);
      Howitzer how = Howitzer();
      how.position = Position(5, 10);
      // exercise
      how.setPosition(moveTo);
      // verify
      assert(how.position.getMetersX() == 125);
      assert(how.position.getMetersY() == 256);
   }  // teardown

   void testRaiseNormal()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(25);
      // exercise
      how.raise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 24.82811266146));
   }  // teardown

   void testRaiseMin()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-90);
      // exercise
      how.raise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), -89.82811266146));
   }  // teardown

   void testRaiseMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(90);
      // exercise
      how.raise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 89.82811266146));
   }  // teardown

   void testRaiseZero()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(0);
      // exercise
      how.raise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 0.0));
   }  // teardown

   void testRaiseToZeroNeg()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-0.17188733854);
      // exercise
      how.raise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 0.0));
   }  // teardown

   void testRaiseToZeroPos()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(0.17188733854);
      // exercise
      how.raise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 0.0));
   }  // teardown

   void testRaisePastZeroPos()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(0.01);
      // exercise
      how.raise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 0.0));
   }  // teardown

   void testRaisePastZeroNeg()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-0.01);
      // exercise
      how.raise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 0.0));
   }  // teardown

   void testLowerNormal()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(25);
      // exercise
      how.lower();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 25.17188733854));
   }  // teardown

   void testLowerMin()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-90);
      // exercise
      how.lower();
      // verify
      assert(how.angle.getDegrees() == -90);
   }  // teardown

   void testLowerMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(90);
      // exercise
      how.lower();
      // verify
      assert(how.angle.getDegrees() == 90);
   }  // teardown

   void testLowerZero()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(0);
      // exercise
      how.lower();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 0.17188733854));
   }  // teardown

   void testLowerToMin()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-89.82811266146);
      // exercise
      how.lower();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), -90));
   }  // teardown

   void testLowerToMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(89.82811266146);
      // exercise
      how.lower();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 90));
   }  // teardown

   void testLowerPastMin()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-89.9);
      // exercise
      how.lower();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), -90));
   }  // teardown

   void testLowerPastMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(89.9);
      // exercise
      how.lower();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(),  90));
   }  // teardown

   void testClockwiseNormal()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(25);
      // exercise
      how.clockwise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 27.8647889757));
   }  // teardown

   void testClockwiseMin()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-90);
      // exercise
      how.clockwise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), -87.1352110243));
   }  // teardown

   void testClockwiseMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(90);
      // exercise
      how.clockwise();
      // verify
      assert(how.angle.getDegrees() == 90);
   }  // teardown

   void testClockwiseToMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(87.1352110243);
      // exercise
      how.clockwise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 90));
   }  // teardown

   void testClockwisePastMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(89.9);
      // exercise
      how.clockwise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 90));
   }  // teardown

   void testCounterClockwiseNormal()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(25);
      // exercise
      how.counterClockwise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), 22.1352110243));
   }  // teardown

   void testCounterClockwiseMin()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-90);
      // exercise
      how.counterClockwise();
      // verify
      assert(decimalCloseEnough(how.angle.getDegrees(), -90));
   }  // teardown

   void testCounterClockwiseMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(90);
      // exercise
      how.counterClockwise();
      // verify
      assert(how.angle.getDegrees() == 87.1352110243);
   }  // teardown

   void testCounterClockwiseToMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-87.1352110243);
      // exercise
      how.counterClockwise();
      // verify
      assert(how.angle.getDegrees() == -90);
   }  // teardown

   void testCounterClockwisePastMax()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-89.9);
      // exercise
      how.counterClockwise();
      // verify
      assert(how.angle.getDegrees() == -90);
   }  // teardown

   void testFireUp()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(0);
      how.position = Position(25, 30);
      ProjectileMock pm = ProjectileMock();
      pm.position = Position(0, 0);
      pm.velocity = VelocityMock(0, 0);
      pm.status = Projectile::LOADED;
      // exercise
      how.fire(pm);
      // verify
      assert(pm.velocity.getDX() == 0);
      assert(pm.velocity.getDY() == 827.0);
      assert(pm.position.getMetersX() == 25);
      assert(pm.position.getMetersY() == 30);
      assert(pm.status == Projectile::FLYING);
   }  // teardown


   void testFireFirstQuadrant()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(30);
      how.position = Position(25, 30);
      ProjectileMock pm = ProjectileMock();
      pm.position = Position(0, 0);
      pm.velocity = VelocityMock(0, 0);
      pm.status = Projectile::LOADED;
      // exercise
      how.fire(pm);
      // verify
      assert(decimalCloseEnough(pm.velocity.getDX(), 413.5));
      assert(decimalCloseEnough(pm.velocity.getDY(), 716.2030089));
      assert(pm.position.getMetersX() == 25);
      assert(pm.position.getMetersY() == 30);
      assert(pm.status == Projectile::FLYING);
   }  // teardown

   void testFireFourthQuadrant()
   {
      // setup
      Howitzer how = Howitzer();
      how.angle = AngleMock(-70);
      how.position = Position(25, 30);
      ProjectileMock pm = ProjectileMock();
      pm.position = Position(0, 0);
      pm.velocity = VelocityMock(0, 0);
      pm.status = Projectile::LOADED;
      // exercise
      how.fire(pm);
      // verify
      assert(decimalCloseEnough(pm.velocity.getDX(), -777.1257973899));
      assert(decimalCloseEnough(pm.velocity.getDY(), 282.85065853));
      assert(pm.position.getMetersX() == 25);
      assert(pm.position.getMetersY() == 30);
      assert(pm.status == Projectile::FLYING);
   }  // teardown
};