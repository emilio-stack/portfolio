//
//  dragLookUpMock.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "dragLookUp.h"

class DragLookUpMock : DragLookUp
{
public:
   DragLookUpMock() {};
   virtual double getDrag(double speed) {return 0.0;};
};
