/****************************************************************************************
 * Header File:
 *    Test Gravity Look Up: The test suite for the gravity look up class.
 * Author:
 *    Emilio Regino
 * Summary:
 *    Unit tests to exercise the gravity look up class.
 ****************************************************************************************/

#pragma once
#include "gravity.h"
#include "key1Key2.h"
#include <iostream>
using namespace std;

class TestGravity
{
public:
   void run()
   {
      cout << "Gravity: ";
      test_getGravityZeroElevation();
      test_getGravity5000Elevation();
      test_getGravityElevationNotContained();
      test_searchTable();
      test_interpolate();
      cout << "Passed" << endl;
   }
private:
   //
   // Gravity Look Up
   //
   
   // Test the getGravity method for the 0 elevation
   void test_getGravityZeroElevation()
   {
      // Setup
      Gravity grav;
      double elevation = 0.0;
      double value = -1.0;
      
      // Exercise
      value = grav.getGravity(elevation);
      
      // Verify
      assert(value == 9.807);
   }  // Teardown
   
   // Test the getGravity method for 5000 elevation
   void test_getGravity5000Elevation()
   {
      // Setup
      Gravity grav;
      double elevation = 5000.0;
      double value = -1.0;
      
      // Exercise
      value = grav.getGravity(elevation);
      
      // Verify
      assert(value == 9.791);
   }  // Teardown
   
   // Test the getGravity method for an elevation not in the table
   void test_getGravityElevationNotContained()
   {
      // Setup
      Gravity grav;
      double elevation = 3050.0;
      double value = -1.0;
      
      // Exercise
      value = grav.getGravity(elevation);
      
      // Verify
      assert(grav.closeEnough(value, 9.79685));
   }  // Teardown
   
   // Test the search table method with the gravity table
   void test_searchTable()
   {
      // Setup
      Gravity grav;
      double elevation = 3050.0;
      key1key2 value;
      value.key1 = -1.0;
      value.key2 = -1.0;
      
      // Exercise
      value = grav.searchTable(elevation, grav.table);
      
      // Verify
      assert(value.key1 == 3000.0);
      assert(value.key2 == 4000.0);
   }  // Teardown
   
   // Test the interpolate method with the gravity table
   void test_interpolate()
   {
      // Setup
      Gravity grav;
      double x1 = 3000.0;
      double y1 = 9.797;
      double x2 = 4000.0;
      double y2 = 9.794;
      double xToFind = 3050.0;
      double value = -1.0;
      
      // Exercise
      value = grav.interpolate(x1, y1, x2, y2, xToFind);
      
      // Verify
      assert(grav.closeEnough(value, 9.79685));
   }  // Teardown
   
};
