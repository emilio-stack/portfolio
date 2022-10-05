/*********************************************************************************************
 * Header File:
 *    Drag: Determines the drag at a given mach in the artillery
 *    simulation. Inherits from LookUp base class
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    Contains and defines the drag key and value table. It contains one
 *    method that is a wrapper for the methods inherited from and defined in
 *    the LookUp base class
 ********************************************************************************************/

#pragma once
#include "lookUp.h"              // for the inherited methods
#include "tableItem.h"           // for the table item struct
const int DRAG_ARRAY_SIZE = 17;  // the size of the table array

/*********************************************************************************************
 * DRAG
 * The drag class
 *********************************************************************************************/
class Drag : public LookUp
{
public:
   // Test class is a friend
   friend class TestDrag;
   
   // Constructor
   Drag();
   
   // Getters
   virtual double getDrag(double mach) const;
   
private:
   tableItem table [DRAG_ARRAY_SIZE];         // The table array
};

