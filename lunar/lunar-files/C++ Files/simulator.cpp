/*************************************************************
 * 1. Name:
 *      Emilio and Preston
 * 2. Assignment Name:
 *      Lab 06: Apollo 11 Final
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part about this assignment was making
 *      the desing more elegant, but it was also a lot of fun.
 *      Our approach was once we got it working we sat down
 *      and looked at each one of our class designs and the
 *      important structure charts. We looked at our algorithms
 *      and we evaluated the whole design using metrics of all
 *      levels of design. We are able to find a lot of ares to
 *      improve on and it was a lot of refactoring but it was
 *      also a lot of fun and really helpful to improve on the
 *      c++ language. 
 * 5. How long did it take for you to complete the assignment?
 *      About 7 hours each.
 *****************************************************************/

 /***********************************************************************
  * Source File:
  *    Simulator : Represents all the moving parts we need to keep track
  *    of, and how they interact over time.
  * Author:
  *    Emilio Regino
  * Summary:
  *    Operates the movement, drawing, and interaction of the simulation.
  ************************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "lunarLander.h"
#include "star.h"
#include "simulator.h"
#include <iostream>

using namespace std;

/**********************************************************************
 * GETINPUT
 * * A method for the simulator to get input from the UI.
 * **********************************************************************/
void Simulator :: getInput(const Interface *pUI)
{
   lander.keysPressed(pUI->isDown(), pUI->isLeft(), pUI->isRight());
}
   
/**********************************************************************
 * UPDATE
 * A method to handle all updates of the simulator.
 * This includes moving the lander and checking for collisions.
 * **********************************************************************/
void Simulator :: update()
{
   // move the lander
   if (lander.isFlying())
   {
      lander.move(SECONDS_PER_FRAME);

      // did we hit the ground?
      if (ground.hitGround(lander.getPosition(), lander.getWidth()))
      {
         cout << lander.getAngle();
         lander.crash();    // update the state of the lander
      }

      // did we land?
      else if (ground.onPlatform(lander.getPosition(), lander.getWidth()) && lander.canLand())
      {
         cout << lander.getAngle();
         lander.land();    // update the state of the lander
      }
   }
}

/**********************************************************************
 * DRAW
 * A method to draw all the items of the game.
 * **********************************************************************/
void Simulator :: draw(ogstream& gout)
{
   // draw our little stars
   for (int currentStar = 0; currentStar < NUM_STARS; currentStar++)
   {
     stars[currentStar].draw(gout);
   }
   
   // draw the ground
   ground.draw(gout);
   
   // draw the lander and its flames
   lander.draw(gout);
   
   // put some text on the screen
   gout.setPosition(Point(30.0, ptUpperRight.getY() - 30));
   gout << "Fuel:\t"     << (int)lander.getFuel() << " lbs\n";
   gout << "Altitude:\t" << (int)ground.getElevation(lander.getPosition(),lander.getWidth()) << " meters\n";
   gout << "Speed:\t"    << round(lander.getSpeed() * 100.0) / 100.0 << " m/s";
   gout.setPosition(Point(150, 30));
   if (lander.isCrashed())
   {
      gout << "Houston, we have a problem!";
   }
   else if (lander.isLanded())
   {
      gout << "The Eagle has landed!";
   }
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Simulator * pSimulator = (Simulator *)p;

   // simulator handle all inputs
   pSimulator -> getInput(pUI);
   
   // simulator handles all updates
   pSimulator -> update();
   
   // simulator handles all drawing
   pSimulator -> draw(gout);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Simulator type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL,
                "Simulator",
                 ptUpperRight);

   // Initialize the game class
   Simulator simulator(ptUpperRight);

   // set everything into action
   ui.run(callBack, &simulator);

   return 0;
}
