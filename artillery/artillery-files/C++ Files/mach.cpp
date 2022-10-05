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

#include "mach.h"       // For the mach class def

/*********************************************************************************************
 * MACH
 * Just the default constructor for the mach class. It initializes the mach table array
 *********************************************************************************************/
Mach :: Mach()
{
   table[0] = tableItem(0.0,      340.0);
   table[1] = tableItem(1000.0,   336.0);
   table[2] = tableItem(2000.0,   332.0);
   table[3] = tableItem(3000.0,   328.0);
   table[4] = tableItem(4000.0,   324.0);
   table[5] = tableItem(5000.0,   320.0);
   table[6] = tableItem(6000.0,   316.0);
   table[7] = tableItem(7000.0,   312.0);
   table[8] = tableItem(8000.0,   308.0);
   table[9] = tableItem(9000.0,   303.0);
   table[10] = tableItem(10000.0,  299.0);
   table[11] = tableItem(15000.0,  295.0);
   table[12] = tableItem(20000.0,  295.0);
   table[13] = tableItem(25000.0,  295.0);
   table[14] = tableItem(30000.0,  305.0);
   table[15] = tableItem(40000.0,  324.0);
}

/*********************************************************************************************
 * GET MACH
 * Just a wrapper for the getValue method inherited from the LookUp base class.
 * getMach will pass the table reference and the array max to the get value
 * method.
 *********************************************************************************************/
double Mach :: getMach(double altitude) const
{
   return getValue(altitude, table, 16);
}
