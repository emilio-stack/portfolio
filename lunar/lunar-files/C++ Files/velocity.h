/***********************************************************************
 * Header File:
 *    Velocity : Represents an object's velocity in the lunar lander game.
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about a velocity of an object.
 ************************************************************************/
#pragma once

/**********************
* VELOCITY
* A single velocity.
**********************/
class Velocity
{
public:
   // constructors
   Velocity() : dx(0.0), dy(0.0)  {}
   Velocity(double dx, double dy);
   Velocity(const Velocity & velocity) : dx(velocity.dx), dy(velocity.dy) {}

   // getters
   double getDx()    const { return dx; }
   double getDy()    const { return dy; }
   double getSpeed() const;
   
   // setters
   void setDx(double dx) { this->dx = dx; }
   void setDy(double dy) { this->dy = dy; }
   void addDx(double ddx) { setDx(getDx() + ddx); }
   void addDy(double ddy) { setDy(getDy() + ddy); }

private:
   double dx;     // horizontal velocity
   double dy;     // vertical velocity
};