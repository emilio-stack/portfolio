/***********************************************************************
 * Header File:
 *    Angle Mock : A mock of the Angle class
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    Limits access to functions, and performs in a very limited way.
 ************************************************************************/

#pragma once
#include <cassert>
#include "angle.h"

class TestProjectile;

class AngleMock : public Angle
{
public:
   // Constructors
   AngleMock() {}
   AngleMock(double initDegrees) {angle = initDegrees;}
   
   // Methods
   virtual double getDegrees() { return angle; }
   virtual double getRadians()
   {
      if (angle == 45)
         return PI / 4.0;
      else if (angle == 25)
         return 0.436332313;
      else if (angle == 0)
         return 0.0;
      else if (angle == 90)
         return PI / 2.0;
      else if (angle == -90)
         return -PI / 2.0;
      else if (angle == 0.17188733854)
         return 0.003;
      else if (angle == -0.17188733854)
         return -0.003;
      else if (angle == 0.01)
         return 0.0001745329252;
      else if (angle == -0.01)
         return -0.0001745329252;
      else if (angle == 89.82811266146)
         return 1.5677963268;
      else if (angle == -89.82811266146)
         return -1.5677963268;
      else if (angle == 89.9)
         return 1.5690509975;
      else if (angle == -89.9)
         return -1.5690509975;
      else if (angle == 87.1352110243)
         return 1.5207963268;
      else if (angle == -87.1352110243)
         return -1.5207963268;
      assert(false);
      return 0.0;
   }
   virtual void addDegrees(double degrees) { assert(false); }
   virtual void addRadians(double radians)
   {
      if (angle == 25 && radians == -0.003)
         angle = 24.82811266146;
      else if (angle == 90 && radians == -0.003)
         angle = 89.82811266146;
      else if (angle == -90 && radians == 0.003)
         angle = -89.82811266146;
      else if (angle == 0 && radians == 0.003)
         angle = 0.17188733854;
      else if (angle == 0 && radians == -0.003)
         angle = -0.17188733854;
      else if (angle == -0.17188733854 && radians == 0.003)
         angle = 0.0;
      else if (angle == 0.17188733854 && radians == -0.003)
         angle = 0.0;
      else if (angle == 0.01 && radians == -0.003)
         angle = -0.16188733854;
      else if (angle == -0.01 && radians == 0.003)
         angle = 0.16188733854;

      else if (angle == 25 && radians == 0.003)
         angle = 25.17188733854;
      else if (angle == 90 && radians == 0.003)
         angle = 90.17188733854;
      else if (angle == -90 && radians == -0.003)
         angle = -90.17188733854;
      else if (angle == -89.82811266146 && radians == -0.003)
         angle = -90;
      else if (angle == 89.82811266146 && radians == 0.003)
         angle = 90;
      else if (angle == 89.9 && radians == 0.030)
         angle = 90.07188733854;
      else if (angle == -89.9 && radians == -0.030)
         angle = -90.07188733854;

      else if (angle == 25 && radians == 0.05)
         angle = 27.8647889757;
      else if (angle == -90 && radians == 0.05)
         angle = -87.1352110243;
      else if (angle == 90 && radians == 0.05)
         angle = 92.8647889757;
      else if (angle == 87.1352110243 && radians == 0.05)
         angle = 90;
      else if (angle == 89.9 && radians == 0.05)
         angle = 92.7647889757;

      else if (angle == 25 && radians == -0.05)
         angle = 22.8647889757;
      else if (angle == -90 && radians == -0.05)
         angle = -92.8647889757;
      else if (angle == 90 && radians == -0.05)
         angle = 87.1352110243;
      else if (angle == -87.1352110243 && radians == -0.05)
         angle = -90;
      else if (angle == -89.9 && radians == -0.05)
         angle = -92.7647889757;

      else
         assert(false);
   }
   virtual void setDegrees(double degrees)
   {
      if (degrees == 0.0)
         angle = 0.0;
      else if (degrees == 90)
         angle = 90;
      else if (degrees == -90)
         angle = -90;
      else
         assert(false);
   }
   virtual void setRadians(double radians) { assert(false); }
private:
};
