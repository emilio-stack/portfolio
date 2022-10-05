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

#include "howitzer.h"

 /*************************************************
  * HOWITZER : RAISE
  * Brings the howitzer's angle closer to zero.
  **************************************************/
void Howitzer::raise()
{
   // If the howitzer is pointing up or to the right, decrease the angle.
   if (angle.getDegrees() >= 0)
   {
      // Don't over do it.
      if (SMALL_ANGLE_CHANGE <= angle.getRadians())
         angle.addRadians(-SMALL_ANGLE_CHANGE);
      else
         angle.setDegrees(0.0);
   }
   // If the howitzer is pointing to the left, increase the angle.
   else
   {
      // Don't over do it.
      if (SMALL_ANGLE_CHANGE <= -angle.getRadians())
         angle.addRadians(SMALL_ANGLE_CHANGE);
      else
         angle.setDegrees(0.0);
   }
}

/*************************************************
 * HOWITZER : LOWER
 * Brings the howitzer's angle further from zero.
 **************************************************/
void Howitzer::lower()
{
   // If the howitzer is pointing up or to the right, increase the angle.
   if (angle.getDegrees() >= 0)
   {
      // Only increase by the full amount if the result is below 90.
      if (angle.getRadians() + SMALL_ANGLE_CHANGE <= Angle(90).getRadians())
         angle.addRadians(SMALL_ANGLE_CHANGE);
      else
         angle.setDegrees(90.0);
   }
   // If the howitzer is pointing to the left, decrease the angle.
   else
   {
      // Only decrease by the full amount if the result is above -90.
      if (angle.getRadians() - SMALL_ANGLE_CHANGE >= Angle(-90).getRadians())
         angle.addRadians(-SMALL_ANGLE_CHANGE);
      else
         angle.setDegrees(-90.0);
   }
}

/*************************************************
 * HOWITZER : CLOCKWISE
 * Brings the howitzer's angle closer to 90 degrees.
 **************************************************/
void Howitzer::clockwise()
{
   // Only increase by the full amount if the result not above 90.
   if (angle.getRadians() + LARGE_ANGLE_CHANGE <= Angle(90).getRadians())
      angle.addRadians(LARGE_ANGLE_CHANGE);
   else
      angle.setDegrees(90.0);
}

/*************************************************
 * HOWITZER : COUNTERCLOCKWISE
 * Brings the howitzer's angle closer to -90 degrees.
 **************************************************/
void Howitzer::counterClockwise()
{
   // Only increase by the full amount if the result is not below -90.
   if (angle.getRadians() - LARGE_ANGLE_CHANGE >= Angle(-90).getRadians())
      angle.addRadians(-LARGE_ANGLE_CHANGE);
   else
      angle.setDegrees(-90.0);
}

/*************************************************
 * HOWITZER : FIRE
 * Creates a projectile that starts at the Howitzer's
 * position, with a velocity of the Howitzer's muzzle
 * velocity
 **************************************************/
void Howitzer::fire(Projectile & p)
{
   Velocity v = Velocity(angle, MUZZLE_VELOCITY);
   p.fire(v, position);
}