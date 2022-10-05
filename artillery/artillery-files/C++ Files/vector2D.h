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

#pragma once
#include <cmath>     // For sin() & cos()
#include "angle.h"   // For the angle class

/**************************************************************************************
 * VECTOR2D
 * The vector2D class
 **************************************************************************************/
class Vector2D
{
public:
   // Make the test class a friend for verification of privates
   friend class TestVector;
   
   // Constructors
   Vector2D() : horizontalComponent(0.0), verticalComponent(0.0) {};
   Vector2D(Vector2D const &vect);                                                
   Vector2D(double hor, double vert) : horizontalComponent(hor), verticalComponent(vert) {};
   Vector2D(Angle angle, double magnitude);
   
   // Getters
   double getHorComponent() const { return horizontalComponent; };
   double getVertComponent() const { return verticalComponent; };
   virtual Angle getAngle() const;
   double getMagnitude() const;
   
   // Setters
   void setHorizontal(double horizontal) { horizontalComponent = horizontal; };
   void setVertical(double vertical) { verticalComponent = vertical; };
   void addVector(Vector2D vector);
  
protected:
   double horizontalComponent;        // The horizontal component
   double verticalComponent;          // The vertical component
};
