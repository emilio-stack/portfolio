/**************************************************************************************
 * Header File:
 *    Vector 2D : keeps track of the horizontal and vertical components
 *    of a vector in 2-dimensional space, as well as including some simple
 *    calculations about the vector.
 * Author:
 *    Emilio Regino & Preston Millward
 * Summary:
 *    A 2D Vector expressed as horizontal and vertical components.
 **************************************************************************************/

#include "vector2D.h"     // for the vector class def

/*************************************************
 * VECTOR 2D
 * The copy constructor for the vector class
 **************************************************/
Vector2D :: Vector2D(Vector2D const &vect)
{
   horizontalComponent = vect.getHorComponent();
   verticalComponent = vect.getVertComponent();
}

/*************************************************
 * VECTOR 2D
 * The constructor for the vector class given
 * an angle and a magnitude.
 **************************************************/
Vector2D :: Vector2D(Angle angle, double magnitude)
{
   // Calculate and set the horizontal and vertical components
   setHorizontal(magnitude * sin(angle.getRadians()));
   setVertical(magnitude * cos(angle.getRadians()));
};

/*************************************************
 * GET ANGLE
 * Retruns an angle object from the horizontal
 * and vertical components
 **************************************************/
Angle Vector2D :: getAngle() const
{
   // Calculate the angle
   double radians = atan2(horizontalComponent, verticalComponent);
   
   // Create the angle object
   Angle ang;
   
   // Set the value of the angle
   ang.setRadians(radians);
   
   return ang;
}

/*********************************************************************
 * GET MAGNITUDE
 * Retruns the magnitude of the vector
 * Computes the magnitude of the hypotenuse from the
 * given orthogonal components using c = sqrt(a^2 + b^2)
 *********************************************************************/
double Vector2D :: getMagnitude() const
{
   return sqrt(horizontalComponent * horizontalComponent + verticalComponent * verticalComponent);
}

/*********************************************************************
 * ADD VECTOR
 * A method to add a vector
 *********************************************************************/
void Vector2D :: addVector(Vector2D vector)
{
   // Get the vertical and horizontal components
   double horAmount = vector.getHorComponent();
   double verAmount = vector.getVertComponent();
   
   // Add them to the current vector
   horizontalComponent += horAmount;
   verticalComponent += verAmount;
}
