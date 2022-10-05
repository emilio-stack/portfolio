/***********************************************************************
 * Source File:
 *    Test Angle: A class to test the Angle class
 * Author:
 *    Emilio Regino
 * Summary:
 *    Contains the unit tests for the angle class
 ************************************************************************/

#include "angle.h"
#include <cassert>
#include <iostream>
using namespace std;

class TestAngle
{
public:
   
   // The default constructor
   TestAngle(){};
   
   // A method to run all the unit tests
   void run()
   {
      cout << "Angle: ";
      test_setDegrees();
      test_setRadians();
      test_addDegrees();
      test_addRadians();
      test_getDegrees();
      test_getRadian_positive();
      test_getRadian_negative();

      test_verifyNewAngle_IsValid();
      test_verifyNewAngle_IsInvalid();
      test_convertToValid_max();
      test_convertToValid_min();
      test_convertToValid_181();
      test_convertToValid_181Neg();
      test_convertToValid_195();
      test_convertToValid_195Neg();

      test_degreesFromRadians();
      test_radiansFromDegrees();
      test_degreesFromXYZero();
      test_degreesFromXY();

      cout << "Passed" << endl;
   }
   
private:
   // Test the set degrees method
   void test_setDegrees()
   {
      // Setup
      Angle angle;
      
      // Exercise
      angle.setDegrees(90.0);
      
      // Verify
      assert(angle.angle == 90.0);
   }  // Teardown
   
   // Test the set radians method
   void test_setRadians()
   {
      // Setup
      Angle angle;
      
      // Exercise
      angle.setRadians(PI);
      
      // Verify
      assert(angle.angle == 180.0);
   }  // Teardown
   
   // Test the add angle method
   void test_addDegrees()
   {
      // Setup
      Angle angle;
      angle.angle = 0.0;
      
      // Exercise
      angle.addDegrees(90.0);
      
      // Verify
      assert(angle.angle == 90.0);
   }  // Teardown
   
   // Test the add radians method
   void test_addRadians()
   {
      // Setup
      Angle angle;
      angle.angle = 0.0;
      
      // Exercise
      angle.addRadians(PI);
      
      // Verify
      assert(angle.angle == 180.0);
   }  // Teardown
   
   // Test the get degrees method
   void test_getDegrees()
   {
      // Setup
      Angle angle;
      angle.angle = 90.0;
      
      // Exercise
      double value = angle.getDegrees();
      
      // Verify
      assert(value == 90.0);
   }  // Teardown...
   
   // Test the get radians method with a positive angle
   void test_getRadian_positive()
   {
      // Setup
      Angle angle;
      angle.angle = 90.0;
      
      // Exercise
      double value = angle.getRadians();
      
      // Verify
      assert(value == (PI / 2));
   }  // Teardown...
   
   // Test the get radians method with a negative angle
   void test_getRadian_negative()
   {
      // Setup
      Angle angle;
      angle.angle = -90.0;
      
      // Exercise
      double value = angle.getRadians();
      
      // Verify
      assert(value == -(PI / 2));
   }  // Teardown...
   
   // Test that a valid new angle is valid
   void test_verifyNewAngle_IsValid()
   {
      // Setup
      Angle angle;
      
      // Exercise
      bool value = angle.verifyNewAngle(50.0);
      
      // Verify
      assert(value == true);
   }  // Teardown
   
   // Test that a invalid new angle is invalid
   void test_verifyNewAngle_IsInvalid()
   {
      // Setup
      Angle angle;
      
      // Exercise
      bool value = angle.verifyNewAngle(181.0);
      
      // Verify
      assert(value == false);
   }  // Teardown
   
   // test the convert to valid with a value over the max
   void test_convertToValid_max()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.convertToValid(450.0);
      
      // Verify
      assert(value == 90.0);
   }  // Teardown
   
   // test the convert to valid with a value under the min
   void test_convertToValid_min()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.convertToValid(-450.0);
      
      // Verify
      assert(value == -90.0);
   }  // Teardown
   
   // Testing the positive boundry
   void test_convertToValid_181()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.convertToValid(181);
      
      // Verify
      assert(value == -179.0);
   }  // Teardown
   
   // Testing the negative boundary
   void test_convertToValid_181Neg()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.convertToValid(-181);
      
      // Verify
      assert(value == 179.0);
   }  // Teardown
   
   // Testing a common case
   void test_convertToValid_195()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.convertToValid(195);
      
      // Verify
      assert(value == -165);
   }  // Teardown
   
   // Testing a negative common case
   void test_convertToValid_195Neg()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.convertToValid(-195);
      
      // Verify
      assert(value == 165);
   }  // Teardown
   
   // Test the convert to degrees method
   void test_degreesFromRadians()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.degreesFromRadians(PI);
      
      // Verify
      assert(value == 180.0);
   }  // Teardown
   
   // Test the convert to radian method
   void test_radiansFromDegrees()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.radiansFromDegrees(180.0);
      
      // Verify
      assert(value == PI);
   }  // Teardown
   
   // Test the convert from XY method with zeros
   void test_degreesFromXYZero()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.degreesFromXY(0.0, 0.0);
      
      // Verify
      assert(value == 0.0);
   }  // Teardown
   
   // Test the convert from XY method with values
   void test_degreesFromXY()
   {
      // Setup
      Angle angle;
      
      // Exercise
      double value = angle.degreesFromXY(5.0, 5.0);
      
      // Verify
      assert(value == 45.0);
   }  // Teardown
};
