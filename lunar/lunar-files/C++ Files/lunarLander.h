/***********************************************************************
 * Header File:
 *    Lunar Lander : Represents the lander itself in the lunar lander game.
 * Author:
 *    Preston Millward
 * Summary:
 *    Where the lander is located and its motion.
 ************************************************************************/

#pragma once
#include "thrusters.h"
#include "velocity.h"
#include "point.h"
#include "angle.h"
#include "uiDraw.h"  // for ogstream


/***************************************************
 * LUNAR LANDER
 * A lunar lander module.
 **************************************************/
class LunarLander
{
public:
   // constructors
   // These errors occured when the static was taken out of the private variables below
   LunarLander() : status(Flying), angle(Angle()), position(Point()), thrusters(Thrusters()), velocity(Velocity()) {}
   LunarLander(Point startPoint) : status(Flying), angle(Angle()), position(startPoint), thrusters(Thrusters()), velocity(Velocity()) {}
   LunarLander(Point startPoint, Velocity startVelocity) : status(Flying), angle(Angle()), position(startPoint), thrusters(Thrusters()), velocity(startVelocity) {}
   LunarLander(double startAngle, Point startPoint, Velocity startVelocity) : status(Flying), angle(Angle(startAngle)), position(startPoint), thrusters(Thrusters()), velocity(startVelocity) {}

   // getters
   double getSpeed() const { return velocity.getSpeed(); } // Return the speed of the lander in m/s
   short getFuel() const { return thrusters.getFuel(); }   // Return the amount of fuel left in pounds
   float getAngle() const { return angle.getAngle(); }               // Return the lander's angle in radians (0 is up)
   int getWidth() const {return WIDTH; }                   // Return the lander's width in pixels
   Point getPosition() const { return position; }          // Return the lander's position as a Point

   bool isMainThrusterOn() const { return thrusters.isMainThrusterOn(); }   // Whether the main thruster is on
   bool isLeftThrusterOn() const { return thrusters.isLeftThrusterOn(); }   // Whether the left thruster is on
   bool isRightThrusterOn() const { return thrusters.isRightThrusterOn(); } // Whether the right thruster is on
   bool isCrashed() { return status == Crashed;}                            // Whether the lander is in a crashed state
   bool isLanded()  { return status == Landed; }                            // Whether the lander is in a landed state
   bool isFlying()  { return status == Flying; }                            // Whether the lander is in a flying state
   bool canLand();                                                          // Whether the lander's speed and angle allow it to land

   //setters
   void keysPressed(bool down, bool left, bool right); // Tells the thrusters which keys are currently pressed
   void crash();                                       // Puts the lander in a crashed state
   void land();                                        // Puts the lander in a landed state
   
   // draw
   void draw(ogstream & gout) const;
   
   // update
   void move(double dt);

private:
   const double WEIGHT = 15103.0;   // The weight of the lander, in kilograms
   const double GRAVITY = -1.625;   // The acceleration due to gravity on the lander, in m/s
   const double CRASH_SPEED = 4.0;  // The speed at which the lander cannot land.
   const double CRASH_ANGLE = 0.4;   // The absolute value of the angle at which the lander cannot land.
   const int WIDTH = 20;            // The width of the lander, in meters
   const enum lander_status {Flying, Landed, Crashed};
   lander_status status;            // The status of the lander, whether landed, crashed, or flying
   Thrusters thrusters;             // The thrusters of the lander
   Point position;                  // The position of the lander
   Velocity velocity;               // The velocity of the lander
   Angle angle;                    // The angle of the lander, where 0 is up
};
