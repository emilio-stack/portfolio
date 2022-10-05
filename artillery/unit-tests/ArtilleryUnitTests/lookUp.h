//
//  lookUp.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "position.h"

class LookUp
{
public:
   Position searchTable(long double key)
   {
      // make sure to instantiate x and y with meters
      Position pos;
      return pos;
   };
   
protected:
   long double interpolate(long double x0, long double y0,
                           long double x1, long double y1,
                           long double current_x)
   {
      return 0.0;
   };
};
