/*********************************************************************************************
 * Header File:
 *    Gravity: Determines the gravity at a given altitude in the artillery
 *    simulation. Inherits from LookUp base class
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    Contains and defines the gravity key and value table. It contains one
 *    method that is a wrapper for the methods inherited from and defined in
 *    the LookUp base class
 ********************************************************************************************/

#pragma once
#include "lookUp.h"                 // for the inherited methods
#include "tableItem.h"              // for the table item struct
const int GRAVITY_ARRAY_SIZE = 14;  // the size of the gravity table

/*********************************************************************************************
 * GRAVITY
 * The gravity class
 *********************************************************************************************/
class Gravity : public LookUp
{
public:
   // Make test class a friend for testing
   friend class TestGravity;
   
   // Constructor to initialize the table
   Gravity();

   // Getters
   virtual double getGravity(double altitude) const;
   
private:
   tableItem table[GRAVITY_ARRAY_SIZE];         // The table array
};
