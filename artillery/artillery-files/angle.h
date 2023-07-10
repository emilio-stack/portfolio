/***********************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    A single angle stored in degrees
 ************************************************************************/
#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
long double const PI = 3.14159265358979323846;        // For vs community users

/***********************************************************
 * ANGLE
 * The angle class
 ***********************************************************/
class Angle
{
public:
   // Test class has access to privates for testing
   friend class TestAngle;
   
   // Constructors
   Angle() : angle(0.0f) {};
   Angle(double angle) { setDegrees(convertToValid(angle)); }
   Angle(double x, double y) { angle =  degreesFromXY(x, y); }
   
   // Getters
   virtual double getRadians() const { return radiansFromDegrees(angle); };
   virtual double getDegrees() const { return angle; };  
   
   // Setters
   void setDegrees(double newAngleDegrees);
   void setRadians(double newAngleRadians) { setDegrees(convertToValid(degreesFromRadians(newAngleRadians))); };
   
   // Updaters
   void addDegrees(double amount) { setDegrees(convertToValid(angle + amount)); };
   void addRadians(double amount) { addDegrees(degreesFromRadians(amount)); };
   
protected:
   double angle;   // The angle in degrees
   
   // Converters
   double degreesFromRadians(double radians) const { return radians * 180 / PI; };
   double radiansFromDegrees(double degrees) const { return degrees * PI / 180; };
   double degreesFromXY(double x, double y) const { return degreesFromRadians(atan2(x, y)); }
   
   // Validators
   bool verifyNewAngle(double newAngle) { return (newAngle <= 180.0 && newAngle >= -180.0); }
   double convertToValid(double newAngle);
};
