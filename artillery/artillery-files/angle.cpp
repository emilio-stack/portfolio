/***************************************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 *    where 0 degrees is up.
 * Author:
 *    Emilio Regino & Preston Millward
 * Summary:
 *    Keeps track of an angle, and provides an easy interface to convert to
 *    and from degrees and radians
 ***************************************************************************************/

#include "angle.h"     // for the angle class definition

/*************************************************
 * SET DEGREES
 * A method to set a new angle in degrees
 **************************************************/
void Angle::setDegrees(double newAngle)
{
   // make sure the angle is valid before assigning
   angle = convertToValid(newAngle);
}

/*************************************************
 * CONVERT TO VALID
 * A method to convert an invalid angle to a
 * valid angle.
 **************************************************/
double Angle :: convertToValid(double newAngle)
{
   // if the angle is greater than 180
   while (newAngle > 180.0)
      // subtract 360 to get the same direction but in the valid range
      newAngle = newAngle - 360.0;

   // if the angle is less than 180
   while (newAngle < -180.0)
      // add 360 to get the same direction but in the valid range
      newAngle = newAngle + 360.0;

   return newAngle;
};
