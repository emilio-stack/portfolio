///*************************************************************
// * 1. Name:
// *      Preston Millward and Emilio Regino
// * 2. Assignment Name:
// *      Lab 08: M777 Howitzer
// * 3. Assignment Description:
// *      Simulate firing the M777 howitzer 15mm artillery piece
// * 4. What was the hardest part? Be as specific as possible.
// *      Writing all those test cases
// * 5. How long did it take for you to complete the assignment?
// *      10 hours each about.
// *****************************************************************/


using namespace std;
#include "test.h"       // for TESTRUNNER
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "projectile.h" // for PROJECTILE
#include "howitzer.h"   // for HOWITZER
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*

/*******************************************************
* SIMULATOR
*  Runs the simulation.
*******************************************************/
class Simulator
{
public:
   Simulator(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      ground(ptUpperRight)
   {
      Position howitzerStartPosition = Position();
      howitzerStartPosition.setPixelsX(ptUpperRight.getPixelsX() / 2.0);
      ground.reset(howitzerStartPosition);
      howitzer.setPosition(howitzerStartPosition);
   }
   
   Ground ground;
   Projectile projectile;
   Howitzer howitzer;
   Position ptUpperRight;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator* pSimulator = (Simulator*)p;

   //
   // accept input
   //

   // move the howitzer's barrell
   if (pUI->isRight())
      pSimulator->howitzer.clockwise();
   if (pUI->isLeft())
      pSimulator->howitzer.counterClockwise();
   if (pUI->isUp())
      pSimulator->howitzer.raise();
   if (pUI->isDown())
      pSimulator->howitzer.lower();

   // fire that gun
   if (pUI->isSpace())
      pSimulator->howitzer.fire(pSimulator->projectile);

   //
   // perform all the game logic
   //

   // move the projectile across the screen
   pSimulator->projectile.move(0.5);

   // see if it hit the ground
   if (pSimulator->projectile.isFlying()) {
      if (pSimulator->ground.hitGround(pSimulator->projectile.getPosition()))
      {
         pSimulator->projectile.land(pSimulator->ground.hitTarget(pSimulator->projectile.getPosition()));
      }
   }

   //
   // draw everything
   //

   ogstream gout(Position(10.0, pSimulator->ptUpperRight.getPixelsY() - 20.0));

   // draw the ground first
   pSimulator->ground.draw(gout);

   // draw the howitzer
   double ageToPass = -1;
   if (!pSimulator->projectile.isLanded())
   {
      ageToPass = pSimulator->projectile.getAge();
   }
   pSimulator->howitzer.draw(gout, ageToPass);

   // draw the projectile
   pSimulator->projectile.draw(gout);

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
      << pSimulator->projectile.getAge() << "s\n";
   if (pSimulator->projectile.isLanded())
   {
      if (pSimulator->projectile.isOnTarget())
         gout << "Nice job! You hit the target!\n";
      else
         gout << "Oh no! You missed!";
   }
}


/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();
   //Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
   Interface ui(0, NULL,
      "Artillery Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulator sim(ptUpperRight);

   // set everything into action
   ui.run(callBack, &sim);

   return 0;
}
