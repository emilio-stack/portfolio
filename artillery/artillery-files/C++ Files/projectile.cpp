/***********************************************************************
 * Source File:
 *    Projectile : Represents the projectile in the artillery simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    Where the projectile is located, what its status is, and information
 *    about its motion.
 ************************************************************************/

#include "projectile.h"

// Default constructor for the projectile class.
Projectile::Projectile()
{
   shadows.push_back(Position(0, 0));
}

// Constructs a Projectile given its current position.
Projectile::Projectile(Position point)
{
   position = point;
   shadows.push_back(point);
}

// Copy constructor
Projectile Projectile::operator=(Projectile otherP)
{
   position = otherP.position;
   velocity = otherP.velocity;
   status = otherP.status;
   shadows = otherP.shadows;
   age = otherP.age;
   return *this;
}

/************************************************************
* PROJECTILE : FIRE
* Tells the projectile it has been fired, and sets its velocity
* to the given velocity
*************************************************************/
void Projectile::fire(Velocity initialVelocity, Position initialPosition)
{
   if (status != FLYING)
   {
      shadows.clear();
      age = 0;
      status = FLYING;
      velocity = initialVelocity;
      position = initialPosition;
      shadows.push_back(position);
   }
}

/*************************************************************
* PROJECTILE : LAND
* Tells the projectile whether it landed on or off target.
* Sets its velocity to zero, resets shadows to just current
* position, and sets status accordingly.
**************************************************************/
void Projectile::land(bool onTarget)
{
   if (status == FLYING)
   {
      velocity = Velocity(0, 0);
      shadows.clear();
      shadows.push_back(position);
      status = (onTarget) ? ON_TARGET : OFF_TARGET;
   }
}

/************************************************************
* PROJECTILE : SHIFT SHADOWS
* Insert's the projectile's current position in the front of
* the list of shadows, and pops the last position off the end
* if necessary.
*************************************************************/
void Projectile::shiftShadows()
{
   if (status == FLYING)
   {
      shadows.insert(shadows.begin(), position);
      if (shadows.size() > NUM_SHADOWS)
         shadows.pop_back();

   }
}

/***********************************************************
* PROJECTILE : MOVE
* Updates the projectile's position, velocity, and shadows
* based on its current position and velocity. Applies all the
* physics effects of drag, gravity, inertia etc.
***********************************************************/
void Projectile::move(double time)
{
   if (status == FLYING)
   {
      // Get the projectile's current speed and altitude.
      if (getVelocity().getSpeed() < 90)
      {
         double a = 3;
      }
      double altitude = position.getMetersY();
      double speed = velocity.getSpeed();

      // Use the above to find the environment details.
      double gravity = gravityTable.getGravity(altitude);
      double density = airDensityTable.getDensity(altitude);
      double mach_speed = machTable.getMach(altitude);
      double mach = speed / mach_speed;
      double dragCoeff = dragTable.getDrag(mach);

      // Compute the total acceleration acting on the projectile.
      double dragForce = 0.5 * dragCoeff * density * speed * speed * getArea();
      Acceleration dragAcceleration = Acceleration(velocity.getAngle(), -dragForce / MASS);
      Acceleration gravityAcceleration = Acceleration(0, -gravity);
      dragAcceleration.addAcceleration(gravityAcceleration);

      // Update the position based on velocity, acceleration, and time.
      position.applyAccelerationVelocity(dragAcceleration, velocity, time);

      // Update the velocity based on acceleration and time.
      velocity.applyAcceleration(dragAcceleration, time);

      // Now that the projectile is in a new position, update the shadows and age.
      shiftShadows();
      age += time;
   }
}

/***********************************************************
* PROJECTILE : DRAW
* Draws the projectile and its shadows.
************************************************************/
void Projectile::draw(ogstream& gout) const
{
   for (int i = 0; i < shadows.size(); i++)
      gout.drawProjectile(shadows.at(i), 0.5 * (double)i);
};


// PI, for the calculation of area
//const long double M_PI = 3.14159265358979323846; // comment out if on xcode, un comment if on windows
/***********************************************************
* PROJECTILE : GET AREA
* Returns the cross-sectional area of the shell, in meters,
* as viewed from the tip of the shell.
************************************************************/
double Projectile::getArea() const
{
   const long double PI = 3.14159265358979323846;
   double r = DIAMETER / 2.0;
   return PI * r * r;
}
