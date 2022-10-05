/***********************************************************************
 * Header File:
 *    Velocity Mock : A mock of the Velocity class
 * Author:
 *    Preston Millward
 * Summary:
 *    Limits access to functions, and performs in a very limited way.
 ************************************************************************/

#pragma once

#include <cassert>
#include <string>
#include "velocity.h"
#include "angleMock.h"

using std::to_string;

class TestProjectile;

class VelocityMock : public Velocity
{
public:
   friend class TestProjectile;

   VelocityMock()
   {
      speed = 0.0;
      angle = AngleMock(0);
      horizontalComponent = 0;
      verticalComponent = 0;
   };
   VelocityMock(double initDX, double initDY)
   {
      // For each of the following, values were hand-calculated
      // for the inputs. If any value is passed in
      // besides the ones here, that's an issue and we need to 
      // make another case.
      if (initDX == 0.0 && initDY == 0.0)
      {
         speed = 0.0;
         angle = AngleMock(0);
         horizontalComponent = 0;
         verticalComponent = 0;
      }
      else if (initDX == 3.0 && initDY == 4.0)
      {
         speed = 5.0;
         angle = AngleMock(53.13);
         horizontalComponent = 3.0;
         verticalComponent = 4.0;
      }
      else if (initDX == -2.0 && initDY == 0.0)
      {
         speed = 2.0;
         angle = AngleMock(-90.0);
         horizontalComponent = -2.0;
         verticalComponent = 0.0;
      }
      else if (initDX == 0.0 && initDY == 3.0)
      {
         speed = 3.0;
         angle = AngleMock(0.0);
         horizontalComponent = 0.0;
         verticalComponent = 3.0;
      }
      else if (initDX == 498.28 && initDY == 317.90)
      {
         speed = 591.052762788;
         angle = AngleMock(32.54);
         horizontalComponent = 498.28;
         verticalComponent = 317.90;
      }
      else
         assert(false);
   };

   // adds acceleration to velocity over a period of time.
   virtual void applyAcceleration(Acceleration accel, double time)
   {
      horizontalComponent += accel.getDDX() * time;
      verticalComponent += accel.getDDY() * time;
   };

   virtual double getDX() const { return horizontalComponent; }
   virtual double getDY() const { return verticalComponent; }
   virtual double getSpeed() const { return speed; }
   virtual Angle getAngle() const { return angle; }
private:
   double speed;
   Angle angle;
};

