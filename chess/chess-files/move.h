/***********************************************************************
 * Header File:
 *    Move : The move class
 * Author:
 *    Emilio Regino, Bradley Payne, Penelope Sanchez,
 *    Brother Helfrich
 * Summary:
 *    A class to handle all moves in the game
 ************************************************************************/

#pragma once

#include <cassert>
#include <iostream>
#include <string>
#include "position.h"
//#include "board.h"

// Constants
const char PIECE_EMPTY = ' ';

// forward declaration
class Board;

using namespace std;

/****************************************************
 * MOVE
 * The move class
 ****************************************************/
class Move
{
private:
   void read(const string & s);
   
	Position source;        // where the move originated from
	Position destination;   // where the move finished
	char piece;             // piece to be promoted to
	char capture;           // did a capture happen this move?
	bool enpassant;         // Enpassant pawn capture
	bool castleK;           // kingside castle
	bool castleQ;           // queenside castle
	bool isWhite;           // white's move
	string error;           // if in error state, what was the bug?

public:
	// To verify member variables in the test class
	friend class TestMove;

	// Default Constructor
	Move();
   Move(const Move & rhs)              { *this = rhs;          }
   Move(const char * s)                { *this = s;            }

	// Gets location as string
	string getText()           const;

	// Simple getters
	const Position & getSrc()  const    { return source;			}
	const Position & getDes()  const    { return destination;	}
   char getPromotion()        const    { return piece;         }
   char getCapture()          const    { return capture;       }
	bool getEnPassant()	      const		{ return enpassant;		}
	bool getCastleK()		      const		{ return castleK;			}
	bool getCastleQ()		      const		{ return castleQ;			}
	bool getWhiteMove()	      const		{ return isWhite;			}

   
	// Simple setters
   void complete(const Board & board);
   void setSrc(const Position & pos)   { this->source = pos;            }
   void setDest(const Position & pos)  { this->destination = pos;       }
   void setChar(char c)                { this->piece = c;               }
   void setCapture(char c)             { this->capture = tolower(c);    }
	void setEnPassant()	               { this->enpassant = true;	      }
	void setCastleK(bool isKing)			{ this->castleK = isKing;			}
	void setCastleQ(bool castleQ)			{ this->castleQ = castleQ;			}
	void setWhiteMove(bool isWhite)		{ this->isWhite = isWhite;			}
   void setPromote(char letter)        { this->piece = letter;          }
   void setCastle(bool isKing)
   {
      if (isKing)
         this->castleK = true;
      else
         this->castleQ = true;
   };
   
   // Operators
   bool operator == (const Move & rhs)    const;
   bool operator == (const string & rhs)  const { return getText() == rhs; }
   bool operator != (const string & rhs)  const { return getText() != rhs; }
   bool operator != (const Move & rhs)    const { return !(*this == rhs);  }
   bool operator  < (const Move & rhs) const
   {
      return destination.getLocation() < rhs.destination.getLocation();
      
   }

	// for file I/O though only file input is currently implemented
	friend ostream& operator >> (ostream& in,  Move& rhs);
	friend ostream& operator << (ostream& out, Move& rhs);
   
   const Move & operator = (const Move & rhs);
   const Move & operator = (const string & s)
   {
      read(s);
      return *this;
   }
   const Move & operator = (const char *s)
   {
      const string str(s);
      read(str);
      return *this;
   }
	
};
