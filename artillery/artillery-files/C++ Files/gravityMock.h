//
//  gravityLookUpMock.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "gravity.h"
#include<cassert>

class GravityMock : Gravity
{
public:
   GravityMock() {};
   virtual double getGravity(double altitude) const 
   {
      // gravMock returns 9.807 if it gets a 0 or 2.
      if (altitude == 0.0 || altitude == 2.0)
         return 9.807;
      // gravMock returns 9.791 if altitude is 5000.
      else if (altitude == 5000)
         return 9.791;
      else
         assert(false);
   };
};
