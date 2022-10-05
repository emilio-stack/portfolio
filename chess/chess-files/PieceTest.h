///***********************************************************************
// * Header File:
// *    Test position : Test the class position
// * Author:
// *    Penelope Sanchez
// * Summary:
// *    All the unit tests for peaase
// ************************************************************************/
//
//#ifndef pieceTest_h
//#define pieceTest_h
//#include "piece.h"
//#include "board.h"
//#include "move.h"
//#include <cassert>
//
//class Board;
//
///****************************************************
// * TEST PIECE
// * The test suite for the position class
// ****************************************************/
//class PieceTest
//{
//public:
//
//   // A method to run the test suite
//   void run()
//   {
//      getMovesTestSimple();
//      getMovesTestCapture();
//      getMovesTestPromotion();
//   }
//
//   // Test the simple movement of a Pawn
//   void getMovesTestSimple()
//   {
//      // Setup
//      ogstream * gout = new ogstream;
//      Board board(gout);
//      board.setCurrentMove(10);
//      Position pos("b4");
//      board.swap(Position("b2"), pos);
//
//      // Exercise
//      set <Move> moves;
//      board[pos].getMoves(moves, board);
//
//      // Verify
//      set <Move> ::iterator it;
//      assert(moves.size() == 1);
//      Move move;
//
//      move = "b4b5";
//      it = moves.find(move);
//      assert(it != moves.end());
//   } // Teardown
//
//      // Test the simple movement of a Pawn
//   void getMovesTestCapture()
//   {
//      // Setup
//      ogstream gout;
//      Board board(&gout);
//      Position pos("b6");
//      board.swap(Position("b2"), pos);
//
//      // Exercise
//      set <Move> moves;
//      board[pos].getMoves(moves, board);
//
//      // Verify
//      set <Move> ::iterator it;
//      assert(moves.size() == 2);
//      Move move;
//
//      move = "b6a7p";
//      it = moves.find(move);
//      assert(it != moves.end());
//
//         move = "b6c7p";
//      it = moves.find(move);
//      assert(it != moves.end());
//   } // Teardown
//
//   void getMovesTestPromotion()
//   {
//      // Setup
//      ogstream gout;
//      Board board(&gout);
//      Position pos("b7");
//      board.swap(Position("b2"), pos);
//      board.swap(Position("b8"), (Position("a6")));
//
//      // Exercise
//      set <Move> moves;
//      board[pos].getMoves(moves, board);
//
//      // Verify
//      set <Move> ::iterator it;
//      assert(moves.size() == 3);
//      Move move;
//
//      move = "b7a8rQ";
//      it = moves.find(move);
//      assert(it != moves.end());
//
//         move = "b7b8Q";
//      it = moves.find(move);
//      assert(it != moves.end());
//
//         move = "b7c8Q";
//      it = moves.find(move);
//      assert(it != moves.end());
//   } // Teardown
//};
//
//void getMoves_enpassant()
//{
//   //SETUP
//   ogstream gout;
//   Board board(&gout);
//   Position pos("b5");
//   board.swap(Position("b2"), pos);
//   Move m("a7a5");
//   m.setWhiteMove(false);
//   board.move(m);
//   set<Move> moves;
//
//   // EXERCISE
//   board[pos].getMoves(moves, board);
//
//   //VERIFY
//   set <Move> ::iterator it;
//   assert(moves.size() == 2);
//   Move move;
//
//   move = "b5a6E";
//   it = moves.find(move);
//   assert(it != moves.end());
//
//   move = "b5a6";
//   it = moves.find(move);
//   assert(it != moves.end());
//}
//
//#endif /* testPosition_h */
