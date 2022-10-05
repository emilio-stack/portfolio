/***********************************************************************
 * Header File:
 *    Test Mach : Test the class mach
 * Author:
 *    Emilio Regino
 * Summary:
 *    All the unit tests for mach
 ************************************************************************/

#pragma once

#include "mach.h"
#include "key1Key2.h"
#include <iostream>
using namespace std;

class TestMach
{
public:
   void run()
   {
      cout << "Mach: ";
      test_getMachZeroAltitude();
      test_getMach5000Altitude();
      test_getMachNotContained();
      test_searchTable();
      test_interpolate();
      cout << "Passed" << endl;
   }
private:
   //
   // Gravity Look Up
   //
   
   // Test the getMach method for 0 altitude
   void test_getMachZeroAltitude()
   {
      // Setup
      Mach mach;
      double altitude = 0.0;
      double value = -1.0;
      
      // Exercise
      value = mach.getMach(altitude);
      
      // Verify
      assert(value == 340.0);
   }  // Teardown
   
   // Test the getMach method for 5000.0 altitude
   void test_getMach5000Altitude()
   {
      // Setup
      Mach mach;
      double altitude = 5000.0;
      double value = -1.0;
      
      // Exercise
      value = mach.getMach(altitude);
      
      // Verify
      assert(value == 320.0);
   }  // Teardown
   
   // Test the getMach method for a value not in the table
   void test_getMachNotContained()
   {
      // Setup
      Mach mach;
      double altitude = 3050.0;
      double value = -1.0;
      
      // Exercise
      value = mach.getMach(altitude);
      
      // Verify
      assert(mach.closeEnough(value, 327.8));
   }  // Teardown
   
   // Test the search table method with the mach table
   void test_searchTable()
   {
      // Setup
      Mach mach;
      double elevation = 3050.0;
      key1key2 value;
      value.key1 = -1.0;
      value.key2 = -1.0;
      
      // Exercise
      value = mach.searchTable(elevation, mach.table);
      
      // Verify
      assert(value.key1 == 3000.0);
      assert(value.key2 == 4000.0);
   }  // Teardown
   
   // Test the interpolate method with the mach table
   void test_interpolate()
   {
      // Setup
      Mach mach;
      double x1 = 3000.0;
      double y1 = 328.0;
      double x2 = 4000.0;
      double y2 = 324.0;
      double xToFind = 3050.0;
      double value = -1.0;
      
      // Exercise
      value = mach.interpolate(x1, y1, x2, y2, xToFind);
      
      // Verify
      assert(mach.closeEnough(value, 327.8));
   }  // Teardown
   
};

