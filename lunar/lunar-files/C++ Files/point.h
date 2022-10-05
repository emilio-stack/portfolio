/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once

#include <iostream>

/*********************************************
 * POINT
 * A single position.  
 *********************************************/
class Point
{
public:
   // constructors
   Point()                   : x(0.0), y(0.0), x_max(0.0), y_max(0.0) {}
   Point(double x, double y) : x(x), y(y), x_max(0.0), y_max(0.0) {}
   Point(const Point & pt)   : x(pt.x), y(pt.y), x_max(pt.x_max), y_max(pt.y_max) {}
   Point(double x, double y, const Point& boundaryPoint);

   // getters
   double getX()       const { return x;              }
   double getY()       const { return y;              }
   bool operator == (const Point & rhs) const
   {
      return x == rhs.x && y == rhs.y;
   }
   bool operator != (const Point & rhs) const
   {
      return x != rhs.x || y != rhs.y;
   }

   // setters
   void setX(double x);
   void setY(double y);
   void addX(double dx)      { setX(getX() + dx);     }
   void addY(double dy)      { setY(getY() + dy);     }
   Point & operator = (const Point & rhs)
   {
      x = rhs.x;
      y = rhs.y;
      return *this;
   }

private:
   double x;           // horizontal position
   double y;           // vertical position
   double x_max;       // Maximum horizontal position
   double y_max;       // Maximum vertical position
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Point & pt);
std::istream & operator >> (std::istream & in,        Point & pt);
