/***********************************************************************
 * Header File:
 *    Move : The Move class
 * Author:
 *    Bradley Payne & Emilio Regino
 * Summary:
 *    A class to represent a move in a game of chess
 ************************************************************************/

#ifndef move_h
#define move_h

#include "position.h"
#include "testMove.h"

/****************************************************
 * MOVE
 * The move class
 ****************************************************/
class Move
{
   friend class TestMove; // To verify member variables in the test class
   
public:
   
   // Constructors
   Move() {}
   
   // Getters
   std::string getText() const;
   Position getSrc() const;
   Position getDest() const;
   bool getPromotion() const;
   
private:
   Position source;
   Position destination;
   char piece;
   char capture;
   bool enpassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   std::string error;
};

#endif /* move_h */
