//
//  dragLookUpMock.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "drag.h"
#include<cassert>

class DragMock : Drag
{
public:
   DragMock() {};
   virtual double getDrag(double mach) const 
   {
      // dragMock returns 0.1629 if it gets anything less than 0.3
      if (mach < 0.3)
         return 0.1629;
      // dragMock returns 0.3135 if the mach is 1.8470398837142770
      else if (mach == 1.8470398837142770)
         return 0.3135;
      else
         assert(false);
   };
};
