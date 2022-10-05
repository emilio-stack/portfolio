//
//  airDensityLookUp.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "lookUp.h"
#include "position.h"

class AirDensityLookUp : LookUp
{
public:
   AirDensityLookUp() {
      // instantiate the values array
      // store as an array of positions to contain an x and y component
      // the x and y component are stored as meters in position class
      // maybe we should make a separte coord class with x and y components
      values[0] = Position(0.0,      1.2250000);
      values[1] = Position(1000.0,   1.1120000);
      values[2] = Position(2000.0,   1.0070000);
      values[3] = Position(3000.0,   0.9093000);
      values[4] = Position(4000.0,   0.8194000);
      values[5] = Position(5000.0,   0.7364000);
      values[6] = Position(6000.0,   0.6601000);
      values[7] = Position(7000.0,   0.5900000);
      values[8] = Position(8000.0,   0.5258000);
      values[9] = Position(9000.0,   0.4671000);
      values[10] = Position(10000.0,  0.4135000);
      values[11] = Position(15000.0,  0.1948000);
      values[12] = Position(20000.0,  0.0889100);
      values[13] = Position(25000.0,  0.0400800);
      values[14] = Position(30000.0,  0.0184100);
      values[15] = Position(40000.0,  0.0039960);
      values[16] = Position(50000.0,  0.0010270);
      values[17] = Position(60000.0,  0.0003097);
      values[18] = Position(70000.0,  0.0000828);
      values[19] = Position(80000.0,  0.0000185);
   };

   // Look up the value for a given altitude
   double getDensity(double givenAltitude)
   {
      for (int i =0; i < sizeof(values); i++)
      {
         // check if given altitude is contained in the values table
         double altitude = values[i].getMetersX();
         if (givenAltitude == altitude)
         {
            return values[i].getMetersY();
         }
      }

      // if not then search the table
      Position keys = searchTable(givenAltitude);

      // Extract keys
      long double keyBefore = keys.getMetersX();
      long double keyAfter = keys.getMetersY();

      // Extract key values
      long double keyBeforeValue = 0.0;
      long double keyAfterValue = 0.0;
      for (int i = 0; i < sizeof(values); i++)
      {
         double key = values[i].getMetersX();
         if (keyBefore == key)
         {
            // get the corresponding air density value
            keyBeforeValue = values[i].getMetersY();
         }
         else if (keyAfter == key)
         {
            // get the corresponding air density value
            keyAfterValue = values[i].getMetersY();
         }
      }

      // interpolate
      long double interpolatedAirDensity = interpolate(keyBefore, keyBeforeValue,
                                                       keyAfter, keyAfterValue,
                                                       givenAltitude);
      // and return the interpolated value
      return interpolatedAirDensity;
   };
private:
   static Position values[20];
};
