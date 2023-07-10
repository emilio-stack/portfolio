/***********************************************************************
 * Header File:
 *    Piece: The piece class
 * Author:
 *    Emilio Regino, Penelope Sanchez
 * Summary:
 *    A class to represent the a piece in the game of chess.
 *    PAWN, KNIGHT, ROOK, BISHOP, KING, QUEEN, SPACE
 *    all inherit from PIECE.
 ************************************************************************/

#pragma once

#include <set>          // for SET to return a set of possible moves
#include "position.h"   // for POSITION, where the piece is located
#include "move.h"       // for MOVE, how to move a piece
#include "uiDraw.h"     // for DRAW*, to draw a piece on the screen
#include "PieceTest.h"  // for the piece test suite
#include <cassert>

using std::set;

class Board;
class Move;

/***********************************************************************
 * PIECE CLASS
 * Abstract class for the pieces.
 ************************************************************************/
class Piece
{
public:
   // Test suites with private access
   friend class testPiece;
   
   // Constructors
   Piece(int r, int c, bool isWhite = true) :   fWhite(isWhite),
                                                nMoves(0),
                                                position(r, c),
                                                lastMove(-1) {}
   Piece(const Piece& piece) { *this = piece; }
   virtual ~Piece() {}
   const Piece& operator = (const Piece& rhs);
   const Piece& operator = (const Position& rhs)
   {
      nMoves++;
      position = rhs;
      return *this;
   }

   // Getters
   bool operator == (char letter)   const { return getLetter() == letter;   }
   bool operator != (char letter)   const { return getLetter() != letter;   }
   bool isWhite()                   const { return fWhite;                  }
   bool isMoved()                   const { return getNMoves() != 0;        }
   int getNMoves()                  const { return nMoves;                  }
   const Position& getPosition()    const { return position;                }
   bool justMoved(int currentMove)  const
   {
      return (currentMove - 1 == lastMove);
   }

   // Setter
   void setLastMove(int currentMove) { lastMove = currentMove; }

   // virtual methods
   virtual char getLetter()                                          const = 0;
   virtual void display(ogstream* pgout)                             const = 0;
   virtual void getMoves(set <Move> & moves, const Board & board)    const = 0;

   
protected:
	// Moving for piece that would slide
	set <Move> getMovesSlide(	const Board& board,
										const Delta deltas[],
										int numDelta) const;
	// Moving for pieces that don't slide
	set <Move> getMovesNoslide(const Board& board,
										const Delta deltas[],
										int numDelta) const;

	int nMoves;          // Number of times moved
	bool fWhite;         // White or black?
	Position position;   // Holds position for piece
	int lastMove;        // last move the piece made
};

/***********************************************************************
 * SPACE
 * A class to represent a space in the game of chess
 ************************************************************************/
class Space : public Piece
{
public:
   Space(int r, int c) : Piece(r, c) {}
   virtual char getLetter() const { return ' '; }
   virtual void getMoves(set <Move> & moves, const Board & board) const {}
   virtual void display(ogstream * pgout) const {}
};

/***********************************************************************
 * PAWN
 * A class to represent a pawn in the game of chess
 ************************************************************************/
class Pawn : public Piece
{
public:
   Pawn(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
   char getLetter() const { return 'p'; }
   void getMoves(set <Move> & moves, const Board & board) const;
   virtual void display(ogstream * pgout) const
   {
      pgout->drawPawn(position.getLocation(), !isWhite());
   }
private:
   void addPromotion(set <Move> & moves, Move & move) const;
};

/***********************************************************************
 * ROOK
 * A class to represent a rook in the game of chess
 ************************************************************************/
class Rook : public Piece
{
public:
   Rook(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
   char getLetter() const { return 'r'; }
   void getMoves(set <Move> & moves, const Board & board) const;
   virtual void display(ogstream * pgout) const
   {
      pgout->drawRook(position.getLocation(), !isWhite());
   }
};

/***********************************************************************
 * KNIGHT
 * A class to represent a knight in the game of chess
 ************************************************************************/
class Knight : public Piece
{
public:
   Knight(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
   char getLetter() const { return 'n'; }
   void getMoves(set <Move> & moves, const Board & board) const;
   virtual void display(ogstream * pgout) const
   {
      pgout->drawKnight(position.getLocation(), !isWhite());
   }
};

/***********************************************************************
 * BISHOP
 * A class to represent a bishop in the game of chess
 ************************************************************************/
class Bishop : public Piece
{
public:
   Bishop(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
   char getLetter() const { return 'b'; }
   void getMoves(set <Move> & moves, const Board & board) const;
   virtual void display(ogstream * pgout) const
   {
      pgout->drawBishop(position.getLocation(), !isWhite());
   }
};

/***********************************************************************
 * KING
 * A class to represent a king in the game of chess
 ************************************************************************/
class King : public Piece
{
public:
   King(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
   char getLetter() const { return 'k'; }
   void getMoves(set <Move> & moves, const Board & board) const;
   virtual void display(ogstream * pgout) const
   {
      pgout->drawKing(position.getLocation(), !isWhite());
   }
private:
   void addCastle(set <Move> & moves, Move & move, bool isKing) const;
};

/***********************************************************************
 * QUEEN
 * A class to represent a queen in the game of chess
 ************************************************************************/
class Queen : public Piece
{
public:
   Queen(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
   char getLetter() const { return 'q'; }
   void getMoves(set <Move> & moves, const Board & board) const;
   virtual void display(ogstream * pgout) const
   {
   pgout->drawQueen(position.getLocation(), !isWhite());
   }
};
