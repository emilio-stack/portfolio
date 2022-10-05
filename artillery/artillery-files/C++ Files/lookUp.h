/***************************************************************************************
 * Header File:
 *    Look Up : The base class for the gravity, drag, mach, and air density
 *    classes. Does not contain a table of keys and values, just the necessary
 *    methods to search a table of keys and values
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    Contains methods to search a referanced table for a value given a key
 *    and interpolate for the value if the given key is  not present in the table.
 ****************************************************************************************/

#pragma once

#include "tableItem.h"        // For the table item struct
#include "key1Key2.h"         // For the key1key2 struct
#include <cmath>              // For the abs() function

/******************************************************************************************
 * LOOK UP
 * The look up class
 ******************************************************************************************/
class LookUp
{
public:
   // Constructors
   LookUp() {}

protected:
   // Getters
   virtual double getValue(double input, const tableItem *table, int max) const;
   
   // All the necessary methods to look up a value in a table
   key1key2 searchTable(double keyNotFound, const tableItem *table) const;
   virtual double interpolate(double x1, double y1, double x2, double y2, double toFind) const;
   bool closeEnough(double computedValue, double hardcodeValue) const;
};
