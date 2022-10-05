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

#include "lookUp.h"

/**********************************************************************
 * GET VALUE:
 *    A method to get a value from a table given a key.
 * Arguments:
 *    Key: the key to search in the table
 *    Table: the table to search passed BY REFERENCE
 * Returns:
 *    Value: the value found or interpolated
 ***********************************************************************/
double LookUp :: getValue(double input, const tableItem *table, int max) const
{
   // Iterate through the table and check if the given key is present
   for (int i=0; i < max; i++)
   {
      tableItem item = table[i];
      if (item.key == input)
         return item.value;
   }
   
   // If not found then search the table for the key just before
   // and the key just after where the given key would be in the table
   key1key2 keys = searchTable(input, table);
   double x1 = keys.key1;              // The key just before
   double y1 = 0.0;                    // A place holder for the value of the key just before
   double x2 = keys.key2;              // The key just after
   double y2 = 0.0;                    // A place holder for the value of the key just before
   
   // Now iterate through the table to get the values
   // of both the key just before and key just after
   for (int i=0; i < max; i++)
   {
      tableItem item = table[i];
      if (item.key == x1)
         y1 = table[i].value;          // Update the place holder value of the key just before
      else if (item.key == x2)
         y2 = table[i].value;          // Update the place holder value of the key just after
   }
   
   // Now using the two pairs of key and value contained in the table
   // and the given key not contained in the table, interpolate for
   // the value of the key not contained in the table
   double value = interpolate(x1, y1, x2, y2, input);
   
   return value;
}

/**********************************************************************
 * SEARCH TABLE:
 *    A method to search a table for the key just under and the
 *    key just over a key not contained in the table.
 * Arguments:
 *    KeyNotFound: the key not contained in the table
 *    Table: the table to search passed BY REFERENCE
 ***********************************************************************/
key1key2 LookUp :: searchTable(double keyNotFound, const tableItem *table) const
{
   // assign the high and low values
   double high = table[0].key;
   double low = table[0].key;
   
   // Loop through the array
   int i = 0;
   bool searching = true;
   while (i < 14 && searching)
   {
      // If current key is less than not contained key
      if (table[i].key < keyNotFound)
      {
         // check if is greater than the current low
         if (table[i].key > low)
         {
            // If so assign the new low
            low = table[i].key;
         }
      }
      else
      {
         // Our previous iterator was the highest value below the one we want.
         // The current iterator is the lowest value above the one we want.
         // That means we're done searching.
         high = table[i].key;
         searching = false;
      }
      i++;
   }
   
   // Store the keys in a key1key2 struct and return
   key1key2 keys;
   keys.key1 = low;
   keys.key2 = high;
   return keys;
}

/**********************************************************************
 * INTERPOLATE:
 *    A method to interpolate the value of a key not contained
 *    in the table
 * Arguments:
 *    key1: key of the first point on the table
 *    value1: value of the first point on the table
 *    key2: key of the second point on the table
 *    value2: value of the second point on the table
 *    KeytoFind: the key not contained in the table
 ***********************************************************************/
double LookUp :: interpolate(double x1, double y1, double x2, double y2, double toFind) const
{
   if (y2 == y1)
   {
      // They gave us one point twice, or a constant function.
      return y2;
   }
   else
   {
      // Use the interpolation equation
      return (y2 - y1) * (toFind - x1) / (x2 - x1) + y1;
   }
}

/**********************************************************************
 * CLOSE ENOUGH:
 *    A method to tell if a computed value is close enough to
 *    the precision we want.
 * Arguments:
 *    computedValue: The value calculated by the program
 *    hardcodeValue: The value with acceptable precision
 ***********************************************************************/
bool LookUp :: closeEnough(double computedValue, double hardcodeValue) const
{
   return abs(computedValue - hardcodeValue) < 0.0005;
}
