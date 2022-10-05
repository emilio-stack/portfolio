/***********************************************************************
 * Header File:
 *    Angle : Represents the orientation of the lander where 0
 *    degrees is up.
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about the angle orientation
 ************************************************************************/

#include "angle.h" // for the angle class definition
#define _USE_MATH_DEFINES
#include <cmath>

/*************************************************
 * SET ANGLE
 * A method to set a new angle
 **************************************************/
void Angle :: setAngle(float newAngle)
{
   // verify the new angle is valid
   // angle must be between -pi and +pi radians
   while (newAngle >= M_PI)
      newAngle = newAngle - 2 * M_PI;
   while (newAngle <= -M_PI)
      newAngle = newAngle + 2 * M_PI;
   
   // Now assign the new angle
   angle = newAngle;
}
