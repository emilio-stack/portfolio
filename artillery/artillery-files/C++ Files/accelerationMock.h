/***********************************************************************
 * Header File:
 *    Acceleration Mock : A mock of the Acceleration class
 * Author:
 *    Preston Millward
 * Summary:
 *    Limits access to functions, and performs in a very limited way.
 ************************************************************************/

#pragma once
#include <cassert>
#include "acceleration.h"

class TestProjectile;

class AccelerationMock : public Acceleration
{
public:
   friend class TestProjectile;

   AccelerationMock() {}
   AccelerationMock(double initDDX, double initDDY)
   {
      horizontalComponent = initDDX;
      verticalComponent = initDDY;
   };

   AccelerationMock(Angle angle, double magnitude)
   {
      // if magnitude is small, just have a zero acceleration.
      if (-0.0001 < magnitude && magnitude < 0.0001)
      {
         horizontalComponent = 0;
         verticalComponent = 0;
      }
      // If it's a specific case, then here are the values.
      else if (magnitude == -0.0010064378153436754 && angle.getDegrees() == 53.130000000000003)
      {
         horizontalComponent = -0.00060386412753936;
         verticalComponent = -0.00080514917352307;
      }
      else if (magnitude == -0.00016103005045498806 && angle.getDegrees() == -90)
      {
         horizontalComponent = 0.00016103005045499;
         verticalComponent = 0.0;
      }
      else if (magnitude == -0.00036231761352372317 && angle.getDegrees() == 0)
      {
         horizontalComponent = 0.0;
         verticalComponent = -0.00036231761352372317;
      }
      else if (magnitude == -16.270226284779565952890792291221 && angle.getDegrees() == 32.54)
      {
         horizontalComponent = -13.7160632688079074612481;
         verticalComponent = -8.75156396102950015406609;
      }
      else
         assert(false);
   };

   virtual double getDDX() { return horizontalComponent; }
   virtual double getDDY() { return verticalComponent; }
   virtual void addAcceleration(AccelerationMock otherAccel)
   { 
      horizontalComponent += otherAccel.getDDX();
      verticalComponent += otherAccel.getDDY();
   };
private:
};
