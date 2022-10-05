/*********************************************************************************************
 * Header File:
 *    Air Density: Determines the air density at a given altitude in the artillery
 *    simulation. Inherits from LookUp base class
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    Contains and defines the air density key and value table. It contains one
 *    method that is a wrapper for the methods inherited from and defined in
 *    the LookUp base class
 ********************************************************************************************/
#pragma once
#include "lookUp.h"           // For the inherited methods to search the air density table
#include "tableItem.h"        // For the table item struct

const int AIRDENSITY_ARRAY_MAX = 20;      // The size of the table array

/*********************************************************************************************
 * AIR DENSITY
 * The air density class
 *********************************************************************************************/
class AirDensity : public LookUp
{
public:
   // Test class is a friend
   friend class TestAirDensity;
   
   // Constructor
   AirDensity();

   // Getters
   virtual double getDensity(double altitude) const;
   
protected:
   tableItem table [AIRDENSITY_ARRAY_MAX];         // The table array
};
