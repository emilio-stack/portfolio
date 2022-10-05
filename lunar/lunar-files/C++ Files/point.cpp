/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "point.h"
#include <cassert>

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 * and set the maximum position for this Point.
 *****************************************/
Point::Point(double x, double y, const Point & boundaryPoint)
{
   // Set up the boundaries.
   x_max = boundaryPoint.getX();
   y_max = boundaryPoint.getY();

   // Set the default positions.
   this->x = 0.0;
   this->y = 0.0;

   // Set the new positions.
   setX(x);
   setY(y);
}

/**********************************************
 * SET X
 * Sets the x value for this point, making sure
 * it is within bounds.
 *********************************************/
void Point::setX(double x)
{
   // If x is too small, set to zero.
   if (x < 0.0)
      this->x = 0.0;

   // If there is an upper bound and we're beyond it, set to upper bound.
   else if (x_max != 0.0 && x > x_max)
      this->x = x_max;

   // If we're in bounds, set x. 
   else
      this->x = x;
}

/**********************************************
 * SET Y
 * Sets the y value for this point, making sure
 * it is within bounds.
 *********************************************/
void Point::setY(double y)
{
   // If y is too small, set to zero.
   if (y < 0.0)
      this->y = 0.0;

   // If there is an upper bound and we're beyond it, set to upper bound.
   else if (y_max != 0.0 && y > y_max)
      this->y = y_max;

   // If we're in bounds, set y. 
   else
      this->y = y;
}

/******************************************
 * POINT insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream & operator << (std::ostream & out, const Point & pt)
{
   out << "(" << pt.getX() << ", " << pt.getY() << ")";
   return out;
}

/*******************************************
 * POINT extraction
 *       Prompt for coordinates
 ******************************************/
std::istream & operator >> (std::istream & in, Point & pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setX(x);
   pt.setY(y);

   return in;
}
