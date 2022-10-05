//
//  gravityLookUpMock.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "gravityLookUp.h"

class GravityLookUpMock : GravityLookUp
{
public:
   GravityLookUpMock() {};
   virtual double getGravity(double altitude) {return 0.0;};
};
