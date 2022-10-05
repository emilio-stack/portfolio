/***********************************************************************
 * Source File:
 *    move.cpp
 * Author:
 *    Emilio Regino, Bradley Payne, Penelope Sanchez,
 *    Brother Helfrich
 * Summary:
 *    A class to handle functions for move class
 ************************************************************************/

#include "move.h"
#include "piece.h"
#include "board.h"
#include <cassert>
#include <sstream>
#include <iostream>


using namespace std;

/***********************************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 * Sets up the default values for move class
 ************************************************************************/
Move::Move()
{
	this->enpassant = false;
	this->castleK = false;
	this->castleQ = false;
	this->isWhite = true;
	this->capture = PIECE_EMPTY;
	this->piece = PIECE_EMPTY;
}

/***********************************************************************
 * MOVE : COMPLETE
 * we have a move that is nothing but a source and a destination
 * Figure out what it should be.
 ************************************************************************/
void Move::complete(const Board & board)
{
   // set the capture
   capture = board[destination].getLetter();
   
   // set the color
   isWhite =  board[source].isWhite();
   
   // handle if this is an en-passant
   if (capture == ' ' && board[source] == 'p')
      enpassant = true;
   
   // handle castle K
   if (board[source] == 'k'  &&
       board[source].getNMoves() == 0 &&
       destination == 6)
   {
      castleK = true;
   }
   
   // handle castle Q
   if (board[source] == 'k'  &&
       board[source].getNMoves() == 0 &&
       destination == 2)
   {
      castleQ = true;
   }
   
   // handle promotion
   if (board[source] == 'p' && destination.getRow() == (board[source].isWhite() ? 7 : 0))
   {
      piece = 'Q';
   }
}

/***********************************************************************
 * MOVE : EQUALITY
 ************************************************************************/
bool Move::operator == (const Move & rhs) const
{
   if (this->source        == rhs.getSrc()         &&
       this->destination   == rhs.getDes()         &&
       this->castleK       == rhs.getCastleK()     &&
       this->castleQ       == rhs.getCastleQ()     &&
       this->enpassant     == rhs.getEnPassant()   &&
       this->capture       == rhs.getCapture()     &&
       this->piece         == rhs.getPromotion())
   {
      assert(enpassant  == rhs.getEnPassant());
      assert(castleK    == rhs.getCastleK());
      assert(castleQ    == rhs.getCastleQ());
      assert(piece      == rhs.getPromotion());
      return true;
   }
   else
      return false;
}

/***********************************************************************
 * GET TEXT
 * Returns the current location and the move locations as a string.
 * A pawn at row: 2 col: D moving to row 3 would return d2d3 in a string.
 ************************************************************************/
string Move::getText() const
{
   // if there is an error, return it instead
   if (error.length())
      return error;
   
   // use the string stream so we can use the
   // insertion operators of the position class.
   ostringstream sout;
   sout << source << destination;
   
   // handle all the special stuff
   if (enpassant)
      sout << "E";
   if (castleK)
      sout << "c";
   if (castleQ)
      sout << "C";
   if (piece != PIECE_EMPTY)
      sout << piece;
   if (capture != PIECE_EMPTY)
      sout << (char)tolower(capture);
   
   // return the result as a string
   return sout.str();
}

/***********************************************************************
 * MOVE : ASSIGNMENT
 ************************************************************************/
const Move & Move::operator = (const Move & rhs)
{
   source = rhs.getSrc();
   destination = rhs.getDes();
   piece = rhs.getPromotion();
   capture = rhs.getCapture();
   enpassant = rhs.getEnPassant();
   castleK = rhs.getCastleK();
   castleQ = rhs.getCastleQ();
   isWhite = rhs.getWhiteMove();
   error = rhs.error;
   return *this;
}

/***********************************************************************
 * MOVE : READ
 * Parse the input into components. We will not validate until later
 ************************************************************************/
void Move::read(const string &s)
{
   // clear the move
   *this = Move();
   
   //
   // from square
   //
   source = s.c_str() + 0;  // start at the start
   
   //
   // to square
   //
   destination = s.c_str() + 2;  // start two characters in, the destination
   
   //
   // capture and promotion
   //
   for (int i = 4; i < (int)s.size(); i++)
   {
      switch (s[i])
      {
         case 'p':   // capture a pawn
         case 'n':   // capture a knight
         case 'b':   // capture a bishop
         case 'r':   // capture a rook
         case 'q':   // capture a queen
         case 'k':   // !! can't capture a king
            capture = tolower(s[i]);
            break;
         case 'c':   // short castle or kingside castle
            castleK = true;
            break;
         case 'C':   // long castle or queenside castle
            castleQ = true;
            break;
         case 'E':   // enpassant
            enpassant = true;
            break;
            
         case 'N':   // promote to knight
         case 'B':   // promote to bishop
         case 'R':   // promote to rook
         case 'Q':   // promote to queen
            piece = s[i];
            break;
         
         default:
            // unknown piece
            error = s;
            throw string("unknown promotion piece specification");
      }
   }
   
   // if we made it this far, we are successful
   return;
}

/***********************************************************************
 * MOVE : INSERTION OPERATOR
 * A glorified get text call
 ************************************************************************/
ostream & operator << (ostream & out, Move & rhs)
{
   out << rhs.getText();
   
   return out;
}

/***********************************************************************
 * MOVE : EXTRACTION OPERATOR
 * The assignment operator with a string on the right hand side
 ************************************************************************/
istream & operator >> (istream & in, Move & rhs)
{
   string s;
   if (in >> s)
      rhs = s;  // assignment operator calling Move::read()
   
   return in;
}
