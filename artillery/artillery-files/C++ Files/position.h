/***********************************************************************
 * Header File:
 *    Point : The representation of a position 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/


#pragma once

#include "acceleration.h"
#include "velocity.h"
#include <iostream>

/*********************************************
 * Position
 * A single position on the field in Meters or Pixels
 *********************************************/
class Position
{
public:
   
   // constructors
   Position()            : x(0.0), y(0.0)  {}
   Position(double x, double y); // in meters
   Position(const Position & pt) : x(pt.x), y(pt.y) {}
   Position& operator = (const Position& pt);

   // getters
   virtual double getMetersX() const { return x;                    }
   virtual double getMetersY() const { return y;                    }
   virtual double getPixelsX() const { return (int)(x / metersFromPixels); }
   virtual double getPixelsY() const { return (int)(y / metersFromPixels); }

   // setters
   virtual void applyAccelerationVelocity(Acceleration accel, Velocity vel, double time);
   virtual void setMetersX(double xMeters)  { this->x = xMeters;                      }
   virtual void setMetersY(double yMeters)  { this->y = yMeters;                      }
   virtual void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters);    }
   virtual void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters);    }
   virtual void setPixelsX(double xPixels)  { this->x = xPixels * metersFromPixels;   }
   virtual void setPixelsY(double yPixels)  { this->y = yPixels * metersFromPixels;   }
   virtual void addPixelsX(double dxPixels) { setPixelsX(getPixelsX() + dxPixels);    }
   virtual void addPixelsY(double dyPixels) { setPixelsY(getPixelsY() + dyPixels);    }

   // deal with the ratio of meters to pixels
   virtual void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   virtual double getZoom() const { return metersFromPixels; }

protected:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in, Position& pt);

/*********************************************
 * PT
 * Trivial point, no units implied
 *********************************************/
struct PT
{
   int x;
   int y;
};
