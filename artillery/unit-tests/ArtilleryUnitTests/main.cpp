//
//  main.cpp
//  Lab10
//
//  Created by Emilio on 3/10/22.
//

#include <iostream>
#include "testGround.h"
#include "position.h"
#include "airDensityLookUp.h"

double Position::metersFromPixels = 40.0;

int main(int argc, const char * argv[]) {
   TestGround test;
   test.run();
   std::cout << "Hello, World!\n";
   return 0;
}
