/***********************************************************************
 * Header File:
 *    Velocity : Represents a 2-dimensional velocity in the
 *    artillery simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    Tracks the components of a 2-dimensional velocity, and provides
 *    a simple way to apply an acceleration over time.
 *    Inherits from the Vector2D class.
 ************************************************************************/

#pragma once

#include "vector2DMock.h"
#include "acceleration.h"

class TestVelocity;
class TestProjectile;

class Velocity : public Vector2D
{
public:
   friend class TestVelocity;
   friend class TestProjectile;

   // Default constructor
   Velocity() {};
   // Construct from components
   Velocity(double x, double y) : Vector2D(x, y) { };
   // Construct from angle and magnitude
   Velocity(Angle angle, double mag) : Vector2D(angle, mag) {};

   // Apply an acceleration to this velocity for the specified amount of time
   virtual void applyAcceleration(Acceleration accel, double time);

   // Getters
   virtual double getDX() const { return horizontalComponent; };
   virtual double getDY() const { return verticalComponent; };
   virtual double getSpeed() const { return getMagnitude(); };
protected:
};