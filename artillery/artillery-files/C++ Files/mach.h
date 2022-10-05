/*********************************************************************************************
 * Header File:
 *    Mach: Determines the mach at a given altitude in the artillery
 *    simulation. Inherits from LookUp base class
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    Contains and defines the mach key and value table. It contains one
 *    method that is a wrapper for the methods inherited from and defined in
 *    the LookUp base class
 ********************************************************************************************/

#pragma once
#include "lookUp.h"                 // for the inherited methods
#include "tableItem.h"              // for the table item struct

/*********************************************************************************************
 * MACH
 * The mach class
 *********************************************************************************************/
class Mach : public LookUp
{
public:
   // Make the test class a friend
   friend class TestMach;
   
   // Constructor
   Mach();
   
   // Getter
   double getMach(double altitude) const;
   
private:
   tableItem table [16];         // The table array
};
