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
 *********************************************************************************************/

#include "airDensity.h"     // For the air density class def

/*********************************************************************************************
 * AIR DENSITY
 * Just the default constructor to initialize the air density table
 *********************************************************************************************/
AirDensity :: AirDensity()
{
   table[0]  = tableItem(0.0,      1.2250000);
   table[1]  = tableItem(1000.0,   1.1120000);
   table[2]  = tableItem(2000.0,   1.0070000);
   table[3]  = tableItem(3000.0,   0.9093000);
   table[4]  = tableItem(4000.0,   0.8194000);
   table[5]  = tableItem(5000.0,   0.7364000);
   table[6]  = tableItem(6000.0,   0.6601000);
   table[7]  = tableItem(7000.0,   0.5900000);
   table[8]  = tableItem(8000.0,   0.5258000);
   table[9]  = tableItem(9000.0,   0.4671000);
   table[10] = tableItem(10000.0,  0.4135000);
   table[11] = tableItem(15000.0,  0.1948000);
   table[12] = tableItem(20000.0,  0.0889100);
   table[13] = tableItem(25000.0,  0.0400800);
   table[14] = tableItem(30000.0,  0.0184100);
   table[15] = tableItem(40000.0,  0.0039960);
   table[16] = tableItem(50000.0,  0.0010270);
   table[17] = tableItem(60000.0,  0.0003097);
   table[18] = tableItem(70000.0,  0.0000828);
   table[19] = tableItem(80000.0,  0.0000185);
}

/*********************************************************************************************
 * GET DENSITY
 * Just a wrapper for the getValue method inherited from the LookUp base class.
 * getDensity will pass the table reference and the array max to the get value
 * method.
 *********************************************************************************************/
double AirDensity :: getDensity(double altitude) const
{
   
   return getValue(altitude, table, AIRDENSITY_ARRAY_MAX);
}
