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
 *********************************************************************************************/

#include "drag.h"       // for the drag class def

/*********************************************************************************************
 * DRAG
 * Just the default constructor for the drag class. It initializes the drag table array
 *********************************************************************************************/
Drag :: Drag()
{
   table[0]  = tableItem(0.000,   0.0000);
   table[1]  = tableItem(0.300,   0.1629);
   table[2]  = tableItem(0.500,   0.1659);
   table[3]  = tableItem(0.700,   0.2031);
   table[4]  = tableItem(0.890,   0.2597);
   table[5]  = tableItem(0.920,   0.3010);
   table[6]  = tableItem(0.960,   0.3287);
   table[7]  = tableItem(0.980,   0.4002);
   table[8]  = tableItem(1.000,   0.4258);
   table[9]  = tableItem(1.020,   0.4335);
   table[10] = tableItem(1.060,   0.4483);
   table[11] = tableItem(1.240,   0.4064);
   table[12] = tableItem(1.530,   0.3663);
   table[13] = tableItem(1.990,   0.2897);
   table[14] = tableItem(2.870,   0.2297);
   table[15] = tableItem(2.890,   0.2306);
   table[16] = tableItem(5.000,   0.2656);
}

/*********************************************************************************************
 * GET DRAG
 * Just a wrapper for the getValue method inherited from the LookUp base class.
 * getDrag will pass the table reference and the array max to the get value
 * method.
 *********************************************************************************************/
double Drag :: getDrag(double mach) const
{
   return getValue(mach, table, DRAG_ARRAY_SIZE);
}
