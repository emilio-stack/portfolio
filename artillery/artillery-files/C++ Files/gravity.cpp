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

#include "gravity.h"       // For the gravity class def

/*********************************************************************************************
 * GRAVITY
 * Just the default constructor for the gravity class. It initializes the gravity table array
 *********************************************************************************************/
Gravity :: Gravity()
{
   table[0] = tableItem(0.0,       9.807);
   table[1] = tableItem(1000.0,    9.804);
   table[2] = tableItem(2000.0,    9.801);
   table[3] = tableItem(3000.0,    9.797);
   table[4] = tableItem(4000.0,    9.794);
   table[5] = tableItem(5000.0,    9.791);
   table[6] = tableItem(6000.0,    9.788);
   table[7] = tableItem(7000.0,    9.785);
   table[8] = tableItem(8000.0,    9.782);
   table[9] = tableItem(9000.0,    9.779);
   table[10] = tableItem(10000.0,  9.776);
   table[11] = tableItem(15000.0,  9.761);
   table[12] = tableItem(20000.0,  9.745);
   table[13] = tableItem(25000.0,  9.730);
}

/*********************************************************************************************
 * GET GRAVITY
 * Just a wrapper for the getValue method inherited from the LookUp base class.
 * getGravity will pass the table reference and the array max to the get value
 * method.
 *********************************************************************************************/
double Gravity :: getGravity(double altitude) const
{
   return getValue(altitude, table, GRAVITY_ARRAY_SIZE);
}


