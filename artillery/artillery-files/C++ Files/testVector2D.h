/***********************************************************************
 * Source File:
 *    Test Vecto2Dr: A class to test the Vector2D class
 * Author:
 *    Emilio Regino
 * Summary:
 *    Contains the unit tests for the vector2D class
 ************************************************************************/

#include "vector2D.h"
#include <iostream>
using namespace std;

class TestVector
{
public:
   // A method to run the tests
   void run()
   {
      cout << "Vector: ";
      test_getHorComponent();
      test_getVertComponent();
      test_getMagnitudeZero();
      test_getMagnitude();
      test_getAngleZero();
      test_getAngle();
      test_setHorizontalComponent();
      test_setVerticalComponent();
      test_addVector();
      cout << "Passed" << endl;
   }
   
private:
   //
   // Vector
   //
   
   // Test the get horizontal component method
   void test_getHorComponent()
   {
      // Setup
      Vector2D vector;
      vector.horizontalComponent = 10.0;
      
      // Exercise
      double value = vector.getHorComponent();
      
      // Verify
      assert(value == 10.0);
   }  // Teardown
   
   // Test the get vertical component method
   void test_getVertComponent()
   {
      // Setup
      Vector2D vector;
      vector.verticalComponent = 10.0;
      
      // Exercise
      double value = vector.getVertComponent();
      
      // Verify
      assert(value == 10.0);
   }  // Teardown
   
   // Test the get magnitude component method with 0 values
   void test_getMagnitudeZero()
   {
      // Setup
      Vector2D vector;
      vector.horizontalComponent = 0.0;
      vector.verticalComponent = 0.0;

      // Exercise
      double value = vector.getMagnitude();

      // Verify
      assert(value == 0.0);
   }  // Teardown
   
   // Test the get magnitude component method
   void test_getMagnitude()
   {
      // Setup
      Vector2D vector;
      vector.horizontalComponent = 5.0;
      vector.verticalComponent = 5.0;

      // Exercise
      double value = vector.getMagnitude();

      // Verify
      assert(value == 7.0710678118654755);
   }  // Teardown
   
   // Test the get angle method with no values
   void test_getAngleZero()
   {
      // Setup
      Vector2D vector;

      // Exercise
      Angle value = vector.getAngle();

      // Verify
      assert(value.getDegrees() == 0.0);
   }  // Teardown
   
   // Test the get angle method with values
   void test_getAngle()
   {
      // Setup
      Vector2D vector;
      vector.horizontalComponent = 5.0;
      vector.verticalComponent = 5.0;

      // Exercise
      Angle value = vector.getAngle();

      // Verify
      assert(value.getDegrees() == 45.0);
   }  // Teardown
   
   // Test the set horizontal component method
   void test_setHorizontalComponent()
   {
      // Setup
      Vector2D vector;
      vector.setVertical(0.0);
      
      // Exercise
      vector.setHorizontal(10.0);
      
      
      // Verify
      assert(vector.horizontalComponent == 10.0);
      assert(vector.verticalComponent == 0.0);
   }  // Teardowns
   
   // Test the set vertical component method
   void test_setVerticalComponent()
   {
      // Setup
      Vector2D vector;
      vector.setHorizontal(0.0);
      
      // Exercise
      vector.setVertical(10.0);
      
      
      // Verify
      assert(vector.horizontalComponent == 0.0);
      assert(vector.verticalComponent == 10.0);
   }  // Teardowns
   
   // Test the add vector method
   void test_addVector()
   {
      // Setup
      Vector2D vector;
      vector.setHorizontal(0.0);
      vector.setVertical(0.0);
      Vector2D newVector;
      newVector.setHorizontal(10.0);
      newVector.setVertical(10.0);
      
      // Exercise
      vector.addVector(newVector);
      
      // Verify
      assert(vector.horizontalComponent == 10.0);
      assert(vector.verticalComponent == 10.0);
   }  // Teardowns
};
