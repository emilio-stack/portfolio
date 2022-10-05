//
//  machLookUpMock.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "mach.h"
#include<cassert>

class MachMock : Mach
{
public:
   MachMock() {};
   virtual double getMach(double altitude) const 
   {
      // machMock returns 340 if it gets a 0 or 2.
      if (altitude == 0.0 || altitude == 2.0)
         return 340;
      // machMock returns 320 if altitude is 5000.
      else if (altitude == 5000)
         return 320;
      else
         assert(false);
   };
};
