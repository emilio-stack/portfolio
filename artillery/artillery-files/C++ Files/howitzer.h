/***********************************************************************
 * Header File:
 *    Howitzer : Represents the Howitzer in the artillery simulation.
 * Author:
 *    Preston Millward
 * Summary:
 *    The howitzer is stationary on the ground. The angle of its barrell
 *    can be changed, and when the user fires a shot, it will produce a 
 *    projectile with the correct velocity and the same angle that the
 *    howitzer was aimed at. 
 ************************************************************************/

#pragma once

#include "projectileMock.h"
#include "angleMock.h"
#include "uiDraw.h"  // for ogstream

class TestHowitzer;

class Howitzer
{
public:
   friend class TestHowitzer;
   
   // Default Constructor
   Howitzer() { Howitzer(Position(0, 0)); };
   // Construct with a start position
   Howitzer(Position startPosition) { position = startPosition; angle = Angle(0); };
  
   // Fire the projectile
   void fire(Projectile & p);

   // Draw the howitzer if the projectile has not been fired.
   void draw(ogstream & gout) const { draw(gout, -1); }
   // Draw the howitzer if the projectile has been fired.
   void draw(ogstream & gout, double age) const { gout.drawHowitzer(position, angle.getRadians(), age); };

   // Return the angle the howitzer is pointing
   Angle getAngle() const { return angle; };

   // Set position
   void setPosition(Position newPosition) { position = newPosition; };

   // The following functions adjust the angle of the howitzer.
   // Closer to 0
   void raise();
   // Further from 0
   void lower();
   // Closer to +90
   void clockwise();
   // Closer to -90
   void counterClockwise();

private:
   Angle angle;                             // Angle the howitzer is pointing
   Position position;                       // Where the howitzer is positioned
   double const MUZZLE_VELOCITY = 827.0;    // m/s
   double const SMALL_ANGLE_CHANGE = 0.003; // radians
   double const LARGE_ANGLE_CHANGE = 0.05;  // radians
};