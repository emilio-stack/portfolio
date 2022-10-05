/***********************************************************************
 * Header File:
 *    Fuel : Represents how much fuel the thrusters have in the lunar lander game.
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about the thruster's fuel.
 ************************************************************************/

#pragma once
 /**********************
 * FUEL
 * An amount of fuel.
 **********************/
class Fuel
{
public:
   // constructors
   Fuel() : fuel(MAX_FUEL) {}
   Fuel(int amount) { setFuel(amount); }

   // Updater
   void useFuel(int amount) { setFuel(fuel - amount); }

   // Getter
   short getFuel() const { return fuel; }

private:
   const short MAX_FUEL = 5000;
   // -32,768 to 0 is 0 fuel. 0 to MAX_FUEL is fuel, MAX_FUEL to 32,767 is MAX_FUEL fuel
   short fuel;
   void setFuel(int amount);
};