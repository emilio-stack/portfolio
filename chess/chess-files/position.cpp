/***********************************************************************
 * Source File:
 *    position.cpp
 * Author:
 *    Emilio Regino, Bradley Payne & Penelope Sanchez
 * Summary:
 *    A class to handle all positions functions in the game
 ************************************************************************/

#include "position.h"
#include <iostream>
using namespace std;

/***********************************************************************
 * SET ROW
 * A method to set the row of the position. This method only
 * affects the row of a position and has no effect on the column.
 ************************************************************************/
void Position :: setRow(int r)
{
   if (r >= 0 && r < 8 && isValid())
   {
      char c = getCol();
      location = (char) r * 8 + c;
   }
   else
      location = -1;
}

/***********************************************************************
 * SET COLUMN
 * A method to set the column of the position. This method only
 * affects the column of a position and has no effect on the row.
 ************************************************************************/
void Position :: setCol(int c)
{
   if (c >= 0 && c < 8 && isValid())
   {
      char r = getRow();
      location = r * 8 + (char)c;
   }
   else
      location = -1;
}

/***********************************************************************
 * INEQUALITY OPERATOR
 * A method to support the inequality operator for the position
 * class.
 ************************************************************************/
bool Position::operator != (const Position & rhs) const
{
   if (isInvalid())
      return rhs.isValid();
   else
      return rhs.location != location;
}

/***********************************************************************
 * ASSIGNMENT OPERATOR
 * A method to support the assignment operator for the position
 * class.
 ************************************************************************/
const Position & Position::operator = (const Position & rhs)
{
   location = rhs.location;
   
   
   return *this;
}

/***********************************************************************
 * ASSIGNMENT OPERATOR
 * A method to support the assignment operator for the position
 * class.
 ************************************************************************/
const Position & Position::operator = (const char * rhs)
{
   if (rhs == NULL)
      location = -1;
   
   else if (rhs[0] < 'a' || rhs[0] > 'h' ||
            rhs[1] < '1' || rhs[1] > '8')
      location = -1;
   else
      set(rhs[1] - '1', rhs[0] - 'a');
   
   return *this;
}

/***********************************************************************
 * INSERTION OPERATOR
 * A method to support the insertion operator for the position
 * class.
 ************************************************************************/
ostream & operator << (ostream & out, const Position & rhs)
{
   if (rhs.isValid())
      out << (char)(rhs.getCol() + 'a')
      << (char)(rhs.getRow() + '1');
   else
      out << "error";

   return out;
}

/***********************************************************************
 * EXTRACTION OPERATOR
 * A method to support the extraction operator for the position
 * class.
 ************************************************************************/
istream & operator >> (istream & in, Position & rhs)
{
   char text[3] = {};
   in >> text[0] >> text[1];
   if (in.fail())
   {
      in.clear();
      in.ignore();
      throw string("Error reading coordinates");
   }
   else
   {
      rhs = text;
   }
   
   return in;
}

/***********************************************************************
 * COMPARISON OPERATOR
 * A method to support the comparison operator for the position
 * class.
 ************************************************************************/
bool Position::operator == (const Position & rhs) const
{
   return location == rhs.getLocation();
}
