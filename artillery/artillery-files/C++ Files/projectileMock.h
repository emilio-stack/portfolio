/***********************************************************************
 * Header File:
 *    Projectile Mock : A mock of the Projectile class
 * Author:
 *    Preston Millward
 * Summary:
 *    Limits access to functions, and performs in a very limited way.
 ************************************************************************/

#pragma once
#include <cassert>
#include "projectile.h"

class TestHowitzer;

class ProjectileMock : public Projectile
{
public:
   friend class TestHowitzer;
   ProjectileMock() { Projectile(); };
   ProjectileMock(Position point) { assert(false); };
   virtual void move(double time) { assert(false); };
   virtual void fire(Velocity initialVelocity) { assert(false); };
   virtual void land(bool onTarget) { assert(false); };
   virtual Position getPosition() const { assert(false); return position; };
   virtual Position getLastPosition() const {assert(false); return shadows.at(1); };
   virtual double getSpeed() const {assert(false); return velocity.getSpeed(); };
   virtual Velocity getVelocity() const {assert(false); return velocity; };
   virtual Angle getAngle() const {assert(false); return Angle(); };
   virtual float getAge() const {assert(false); return age; };
   virtual bool isLoaded() const {assert(false); return status == LOADED; };
   virtual bool isFlying() const {assert(false); return status == FLYING; };
   virtual bool isLanded() const {assert(false); return (status == ON_TARGET || status == OFF_TARGET); };
   virtual bool isOnTarget() const {assert(false); return status == ON_TARGET; };
   virtual void draw(ogstream& gout) const {assert(false);};
};