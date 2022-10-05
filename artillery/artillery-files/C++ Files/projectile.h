/***********************************************************************
 * Header File:
 *    Projectile : The representation of a projectile
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about the projectile's position, status,
 *    and motion.
 ************************************************************************/
#pragma once
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include "airDensity.h"
#include "gravity.h"
#include "drag.h"
#include "mach.h"
#include "uiDraw.h"  // for ogstream
#include <vector>    // for vectors
#define _USE_MATH_DEFINES // for M_PI to work on xcode (comment out on windows)
#include <cmath>           // for M_PI to work on xcode (comment out on windows)
class TestProjectile;
class TestHowitzer;
 /*********************************************
  * Projectile
  * Everything we need to know about the
  * projectile's position, status, and motion.
  *********************************************/
class Projectile
{
public:
   friend class TestProjectile;
   friend class TestHowitzer;
   Projectile();
   Projectile(Position point);
   Projectile operator=(Projectile otherP);
   virtual void move(double time);
   virtual void fire(Velocity initialVelocity, Position initialPosition);
   virtual void land(bool onTarget);
   virtual Position getPosition() const { return position; };
   virtual Position getLastPosition() const { return shadows.at(1); };
   virtual double getSpeed() const { return velocity.getSpeed(); };
   virtual Velocity getVelocity() const { return velocity; };
   virtual Angle getAngle() const { return Angle(); };
   virtual float getAge() const { return age; };
   virtual bool isLoaded() const { return status == LOADED; };
   virtual bool isFlying() const { return status == FLYING; };
   virtual bool isLanded() const { return (status == ON_TARGET || status == OFF_TARGET); };
   virtual bool isOnTarget() const { return status == ON_TARGET; };
   virtual void draw(ogstream& gout) const;

protected:
   void shiftShadows();
   double getArea() const;
   const double MASS = 46.7;        // kilograms
   const double DIAMETER = 0.15489; // meters
   const char NUM_SHADOWS = 6;
   const Gravity gravityTable;
   const AirDensity airDensityTable;
   const Mach machTable;
   const Drag dragTable;
   float age = 0;
   Velocity velocity;
   Position position;
   const enum ProjectileStatus{ LOADED, FLYING, ON_TARGET, OFF_TARGET };
   ProjectileStatus status;
   std::vector<Position> shadows;
};
