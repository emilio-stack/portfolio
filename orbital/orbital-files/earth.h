/***********************************************************************
 * Header File:
 *    Earth : The earth in the orbit simulator
 * Author:
 *    Emilio Regino, Bradley Payne, Penelope Sanchez
 * Summary:
 *    The earth is collidable and is always at position (0.0, 0.0)
 *    for the purposes of this simulator.
 ************************************************************************/

#pragma once

#include "position.h"      // for POSITION
#include "constants.h"     // for CONSTANTS

/***********************************************************************
 * EARTH
 * The earth in the orbit simulator.
 ************************************************************************/
class Earth
{
public:
   // constructors
   Earth(): position(0.0, 0.0), angle(0.0), radius(EARTH_RADIUS) {}
   
   // getters
   double getAngle() { return angle; }
   Position getPosition() { return position; }
   double getRadius() {return radius; }
   
   // render
   void draw() const { drawEarth(position, angle); }
   
   // modifers
   void update() { angle += -(2.0 * M_PI / 30.0) * (TIME_DILATION / 86400.0); }
   
private:
   Position position; // the position of the earth
   double angle;      // the angle of the earth in radians
   double radius;     // the radius of the earth in meters
};
