/***********************************************************************
 * Header File:
 *    Test Drag : Test the class drag
 * Author:
 *    Emilio Regino
 * Summary:
 *    All the unit tests for drag
 ************************************************************************/

#pragma once

#include "drag.h"
#include "key1key2.h"
#include <cassert>
#include <iostream>
using namespace std;

class TestDrag
{
public:
   void run()
   {
      cout << "Drag: ";
      test_getDragZeroSpeed();
      test_getDragPoint15();
      test_getDragPoint3();
      test_getDragPoint89();
      test_getDragNotContained();
      test_searchTable();
      test_interpolate();
      cout << "Passed" << endl;
   }
private:
   //
   // Gravity Look Up
   //
   
   // Test the getDrag method for mach 0
   void test_getDragZeroSpeed()
   {
      // Setup
      Drag drag;
      double mach = 0.0;
      double value = -1.0;
      
      // Exercise
      value = drag.getDrag(mach);
      
      // Verify
      assert(value == 0.0);
   }  // Teardown
   
   // Test the getDrag method for mach .15
   void test_getDragPoint15()
   {
      // Setup
      Drag drag;
      double mach = 0.15;
      double value = -1.0;
      
      // Exercise
      value = drag.getDrag(mach);
      
      // Verify
      assert(value == 0.08145);
   }  // Teardown
   
   // Test the getDrag method for 0.300 mach
   void test_getDragPoint3()
   {
      // Setup
      Drag drag;
      double mach = 0.300;
      double value = -1.0;
      
      // Exercise
      value = drag.getDrag(mach);
      
      // Verify
      assert(value == 0.1629);
   }  // Teardown
   
   // Test the getDrag method for 0.890 mach
   void test_getDragPoint89()
   {
      // Setup
      Drag drag;
      double mach = 0.890;
      double value = -1.0;
      
      // Exercise
      value = drag.getDrag(mach);
      
      // Verify
      assert(value == 0.2597);
   }  // Teardown
   
   // Test the getDrag method for a value not in the table
   void test_getDragNotContained()
   {
      // Setup
      Drag drag;
      double mach = 0.940;
      double value = -1.0;
      
      // Exercise
      value = drag.getDrag(mach);
      
      // Verify
      assert(drag.closeEnough(value, 0.31484));
   }  // Teardown
   
   // Test the search table method with the drag table
   void test_searchTable()
   {
      // Setup
      Drag drag;
      double dragVal = 0.940;
      key1key2 value;
      value.key1 = -1.0;
      value.key2 = -1.0;
      
      // Exercise
      value = drag.searchTable(dragVal, drag.table);
      
      // Verify
      assert(value.key1 == 0.920);
      assert(value.key2 == 0.960);
   }  // Teardown
   
   // Test the interpolate method with the drag table
   void test_interpolate()
   {
      // Setup
      Drag drag;
      double x1 = 0.920;
      double y1 = 0.3010;
      double x2 = 0.960;
      double y2 = 0.3287;
      double xToFind = 0.940;
      double value = -1.0;
      
      // Exercise
      value = drag.interpolate(x1,  y1, x2, y2, xToFind);
      
      // Verify
      assert(drag.closeEnough(value, 0.31484));
   }  // Teardown
   
};
