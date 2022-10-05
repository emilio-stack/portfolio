/***********************************************************************
 * Header File:
 *    Anglel : Represents the orientation of the lander where 0
 *    degrees is up.
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about the angle orientation
 ************************************************************************/

#pragma once

class Angle
{
public:
   // Constuctors
   Angle() : angle(0.0f) {}
   Angle(float angle) {setAngle(angle);}
   
   // Updaters
   void setAngle(float newAngle);
   void adjustAngle(float amount) {setAngle(angle + amount);};
   
   // Getters
   float getAngle() const {return angle;};
   
private:
   float angle;

};
