/***********************************************************************
 * Header File:
 *    Position Mock : A mock of the position class
 * Author:
 *    Emilio Regino
 * Summary:
 *    A class to handle all positions in the game
 ************************************************************************/

#ifndef positionMock_h
#define positionMock_h
#include "position.h"
#include <cassert>
#include <ostream>

/****************************************************
 * POSITION
 * The position class
 ****************************************************/
class PositionMock : public Position
{
public:
   
   // Constructor
   PositionMock() {};
   PositionMock(int loc) { location = loc; };
   
   // Getters
   int getLocation() const { assert(false); return location;     };
   int getRow()      const { assert(false); return location / 8; };
   int getColumn()   const { assert(false); return location % 8; };
   double getX()     const { assert(false); return squareWidth;  };
   double getY()     const { assert(false);return squareHeight; };
   
   // Validate a position
   bool isValid() const { assert(false); return false;};
   
   // Setters
   void setRow(int destRow)           { assert(false); };
   void setCol(int destCol)           { assert(false); };
   void set(int destRow, int destCol) { assert(false); };
   void adjustRow(int dxRow)          { assert(false); };
   void adjustCol(int dxCol)          { assert(false); };
   
private:
   int location;
   double squareWidth;
   double squareHeight;
};

#endif /* positionMock_h */
