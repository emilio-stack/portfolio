/***********************************************************************
 * Header File:
 *    Test Move : Test the Move class
 * Author:
 *    Emilio Regino, Bradley Payne & Penelope Sanchez
 * Summary:
 *    All the unit tests for Move
 ************************************************************************/

#ifndef testMove_h
#define testMove_h
#include "move.h"
#include "position.h"
#include <cassert>

/****************************************************
 * TEST Move
 * The test suite for the Move class
 ****************************************************/
class TestMove
{
public:

   // A method to run the test suite
   void run()
   {
      std :: cout << "Testing Move: ";
      test_Move_GetText();
      test_Move_GetSrc();
      test_Move_GetDes();
      test_Move_GetPromotion();
      test_Move_GetCapture();
      test_Move_GetEnPassant();
      test_Move_GetCastleK();
      test_Move_GetCastleQ();
      test_Move_GetWhiteMove();
      test_Move_SetEnPassant();
      test_Move_SetCastleK();
      test_Move_SetCastleQ();
      test_Move_SetWhiteMove();
      test_Move_AssignMove();
      test_Move_AssignString();
      std :: cout << "Passed!\n";
   }

   void test_Move_GetText()
   {
      // Setup
      Move m;
      m.source = Position(11);
      m.destination = Position(19);
      m.piece = 'p';    // p for pawn white
      m.capture = 'S';  // S for space
      m.enpassant = false;
      m.castleK = false;
      m.castleQ = false;
      m.isWhite = true;
      m.error == "";
      string value;

      // Exercise
      value = m.getText();

      // Verify
      assert(value == "d2d3ps");
      assert(m.source.getLocation() == 11);
      assert(m.destination.getLocation() == 19);
      assert(m.piece == 'p');   // p for pawn white
      assert(m.capture == 'S'); // S for space
      assert(m.enpassant == false);
      assert(m.castleK == false);
      assert(m.castleQ == false);
      assert(m.isWhite == true);
      assert(m.error == "");
   }   // Teardown

   void test_Move_GetSrc()
   {
      // Setup
      Move m;
      m.source = Position(3);
      m.destination = Position(11);
      m.piece = 'p';   // p for pawn white
      m.capture = 'S'; // S for space
      m.enpassant = false;
      m.castleK = false;
      m.castleQ = false;
      m.isWhite = true;
      m.error = "";
      int value;

      // Exercise
      value = m.getSrc().location;

      // Verify
      assert(value == 3);
      assert(m.source.getLocation() == 3);
      assert(m.destination.getLocation() == 11);
      assert(m.piece == 'p');   // p for pawn white
      assert(m.capture == 'S'); // S for space
      assert(m.enpassant == false);
      assert(m.castleK == false);
      assert(m.castleQ == false);
      assert(m.isWhite == true);
      assert(m.error == "");
   }   // Teardown

   void test_Move_GetDes()
   {
      // Setup
      Move m;
      m.source = Position(11);
      m.destination = Position(19);
      m.piece = 'p';   // p for pawn white
      m.capture = 'S'; // S for space
      m.enpassant = false;
      m.castleK = false;
      m.castleQ = false;
      m.isWhite = true;
      m.error == "";
      int value;

      // Exercise
      value = m.getDes().location;

      // Verify
      assert(value == 19);
      assert(m.source.getLocation() == 11);
      assert(m.destination.getLocation() == 19);
      assert(m.piece == 'p');   // p for pawn white
      assert(m.capture == 'S'); // S for space
      assert(m.enpassant == false);
      assert(m.castleK == false);
      assert(m.castleQ == false);
      assert(m.isWhite == true);
      assert(m.error == "");
   }   // Teardown

   void test_Move_GetPromotion()
   {
      // setup
      Move m;
      m.source = Position(56);
      m.destination = Position(64);
      m.piece = 'p';      // p for pawn white
      m.capture = 'S';   // S for space
      m.enpassant = false;
      m.castleK = false;
      m.castleQ = false;
      m.isWhite = true;
      m.error == "";
      char value;

      // exercise
      value = m.getPromotion();

      // verify
      assert(value == m.piece);
      assert(m.source.getLocation() == 56);
      assert(m.destination.getLocation() == 64);
      assert(m.piece == 'p');   // q for queen white
      assert(m.capture == 'S'); // S for space
      assert(m.enpassant == false);
      assert(m.castleK == false);
      assert(m.castleQ == false);
      assert(m.isWhite == true);
      assert(m.error == "");
   }   // Teardown

   void test_Move_GetCapture()
   {
      // setup
      Move m2;
      m2.source = Position(24);
      m2.destination = Position(17);
      m2.piece = 'P';   // P for pawn black
      m2.capture = 'S';   // S for space
      m2.enpassant = false;
      m2.castleK = false;
      m2.castleQ = false;
      m2.isWhite = false;
      m2.error = "";

      Move m1;
      m1.source = Position(9);
      m1.destination = Position(17);
      m1.piece = 'p';   // p for pawn white
      m1.capture = 'P';   // P for pawn black
      m1.enpassant = false;
      m1.castleK = false;
      m1.castleQ = false;
      m1.isWhite = true;
      m1.error == "";

      // exercise
      char capture = m1.getCapture();

      // verify
      assert(capture = 'p');
      assert(m1.source.getLocation() == 9);
      assert(m1.destination.getLocation() == 17);
      assert(m1.piece == 'p');   // p for pawn white
      assert(m1.capture == 'P');   // P for pawn black
      assert(m1.enpassant == false);
      assert(m1.castleK == false);
      assert(m1.castleQ == false);
      assert(m1.isWhite == true);
      assert(m1.error == "");
   }   // Teardown

   void test_Move_GetEnPassant()
   {
      // setup
      Move m1;
      m1.source = Position(32);
      m1.destination = Position(24);
      m1.piece = 'P';   // P for pawn black
      m1.capture = 'S';   // S for space
      m1.enpassant = false;
      m1.castleK = false;
      m1.castleQ = false;
      m1.isWhite = false;
      m1.error = "";

      // exercise
      bool enpassant = m1.getEnPassant();

      // verify
      assert(enpassant == false);
      assert(m1.source.getLocation() == 32);
      assert(m1.destination.getLocation() == 24);
      assert(m1.piece == 'P');   // P for pawn black
      assert(m1.capture == 'S');   // S for space
      assert(m1.enpassant == false);
      assert(m1.castleK == false);
      assert(m1.castleQ == false);
      assert(m1.isWhite == false);
      assert(m1.error == "");
   }   // Teardown

   void test_Move_GetCastleK()
   {
      // setup
      Move m1;
      m1.source = Position(4);
      m1.destination = Position(6);
      m1.piece = 'k';   // k for king white
      m1.capture = 'S';   // S for space
      m1.enpassant = false;
      m1.castleK = true;
      m1.castleQ = false;
      m1.isWhite = true;
      m1.error = "";

      // exercise
      bool castleK = m1.getCastleK();

      // verify
      assert(castleK == true);
      assert(m1.source.getLocation() == 4);
      assert(m1.destination.getLocation() == 6);
      assert(m1.piece == 'k');   // k for king white
      assert(m1.capture == 'S');   // S for space
      assert(m1.enpassant == false);
      assert(m1.castleK == true);
      assert(m1.castleQ == false);
      assert(m1.isWhite == true);
      assert(m1.error == "");
   }   // Teardown

   void test_Move_GetCastleQ()
   {
      // setup
      Move m1;
      m1.source = Position(4);
      m1.destination = Position(2);
      m1.piece = 'k';   // k for king white
      m1.capture = 'S';   // S for space
      m1.enpassant = false;
      m1.castleK = false;
      m1.castleQ = true;
      m1.isWhite = true;
      m1.error = "";

      // exercise
      bool castleQ = m1.getCastleQ();

      // verify
      assert(castleQ == true);
      assert(m1.source.getLocation() == 4);
      assert(m1.destination.getLocation() == 2);
      assert(m1.piece == 'k');   // k for king white
      assert(m1.capture == 'S');   // S for space
      assert(m1.enpassant == false);
      assert(m1.castleK == false);
      assert(m1.castleQ == true);
      assert(m1.isWhite == true);
      assert(m1.error == "");
   }   // Teardown

   void test_Move_GetWhiteMove()
   {
      // setup
      Move m1;
      m1.source = Position(10);
      m1.destination = Position(18);
      m1.piece = 'p';   // p for pawn white
      m1.capture = 'S';   // S for space
      m1.enpassant = false;
      m1.castleK = false;
      m1.castleQ = false;
      m1.isWhite = true;
      m1.error = "";

      // exercise
      bool white = m1.getWhiteMove();

      // verify
      assert(white == true);
      assert(m1.source.getLocation() == 10);
      assert(m1.destination.getLocation() == 18);
      assert(m1.piece == 'p');   // p for pawn white
      assert(m1.capture == 'S');   // S for space
      assert(m1.enpassant == false);
      assert(m1.castleK == false);
      assert(m1.castleQ == false);
      assert(m1.isWhite == true);
      assert(m1.error == "");
   }   // Teardown

   void test_Move_SetEnPassant()
   {
      // setup
      Move m1;
      m1.source = Position(32);
      m1.destination = Position(24);
      m1.piece = 'P';   // P for pawn black
      m1.capture = 'p';   // p for pawn white
      m1.enpassant = false;
      m1.castleK = false;
      m1.castleQ = false;
      m1.isWhite = false;
      m1.error = "";

      Move m2;
      m2.source = Position(9);
      m2.destination = Position(25);
      m2.piece = 'p';   // p for pawn white
      m2.capture = 'S';   // S for space
      m2.enpassant = false;
      m2.castleK = false;
      m2.castleQ = false;
      m2.isWhite = true;
      m2.error = "";

      // exercise
      m1.setEnPassant();

      // verify
      assert(m1.source.getLocation() == 32);
      assert(m1.destination.getLocation() == 24);
      assert(m1.piece == 'P');   // P for pawn black
      assert(m1.capture == 'p');   // p for pawn white
      assert(m1.enpassant == true);
      assert(m1.castleK == false);
      assert(m1.castleQ == false);
      assert(m1.isWhite == false);
      assert(m1.error == "");

      assert(m2.source.getLocation() == 9);
      assert(m2.destination.getLocation() == 25);
      assert(m2.piece == 'p');   // p for pawn white
      assert(m2.capture == 'S');   // S for space
      assert(m2.enpassant == false);
      assert(m2.castleK == false);
      assert(m2.castleQ == false);
      assert(m2.isWhite == true);
      assert(m2.error == "");
   }   // Teardown

   void test_Move_SetCastleK()
   {
      // setup
      Move m1;
      m1.source = Position(7);
      m1.destination = Position(5);
      m1.piece = 'r';   // r for white rook
      m1.capture = 'S';   // S for space
      m1.enpassant = false;
      m1.castleK = false;
      m1.castleQ = false;
      m1.isWhite = true;
      m1.error = "";

      Move m2;
      m2.source = Position(4);
      m2.destination = Position(6);
      m2.piece = 'k';   // k for king white
      m2.capture = 'S';   // S for space
      m2.enpassant = false;
      m2.castleK = false;
      m2.castleQ = false;
      m2.isWhite = true;
      m2.error = "";

      // exercise
      m2.setCastleK(true);

      // verify
      assert(m1.source.getLocation() == 7);
      assert(m1.destination.getLocation() == 5);
      assert(m1.piece == 'r');   // r for rook white
      assert(m1.capture == 'S');   // S for space
      assert(m1.enpassant == false);
      assert(m1.castleK == false);
      assert(m1.castleQ == false);
      assert(m1.isWhite == true);
      assert(m1.error == "");

      assert(m2.source.getLocation() == 4);
      assert(m2.destination.getLocation() == 6);
      assert(m2.piece == 'k');   // k for king white
      assert(m2.capture == 'S');   // S for space
      assert(m2.enpassant == false);
      assert(m2.castleK == true);
      assert(m2.castleQ == false);
      assert(m2.isWhite == true);
      assert(m2.error == "");
   }   // Teardown

   void test_Move_SetCastleQ()
   {
      // setup
      Move m1;
      m1.source = Position(0);
      m1.destination = Position(3);
      m1.piece = 'r';   // r for rook white
      m1.capture = 'S';   // S for space
      m1.enpassant = false;
      m1.castleK = false;
      m1.castleQ = false;
      m1.isWhite = true;
      m1.error = "";

      Move m2;
      m2.source = Position(4);
      m2.destination = Position(2);
      m2.piece = 'k';   // k for king white
      m2.capture = 'S';   // S for space
      m2.enpassant = false;
      m2.castleK = false;
      m2.castleQ = false;
      m2.isWhite = true;
      m2.error = "";

      // exercise
      m2.setCastleQ(true);

      // verify
      assert(m1.source.getLocation() == 0);
      assert(m1.destination.getLocation() == 3);
      assert(m1.piece == 'r');   // r for rook white
      assert(m1.capture == 'S');   // S for space
      assert(m1.enpassant == false);
      assert(m1.castleK == false);
      assert(m1.castleQ == false);
      assert(m1.isWhite == true);
      assert(m1.error == "");

      assert(m2.source.getLocation() == 4);
      assert(m2.destination.getLocation() == 2);
      assert(m2.piece == 'k');   // k for king white
      assert(m2.capture == 'S');   // S for space
      assert(m2.enpassant == false);
      assert(m2.castleK == false);
      assert(m2.castleQ == true);
      assert(m2.isWhite == true);
      assert(m2.error == "");
   }   // Teardown

   void test_Move_SetWhiteMove()
   {
      // setup
      Move move;
      move.source = Position(1);
      move.destination = Position(18);
      move.piece = 'k';   // k for king white
      move.capture = 'S'; // S for space
      move.enpassant = false;
      move.castleK = false;
      move.castleQ = false;
      move.isWhite = true;
      move.error = "";

      // exercise
      move.setWhiteMove(true);

      // verify
      assert(move.source.getLocation() == 1);
      assert(move.destination.getLocation() == 18);
      assert(move.piece == 'k');   // k for king white
      assert(move.capture == 'S'); // S for space
      assert(move.enpassant == false);
      assert(move.castleK == false);
      assert(move.castleQ == false);
      assert(move.isWhite == true);
      assert(move.error == "");
   }   // Teardown

   void test_Move_AssignMove()
   {
      // setup
      Move m1;
      m1.source = Position(0);
      m1.destination = Position(0);
      m1.piece = 'P';   // P for pawn black
      m1.capture = 'S';   // S for space
      m1.enpassant = false;
      m1.castleK = false;
      m1.castleQ = false;
      m1.isWhite = false;
      m1.error = "";

      Move m2;
      m2.source = Position(11);
      m2.destination = Position(19);
      m2.piece = 'r';   // r for rook white
      m2.capture = 'k';   // k for king white
      m2.enpassant = true;
      m2.castleK = true;
      m2.castleQ = true;
      m2.isWhite = true;
      m2.error = "some error";

      // exercise
      m1 = m2;

      // verify
      assert(m1.source.getLocation() == 11);
      assert(m1.destination.getLocation() == 19);
      assert(m1.piece == 'r');   // r for rook white
      assert(m1.capture == 'k');   // k for king white
      assert(m1.enpassant == true);
      assert(m1.castleK == true);
      assert(m1.castleQ == true);
      assert(m1.isWhite == true);
      assert(m1.error == "some error");
   }   // Teardown

   void test_Move_AssignString()
   {
      // setup
      Move m1;
      m1.source = Position(0);
      m1.destination = Position(0);
      m1.piece = 'P';   // P for pawn black
      m1.capture = 'S';   // S for space
      m1.enpassant = false;
      m1.castleK = false;
      m1.castleQ = false;
      m1.isWhite = false;
      m1.error = "";

      Move m2;
      m2.source = Position(11);
      m2.destination = Position(19);
      m2.piece = 'r';   // r for rook white
      m2.capture = 'K';   // K for king black
      m2.enpassant = true;
      m2.castleK = true;
      m2.castleQ = true;
      m2.isWhite = true;
      m2.error = "some error";

      // exercise
      m1 = m2;

      // verify
      assert(m1.source.getLocation() == 11);
      assert(m1.destination.getLocation() == 19);
      assert(m1.piece == 'r');   // r for rook white
      assert(m1.capture == 'K');   // K for king black
      assert(m1.enpassant == true);
      assert(m1.castleK == true);
      assert(m1.castleQ == true);
      assert(m1.isWhite == true);
      assert(m1.error == "some error");
   }   // Teardown
};

#endif /* testMove_h */
