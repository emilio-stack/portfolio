//
//  machLookUpMock.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "machLookUp.h"

class MachLookUpMock : MockLookUp
{
public:
   MachLookUpMock() {};
   virtual double getMach(double altitude) {return 0.0;};
};
