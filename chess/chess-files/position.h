/***********************************************************************
 * Header File:
 *    Position : The position class
 * Author:
 *    Emilio Regino, Bradley Payne & Penelope Sanchez
 * Summary:
 *    A class to handle all positions in the game
 ************************************************************************/

#pragma once

#include <cassert>
#include <ostream>

using namespace std;

/****************************************************
 * DELTA
 * Movement in a direction (dRow, dCol)
 ***************************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0 };
const Delta ADD_C = { 0,  1 };
const Delta SUB_R = {-1,  0 };
const Delta SUB_C = { 0, -1 };

const int PIXELS_PER_SQUARE = 32;

/****************************************************
 * POSITION
 * The position class
 ****************************************************/
class Position
{
public:
   // Test suites with private access
	friend class TestPosition;
	friend class TestMove;
  
	// Constructors
   Position(const Position& rhs)
   {
      *this = rhs;
   }
   Position() :               location(-1)   {  }
   Position(int loc) :        location(loc)  {  }
   Position(const char * s) : location(0)    { *this = s; }
   Position(int r, int c)   : location(0)    { set(r, c); }
   Position(const Position & rhs, const Delta & delta) : location(-1)
   {
      set(rhs.getRow() + delta.dRow, rhs.getCol() + delta.dCol);
   }

	// Accessors
	int getLocation() const { return location;                                    }
	int getRow()      const { return (isInvalid() ? 0 : (int)(location / 8));     }
	int getCol()      const { return (isInvalid() ? 0 : (int)(location % 8));     }
   int getX()        const { return (int)((double)getCol() * getSquareWidth());  }
   int getY()        const { return (int)((double)getRow() * getSquareHeight()); }
   double getSquareWidth()  const { return squareWidth;  }
   double getSquareHeight() const { return squareHeight; }

	// Validate a position
   bool isInvalid() const { return location < 0 || location >= 64; }
   bool isValid()   const { return !isInvalid(); }

	// Setters
	void setRow(int r);
	void setCol(int c);
   void set(int r, int c)              { location = 0; setRow(r); setCol(c);           }
   void setXY(double x, double y)      { set(7 - (int)(y / getSquareHeight()),
                                             (int)(x / getSquareWidth()));             }
   void adjustRow(int dRow)            { if (isValid()) setRow(getRow() + (char)dRow); }
   void adjustCol(int dCol)            { if (isValid()) setCol(getCol() + (char)dCol); }
   void setValid()                     { if (isInvalid()) location = 0;                }
   void setInvalid()                   { location = -1;                                }
   void setSquareWidth(double width)   { if (width > 0.0) squareWidth = width;         }
   void setSquareHeight(double height) { if (height > 0.0) squareHeight = height;      }
   
   // Operators
   bool operator  < (const Position & rhs) const { return location < rhs.location; }
   bool operator == (const Position & rhs) const;
   bool operator != (const Position & rhs) const;
   const Position & operator = (const Position & rhs);
   const Position & operator = (const char     * rhs);
   const Position & operator = (const string   & rhs)
   {
      *this = rhs.c_str();
      return *this;
   };
   
   const Position & operator += (const Delta & rhs)
   {
      adjustRow(rhs.dRow);
      adjustCol(rhs.dCol);
      
      return *this;
   }
   
   Position operator + (const Delta & rhs) const
   {
      Position pos(*this);
      pos.adjustRow(rhs.dRow);
      pos.adjustCol(rhs.dCol);
      
      return pos;
   }
   
private:
	char location;
   double squareWidth;
   double squareHeight;
};

ostream & operator << (ostream & out, const Position & pos);
istream & operator >> (istream & in, Position & pos);
