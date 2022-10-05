/***********************************************************************
 * Project Name:
 *    W05 : Chess Code Complete
 * Authors:
 *    Emilio Regino, Bradley Payne & Penelope Sanchez
 * Summary:
 *    This is the completion of the chess program code. It is not
 *    polished yet
 ************************************************************************/

#include "test.h"         // for test suites
#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include "board.h"        // for board
#include "position.h"     // for position
#include "move.h"         // for move
#include <iostream>


/************************************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************************************/
void callBack(Interface *pUI, void * p)
{
   // Cast the void pointer into a board object
   Board * pBoard = (Board *)p;
   
   set <Move> possible;  // The set of possible moves

   // Clearing
   Position prev = pUI->getPreviousPosition();
   Position sel = pUI->getSelectPosition();

   if (prev.isInvalid() && sel.isInvalid())
   {
      if ((*pBoard)[sel].getLetter() == ' ')
      {
         pUI->clearSelectPosition();
      }
      else if ((*pBoard)[sel].isWhite() == pBoard->isWhiteTurn())
      {
         pUI->clearSelectPosition();
      }
   }

   // Move pieces
   if (prev.isValid() && sel.isValid() &&
       (*pBoard)[prev].isWhite() == pBoard->isWhiteTurn())
   {
      Move move;
      move.setSrc(prev);
      move.setDest(sel);
      move.complete(*pBoard);

      // Get the moves of the piece
      (*pBoard)[prev].getMoves(possible, *pBoard);

      set<Move>::iterator it = possible.find(move);
      if (it != possible.end())
      {
         pBoard->move(move);
      }
      
      pUI->clearSelectPosition();
      pUI->clearPreviousPosition();
   }

   // draw
   pBoard->display(pUI->getHoverPosition(), pUI->getSelectPosition());
}

/***********************************************************************
 * MAIN
 * Main initializes the UI and creates the board. Board will
 * handle everything else.
 ************************************************************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // run all the test suites
   testRunner();
   
   // initialize the screen and intraction classes
   Interface ui("Chess");
   ogstream * pgout = new ogstream;
   
   // create a new board
   Board board(pgout);

   // start the game
   ui.run(callBack, &board);

   return 0;
}
