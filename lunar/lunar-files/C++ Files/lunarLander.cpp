/***********************************************************************
 * Source File:
 *    Lunar Lander : Represents the lander itself in the lunar lander game.
 * Author:
 *    Preston Millward
 * Summary:
 *    Where the lander is located and its motion.
 ************************************************************************/

#define _USE_MATH_DEFINES
#include "lunarLander.h"
#include <cmath>

/**********************************************
* CRASH
* Sets the lander's status to crashed, flips it
* upside down, resets all motion, and turns off
* thrusters (for safety reasons. No explosions!)
**********************************************/
void LunarLander::crash()
{
   velocity.setDx(0.0);
   velocity.setDy(0.0);
   thrusters.igniteThrusters(false, false, false);
   status = Crashed;
   angle.setAngle(M_PI);
}

/**********************************************
* LAND
* Sets the lander's status to landed, sets it
* right side up, resets all motion, and turns
* off thrusters to conserve fuel.
**********************************************/
void LunarLander::land()
{
   velocity.setDx(0.0);
   velocity.setDy(0.0);
   thrusters.igniteThrusters(false, false, false);
   status = Landed;
   angle.setAngle(0.0f);
}

/********************************************************
* CAN LAND
* Determines whether the lander's current motion will
* allow for it to land. If it's going too fast, or at
* too extreme of an angle then it cannot land. If it is
* already landed, return true.
********************************************************/
bool LunarLander::canLand()
{
   return isLanded() || (getSpeed() < CRASH_SPEED
                         && getAngle() < CRASH_ANGLE
                         && getAngle() > -CRASH_ANGLE);
}

/******************************************
 * KEYS PRESSED
 * Handles the lander's reaction to keyboard
 * input from the user.
 *****************************************/
void LunarLander::keysPressed(bool down, bool left, bool right)
{
   if (isFlying())
   {
      thrusters.igniteThrusters(down, left, right);
   }
}

/*****************************************
 * MOVE
 * Updates the lander's motion given that an
 * amount of time (dt) has passed.
 ****************************************/
void LunarLander::move(double dt)
{
   if (isFlying())
   {
      // Update the lander's angle
      angle.adjustAngle(thrusters.getRotation());

      // Calculate the components of acceleration
      double totalAcceleration = thrusters.getThrust() / WEIGHT;
      double xAcceleration = totalAcceleration * sin(-getAngle());
      double yAcceleration = totalAcceleration * cos(getAngle()) + GRAVITY;

      // Calculate the components of velocity
      double dx = velocity.getDx() * dt + xAcceleration * 0.5 * dt * dt;
      double dy = velocity.getDy() * dt + yAcceleration * 0.5 * dt * dt;

      // Update the position
      position.addX(dx);
      position.addY(dy);

      // Update the velocity
      velocity.addDx(xAcceleration * dt);
      velocity.addDy(yAcceleration * dt);
   }
}

/*****************************************
 * DRAW
 * Handles drawing the lander
 ****************************************/
void LunarLander::draw(ogstream & gout) const
{
   gout.drawLander(position, getAngle());
   gout.drawLanderFlames(position, getAngle(), isMainThrusterOn(), isLeftThrusterOn(), isRightThrusterOn());
}
