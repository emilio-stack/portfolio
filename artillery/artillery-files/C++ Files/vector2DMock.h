/***********************************************************************
 * Header File:
 *    Vector 2D Mock : A mock of the Vector 2D class
 * Author:
 *    Preston Millward
 * Summary:
 *    Limits access to functions, and performs in a very limited way.
 ************************************************************************/

#pragma once
#include <cassert>
#include "vector2D.h"
#include "angleMock.h"

class TestAcceleration;

class Vector2DMock : Vector2D
{
public:
   friend class TestAcceleration;
   Vector2DMock() : horizontalComponent(0.0), verticalComponent(0.0) {};
   Vector2DMock(double x, double y) : horizontalComponent(x), verticalComponent(y) {};
   Vector2DMock(double magnitude, Angle angle)
   {
      if (magnitude == 2.0 && angle.getDegrees() == 45)
      {
         horizontalComponent = 0.7071067811865475244;
         verticalComponent = 0.7071067811865475244;
      }
      else if (magnitude == -0.0010064378153436754 && angle.getDegrees() == 53.130000000000003)
      {
         horizontalComponent = -0.00080514917352306687139;
         verticalComponent = -0.00060386412753935997922;
      }
      else if (magnitude == -0.00016103005045498806 && angle.getDegrees() == -90)
      {
         horizontalComponent = -0.00016103005045498806;
         verticalComponent = 0.0;
      }
      else if (magnitude == -0.00036231761352372317 && angle.getDegrees() == 0.0)
      {
         horizontalComponent = 0.0;
         verticalComponent = -0.00036231761352372317;
      }
      else if (magnitude == -16.270226284779564 && angle.getDegrees() == 32.54)
      {
         horizontalComponent = -8.75156396102950015406609;
         verticalComponent = -13.7160632688079074612481;
      }
      else if (magnitude == 0.0)
      {
         horizontalComponent = 0.0;
         verticalComponent = 0.0;
      }
      else
      {
         assert(false);
      }
   };
   virtual Angle getAngle()
   {
      if (horizontalComponent == 3.0 && verticalComponent == 4.0)
         return AngleMock(53.13);
      assert(false);
      return AngleMock();
   }
protected:
   double horizontalComponent;
   double verticalComponent;
   double getMagnitude() const
   {
      if (horizontalComponent == 3.0 && verticalComponent == 4.0)
         return 5.0;
      assert(false);
      return 0.0;
   };
};
