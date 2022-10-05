/***********************************************************************
 * Header File:
 *    Test Air Density : Test the class air density
 * Author:
 *    Emilio Regino
 * Summary:
 *    All the unit tests for air density
 ************************************************************************/

#pragma once

#include "airDensity.h"       
#include "key1key2.h"
#include <cassert>
#include <iostream>
using namespace std;

class TestAirDensity
{
public:
   void run()
   {
      cout << "Air Density: ";
      test_getDensityZeroElevation();
      test_getDensity5000Elevation();
      test_getDensityNotContained();
      test_searchTable();
      test_interpolate();
      cout << "Passed" << endl;
   }
private:
   //
   // Air Density Look Up
   //
   
   // Test the getDensity method for elevation 0 
   void test_getDensityZeroElevation()
   {
      // Setup
      AirDensity air;
      double elevation = 0.0;
      double value = -1.0;
      
      // Exercise
      value = air.getDensity(elevation);
      
      // Verify
      assert(value == 1.2250000);
   }  // Teardown
   
   // Test the getDenstiy method for 5000 elevation
   void test_getDensity5000Elevation()
   {
      // Setup
      AirDensity air;
      double elevation = 5000.0;
      double value = -1.0;
      
      // Exercise
      value = air.getDensity(elevation);
      
      // Verify
      assert(value == 0.7364000);
   }  // Teardown
   
   // Test the get density method for a value not in the table
   void test_getDensityNotContained()
   {
      // Setup
      AirDensity air;
      double elevation = 3050.0;
      double value = -1.0;
      
      // Exercise
      value = air.getDensity(elevation);
      
      // Verify
      assert(air.closeEnough(value, 0.90480));
   }  // Teardown
   
   // Test the search table method with the air density table
   void test_searchTable()
   {
      // Setup
      AirDensity air;
      double elevation = 3050.0;
      key1key2 value;
      value.key1 = -1.0;
      value.key2 = -1.0;
      
      // Exercise
      value = air.searchTable(elevation, air.table);
      
      // Verify
      assert(value.key1 == 3000.0);
      assert(value.key2 == 4000.0);
   }  // Teardown
   
   // Test the interpolate method with the air density table
   void test_interpolate()
   {
      // Setup
      AirDensity air;
      double x1 = 3000.0;
      double y1 = 0.9093000;
      double x2 = 4000.0;
      double y2 = 0.8194000;
      double xToFind = 3050.0;
      double value = -1.0;
      
      // Exercise
      value = air.interpolate(x1, y1, x2, y2, xToFind);
      
      // Verify
      assert(air.closeEnough(value, 0.90480));
   }  // Teardown
   
};
