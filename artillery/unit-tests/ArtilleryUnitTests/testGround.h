/***********************************************************************
 * Header File:
 *    Test Ground : Test the Ground class
 * Author:
 *    Emilio Regino
 * Summary:
 *    All the unit tests for the code I wrote in the ground class
 ************************************************************************/


#pragma once
#include "ground.h"
#include "position.h"
#include <cassert>    // for ASSERT


/************************************************************************************
 * GROUND TEST
 *
 * A class to test a ground class
 ************************************************************************************/
class TestGround
{
public:
   void run()
   {
      // Run the tests
      groundTestHitGroundTrue();
      groundTestHitGroundFalse();
   }
   
private:
   
   //
   // Ground
   //
   

   // Verify that we are alerted when we hit the
   // ground
   void groundTestHitGroundTrue()
   {
      // setup
      Position ptUpperRight;
      ptUpperRight.setPixelsX(700.0);
      ptUpperRight.setPixelsY(500.0);
      Ground g = Ground(ptUpperRight);
      
      Position ptHowitzer;
      double x = ptUpperRight.getPixelsX() / 2.0;
      ptHowitzer.setPixelsX(x);
      g.reset(ptHowitzer);
      
      double newElevation = g.ground[5];
//      Position somePosition;
//      somePosition.setPixelsX(5);
//      somePosition.setPixelsY(newElevation);
      
      // exercise
      bool value = g.hitGround(5, newElevation);
      
      // verify
      assert(value == true);
      
      // teardown
   }
   
   // Verify that we are not falsely alerted
   // when we have not hit the ground
   void groundTestHitGroundFalse()
   {
      // setup
      Position ptUpperRight;
      ptUpperRight.setPixelsX(700.0);
      ptUpperRight.setPixelsY(500.0);
      Ground g = Ground(ptUpperRight);
      
      Position ptHowitzer;
      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
      g.reset(ptHowitzer);
      
      int x = (int) ptUpperRight.getPixelsX();
      double newElevation = g.ground[5];
//      Position somePosition;
//      somePosition.setPixelsX(5);
//      somePosition.setPixelsY(newElevation + 20.0);
      
      // exercise
      bool value = g.hitGround( 5, newElevation + 20.0);
      
      // verify
      assert(value == false);
      
      // teardown
   }
};
