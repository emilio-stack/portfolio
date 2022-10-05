/***********************************************************************
 * Header File:
 *    Test Projectile : Test the Projectile class
 * Author:
 *    Preston Millward
 * Summary:
 *    All the unit tests for Projectile
 ************************************************************************/


#pragma once

#include <iostream>
#include <cassert>
#include "projectile.h"
#include "velocityMock.h"

using namespace std;

class TestProjectile
{
public:

   // Runs all the test cases
   void run()
   {
      test_Projectile_Point_Constructor_Normal();
      test_Projectile_Fire_Zero();
      test_Projectile_Fire_Normal();
      test_Projectile_Fire_Wrong_Status();
      test_Projectile_Land_On_Target_Normal();
      test_Projectile_Land_Off_Target_Normal();
      test_Projectile_Land_Wrong_Status();
      test_Projectile_ShiftShadows_First_Shift();
      test_Projectile_ShiftShadows_Full();
      test_Projectile_ShiftShadows_Wrong_Status();
      test_Projectile_Move_No_Time();
      test_Projectile_Move_Gravity_Only();
      test_Projectile_Move_Horizontal_Velocity();
      test_Projectile_Move_Vertical_Velocity();
      test_Projectile_Move_Normal();
      test_Projectile_Move_Wrong_Status();
      test_Projectile_IsLoaded_True();
      test_Projectile_IsLoaded_False();
      test_Projectile_IsFlying_True();
      test_Projectile_IsFlying_False();
      test_Projectile_IsLanded_On_Target();
      test_Projectile_IsLanded_Off_Target();
      test_Projectile_IsLanded_False();
      test_Projectile_IsOnTarget_True();
      test_Projectile_IsOnTarget_False();
   }

   // Verifies that no shadows have been updated.
   void verifyEmptyShadows(Projectile shell) const
   {
      assert(shell.shadows.size() == 6);
      assert(shell.shadows.at(0).getMetersX() == 0.0);
      assert(shell.shadows.at(0).getMetersY() == 0.0);
      assert(shell.shadows.at(1).getMetersX() == 0.0);
      assert(shell.shadows.at(1).getMetersY() == 0.0);
      assert(shell.shadows.at(2).getMetersX() == 0.0);
      assert(shell.shadows.at(2).getMetersY() == 0.0);
      assert(shell.shadows.at(3).getMetersX() == 0.0);
      assert(shell.shadows.at(3).getMetersY() == 0.0);
      assert(shell.shadows.at(4).getMetersX() == 0.0);
      assert(shell.shadows.at(4).getMetersY() == 0.0);
      assert(shell.shadows.at(5).getMetersX() == 0.0);
      assert(shell.shadows.at(5).getMetersY() == 0.0);
   }

   // Constructs the default projectile.
   Projectile defaultSetup() const
   {
      Projectile shell;
      shell.position = Position(1, 2);
      shell.velocity = VelocityMock(3, 4);
      shell.age = 5;
      shell.status = Projectile::LOADED;
      shell.shadows.push_back(Position(0, 0));
      shell.shadows.push_back(Position(0, 0));
      shell.shadows.push_back(Position(0, 0));
      shell.shadows.push_back(Position(0, 0));
      shell.shadows.push_back(Position(0, 0));
      return shell;
   }

   // Determines if the left floating point number is close enough to the right one.
   bool decimalCloseEnough(double lDecimal, double rDecimal, double minDiff = 0.0005) const
   {
      return abs(lDecimal - rDecimal) < minDiff;
   }

   // Initializing with a point should do the same as the default constructor,
   // except the position of the projectile will be the same as that point.
   // In this case, that's the point (15.4, -17)
   void test_Projectile_Point_Constructor_Normal() const
   {
      // setup
      // exercise
      Projectile shell = Projectile(Position(15.4, -17));
      // verify
      assert(shell.position.getMetersX() == 15.4);
      assert(shell.position.getMetersY() == -17);
      assert(shell.velocity.horizontalComponent == 0.0);
      assert(shell.velocity.verticalComponent == 0.0);
      assert(shell.age == 0);
      assert(shell.status == Projectile::LOADED);
      assert(shell.shadows.size() == 1);
      assert(shell.shadows.at(0).getMetersX() == 15.4);
      assert(shell.shadows.at(0).getMetersY() == -17);
   }  // teardown

   // Fire should set the projectile's status to FLYING and its velocity
   // to whatever velocity it was given. Everything else should not change.
   // In this case, the velocity is zero.
   void test_Projectile_Fire_Zero() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.shadows.clear();
      shell.shadows.push_back(Position(1, 2));
      VelocityMock vm = VelocityMock(0, 0);
      Position p = Position(3, 4);
      // exercise
      shell.fire(vm, p);
      // verify
      assert(shell.position.getMetersX() == 3);
      assert(shell.position.getMetersY() == 4);
      assert(shell.velocity.horizontalComponent == 0);
      assert(shell.velocity.verticalComponent == 0);
      assert(shell.age == 0);
      assert(shell.status == Projectile::FLYING);
      assert(shell.shadows.size() == 1);
      assert(shell.shadows.at(0).getMetersX() == 3);
      assert(shell.shadows.at(0).getMetersY() == 4);
   }  // teardown

   // Fire should set the projectile's status to FLYING and its velocity
   // to whatever velocity it was given. Everything else should not change.
   // In this case, the velocity is (-12, 1.1).
   void test_Projectile_Fire_Normal() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::ON_TARGET;
      shell.velocity.horizontalComponent = 0.0;
      shell.velocity.verticalComponent = 0.0;
      shell.shadows.clear();
      shell.shadows.push_back(Position(1, 2));
      VelocityMock vm = VelocityMock(3, 4);
      Position p = Position(3, 4);
      // exercise
      shell.fire(vm, p);
      // verify
      assert(shell.position.getMetersX() == 3);
      assert(shell.position.getMetersY() == 4);
      assert(shell.velocity.horizontalComponent == 3);
      assert(shell.velocity.verticalComponent == 4);
      assert(shell.age == 0);
      assert(shell.status == Projectile::FLYING);
      assert(shell.shadows.size() == 1);
      assert(shell.shadows.at(0).getMetersX() == 3);
      assert(shell.shadows.at(0).getMetersY() == 4);
   }  // teardown

   // Fire should do nothing if the projectile is FLYING.
   void test_Projectile_Fire_Wrong_Status() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.velocity.horizontalComponent = 0.0;
      shell.velocity.verticalComponent = 0.0;
      shell.status = Projectile::FLYING;
      VelocityMock vm = VelocityMock(3, 4);
      Position p = Position(6, 8);
      // exercise
      shell.fire(vm, p);
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.horizontalComponent == 0);
      assert(shell.velocity.verticalComponent == 0);
      assert(shell.age == 5);
      assert(shell.status == Projectile::FLYING);
      verifyEmptyShadows(shell);
   }  // teardown

   // Land, if given True, should set the velocity to zero and status to
   // ON_TARGET
   void test_Projectile_Land_On_Target_Normal() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      // exercise
      shell.land(true);
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.horizontalComponent == 0);
      assert(shell.velocity.verticalComponent == 0);
      assert(shell.age == 5);
      assert(shell.status == Projectile::ON_TARGET);
      assert(shell.shadows.size() == 1);
      assert(shell.shadows.at(0).getMetersX() == 1);
      assert(shell.shadows.at(0).getMetersY() == 2);
   }  // teardown

   // Land, if given False, should set the velocity to zero and status to
   // OFF_TARGET
   void test_Projectile_Land_Off_Target_Normal() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      // exercise
      shell.land(false);
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.horizontalComponent == 0);
      assert(shell.velocity.verticalComponent == 0);
      assert(shell.age == 5);
      assert(shell.status == Projectile::OFF_TARGET);
      assert(shell.shadows.size() == 1);
      assert(shell.shadows.at(0).getMetersX() == 1);
      assert(shell.shadows.at(0).getMetersY() == 2);
   }  // teardown

   // Land should do nothing if the status is not FLYING
   void test_Projectile_Land_Wrong_Status() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::LOADED;
      // exercise
      shell.land(true);
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.horizontalComponent == 3);
      assert(shell.velocity.verticalComponent == 4);
      assert(shell.age == 5);
      assert(shell.status == Projectile::LOADED);
      verifyEmptyShadows(shell);
   }  // teardown

   // ShiftShadows, if the list of shadows has only one element, will add
   // a new Position to the front of the shadows vector.
   void test_Projectile_ShiftShadows_First_Shift() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      shell.shadows.clear();
      shell.shadows.push_back(Position(0, 0));
      // exercise
      shell.shiftShadows();
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.horizontalComponent == 3);
      assert(shell.velocity.verticalComponent == 4);
      assert(shell.age == 5);
      assert(shell.status == Projectile::FLYING);
      assert(shell.shadows.size() == 2);
      assert(shell.shadows.at(0).getMetersX() == 1);
      assert(shell.shadows.at(0).getMetersY() == 2);
      assert(shell.shadows.at(1).getMetersX() == 0);
      assert(shell.shadows.at(1).getMetersY() == 0);
      
   }  // teardown

   // ShiftShadows, if the list of shadows has NUM_SHADOWS elements, will
   // add a new Position to the front of the shadows vector AND pop the
   // Position at the back of the shadows vector.
   void test_Projectile_ShiftShadows_Full() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      shell.shadows.clear();
      shell.shadows.push_back(Position(5.78, -25.8));
      shell.shadows.push_back(Position(100, 200));
      shell.shadows.push_back(Position(2.5, 6.8));
      shell.shadows.push_back(Position(-1, -6));
      shell.shadows.push_back(Position(5, 7));
      shell.shadows.push_back(Position(0, 0));
      // exercise
      shell.shiftShadows();
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.horizontalComponent == 3);
      assert(shell.velocity.verticalComponent == 4);
      assert(shell.age == 5);
      assert(shell.status == Projectile::FLYING);
      assert(shell.shadows.size() == 6);
      assert(shell.shadows.at(0).getMetersX() == 1);
      assert(shell.shadows.at(0).getMetersY() == 2);
      assert(shell.shadows.at(1).getMetersX() == 5.78);
      assert(shell.shadows.at(1).getMetersY() == -25.8);
      assert(shell.shadows.at(2).getMetersX() == 100);
      assert(shell.shadows.at(2).getMetersY() == 200);
      assert(shell.shadows.at(3).getMetersX() == 2.5);
      assert(shell.shadows.at(3).getMetersY() == 6.8);
      assert(shell.shadows.at(4).getMetersX() == -1);
      assert(shell.shadows.at(4).getMetersY() == -6);
      assert(shell.shadows.at(5).getMetersX() == 5);
      assert(shell.shadows.at(5).getMetersY() == 7);

   }  // teardown

   // ShiftShadows will do nothing if the status is not FLYING
   void test_Projectile_ShiftShadows_Wrong_Status() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::LOADED;
      // exercise
      shell.shiftShadows();
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.horizontalComponent == 3);
      assert(shell.velocity.verticalComponent == 4);
      assert(shell.age == 5);
      assert(shell.status == Projectile::LOADED);
      verifyEmptyShadows(shell);

   }  // teardown

   // Move will only update the shadows if the time passed in is zero.
   // After zero time has passed, the bullet shouldn't have changed its
   // motion at all.
   void test_Projectile_Move_No_Time() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      shell.shadows.clear();
      shell.shadows.push_back(Position(1, 2));
      // exercise
      shell.move(0);
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.horizontalComponent == 3);
      assert(shell.velocity.verticalComponent == 4);
      assert(shell.age == 5);
      assert(shell.status == Projectile::FLYING);
      assert(shell.shadows.size() == 2);
      assert(shell.shadows.at(0).getMetersX() == 1);
      assert(shell.shadows.at(0).getMetersY() == 2);
      assert(shell.shadows.at(1).getMetersX() == 1);
      assert(shell.shadows.at(1).getMetersY() == 2);
   }  // teardown

   // Move will apply the force of gravity if there is no velocity.
   void test_Projectile_Move_Gravity_Only() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      shell.velocity = VelocityMock(0, 0);
      shell.position = Position(0, 0);
      shell.shadows.clear();
      shell.shadows.push_back(Position(0, 0));
      // exercise
      shell.move(0.5);
      // verify
      assert(decimalCloseEnough(shell.position.getMetersX(), 0.0));
      assert(decimalCloseEnough(shell.position.getMetersY(), -1.22588));
      assert(decimalCloseEnough(shell.velocity.horizontalComponent, 0.0));
      assert(decimalCloseEnough(shell.velocity.verticalComponent, -4.9035));
      assert(shell.age == 5.5);
      assert(shell.status == Projectile::FLYING);
      assert(shell.shadows.size() == 2);
      assert(decimalCloseEnough(shell.shadows.at(0).getMetersX(), 0.0));
      assert(decimalCloseEnough(shell.shadows.at(0).getMetersY(), -1.22588));
      assert(shell.shadows.at(1).getMetersX() == 0);
      assert(shell.shadows.at(1).getMetersY() == 0);
   }  // teardown

   // Move will apply inertia from horizontal velocity and the force of gravity.
   void test_Projectile_Move_Horizontal_Velocity() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      shell.velocity = VelocityMock(-2, 0);
      shell.position = Position(0, 0);
      shell.shadows.clear();
      shell.shadows.push_back(Position(0, 0));
      // exercise
      shell.move(0.5);
      // verify
      assert(decimalCloseEnough(shell.position.getMetersX(), -1.0));
      assert(decimalCloseEnough(shell.position.getMetersY(), -1.22588));
      assert(decimalCloseEnough(shell.velocity.horizontalComponent, -2.0));
      assert(decimalCloseEnough(shell.velocity.verticalComponent, -4.9035));
      assert(shell.age == 5.5);
      assert(shell.status == Projectile::FLYING);
      assert(shell.shadows.size() == 2);
      assert(decimalCloseEnough(shell.shadows.at(0).getMetersX(), -1.0));
      assert(decimalCloseEnough(shell.shadows.at(0).getMetersY(), -1.22588));
      assert(shell.shadows.at(1).getMetersX() == 0);
      assert(shell.shadows.at(1).getMetersY() == 0);
   }  // teardown

   // Move will apply inertia from vertical velocity and the force of gravity.
   void test_Projectile_Move_Vertical_Velocity() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      shell.velocity = VelocityMock(0, 3);
      shell.position = Position(0, 0);
      shell.shadows.clear();
      shell.shadows.push_back(Position(0, 0));
      // exercise
      shell.move(0.5);
      // verify
      assert(decimalCloseEnough(shell.position.getMetersX(), 0.0));
      assert(decimalCloseEnough(shell.position.getMetersY(), 0.27408));
      assert(decimalCloseEnough(shell.velocity.horizontalComponent, 0));
      assert(decimalCloseEnough(shell.velocity.verticalComponent, -1.90368));
      assert(shell.age == 5.5);
      assert(shell.status == Projectile::FLYING);
      assert(shell.shadows.size() == 2);
      assert(decimalCloseEnough(shell.shadows.at(0).getMetersX(), 0.0));
      assert(decimalCloseEnough(shell.shadows.at(0).getMetersY(), 0.27408));
      assert(shell.shadows.at(1).getMetersX() == 0);
      assert(shell.shadows.at(1).getMetersY() == 0);
   }  // teardown

   // Move will apply inertia from both components of velocity
   // and the force of gravity.
   void test_Projectile_Move_Normal() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      shell.velocity = VelocityMock(498.28, 317.90);
      shell.position = Position(3000, 5000);
      shell.shadows.clear();
      shell.shadows.push_back(Position(0, 0));
      // exercise
      shell.move(0.5);
      // verify
      assert(decimalCloseEnough(shell.position.getMetersX(), 3247.4254));
      assert(decimalCloseEnough(shell.position.getMetersY(), 5156.6322));
      assert(decimalCloseEnough(shell.velocity.horizontalComponent, 491.4218));
      assert(decimalCloseEnough(shell.velocity.verticalComponent, 308.6290));
      assert(shell.age == 5.5);
      assert(shell.status == Projectile::FLYING);
      assert(shell.shadows.size() == 2);
      assert(decimalCloseEnough(shell.shadows.at(0).getMetersX(), 3247.4254));
      assert(decimalCloseEnough(shell.shadows.at(0).getMetersY(), 5156.6322));
      assert(shell.shadows.at(1).getMetersX() == 0);
      assert(shell.shadows.at(1).getMetersY() == 0);
   }  // teardown

   // Move will do nothing if the status is not FLYING
   void test_Projectile_Move_Wrong_Status() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::LOADED;
      // exercise
      shell.move(0.5);
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.horizontalComponent == 3);
      assert(shell.velocity.verticalComponent == 4);
      assert(shell.age == 5);
      assert(shell.status == Projectile::LOADED);
      verifyEmptyShadows(shell);
   }  // teardown

   // IsLoaded returns true if the status is LOADED.
   void test_Projectile_IsLoaded_True() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::LOADED;
      // exercise
      bool b = shell.isLoaded();
      // verify
      assert(b);
   }  // teardown

   // IsLoaded returns false in all other cases.
   void test_Projectile_IsLoaded_False() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      // exercise
      bool b = shell.isLoaded();
      // verify
      assert(!b);
   }  // teardown

   // IsFlying returns true if the status is FLYING.
   void test_Projectile_IsFlying_True() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      // exercise
      bool b = shell.isFlying();
      // verify
      assert(b);
   }  // teardown

   // IsFlying returns false in all other cases.
   void test_Projectile_IsFlying_False() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::ON_TARGET;
      // exercise
      bool b = shell.isFlying();
      // verify
      assert(!b);
   }  // teardown

   // IsLanded returns true if status is ON_TARGET.
   void test_Projectile_IsLanded_On_Target() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::ON_TARGET;
      // exercise
      bool b = shell.isLanded();
      // verify
      assert(b);
   }  // teardown

   // IsLanded returns true if status is OFF_TARGET.
   void test_Projectile_IsLanded_Off_Target() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::OFF_TARGET;
      // exercise
      bool b = shell.isLanded();
      // verify
      assert(b);
   }  // teardown

   // IsLanded returns false in all other cases.
   void test_Projectile_IsLanded_False() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::LOADED;
      // exercise
      bool b = shell.isLanded();
      // verify
      assert(!b);
   }  // teardown

   // IsOnTarget returns true if status is ON_TARGET.
   void test_Projectile_IsOnTarget_True() const
   {
      Projectile shell = defaultSetup();
      shell.status = Projectile::ON_TARGET;
      // exercise
      bool b = shell.isOnTarget();
      // verify
      assert(b);
   }  // teardown

   // IsOnTarget returns false in all other cases.
   void test_Projectile_IsOnTarget_False() const
   {
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      // exercise
      bool b = shell.isOnTarget();
      // verify
      assert(!b);
   }  // teardown
};