//
//  airDensityLookUpMock.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "airDensityLookUp.h"

class AirDensityLookUpMock : AirDensityLookUp
{
public:
   AirDensityLookUpMock() {};
   virtual double getDensity(double altitude) {return 0.0;};
};
