/***********************************************************************
 * Header File:
 *    Piece: The piece class
 * Author:
 *    Emilio Regino, Bradley Payne, Penelope Sanchez, Brother
 *    Helfrich
 * Summary:
 *    A class to represent the a piece in the game of chess.
 *    PAWN, KNIGHT, ROOK, BISHOP, KING, QUEEN, SPACE
 *    all inherit from PIECE.
 ************************************************************************/

#include "piece.h"
#include "board.h"

/***********************************************************************
 * PAWN : ADD PROMOTION
 * Add pawn promotion to a queen
 ***********************************************************************/
void Pawn::addPromotion(set<Move> &moves, Move &move) const
{
   move.setPromote('Q');
   moves.insert(move);
}

/***********************************************************************
 * PAWN : GET MOVES
 ***********************************************************************/
void Pawn::getMoves(set<Move> &moves, const Board &board) const
{
   // The pawn can move forward if
   // 1. there is no piece directly in front of it
   // 2. we are not at the end of the pawn run
   {
      // position i am moving the piece into. sorta like move.dest
      Position posMove(getPosition(), isWhite() ? ADD_R : SUB_R);
      
      if (posMove.isValid() &&
          board[posMove] == ' ')
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         
         // do promotion also if we are at the front rank...
         if (posMove.getRow() == (isWhite() ? 7 : 0))
            addPromotion(moves, move);
         // otherwiese, just a standard movement
         else
            moves.insert(move);
      }
   }
   
   // The pawn can do a double move forward if:
   // 1. we have not yet moved
   // 2. the space before is empty
   // 3. the space two spots before is empty
   if (!isMoved())
   {
      assert(position.getRow() == (isWhite() ? 1 : 6));
      Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
      Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());
      
      if (board[posMove] == ' ' && board[posCheck] == ' ')
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         moves.insert(move);
      }
   }
   
   // The pawn can attack if:
   // 1. there is an enemy piece to the right or left
   // 2. we are not at the back rank
   // 3. we are not on the right most column
   const int cDelta[] = { 1, -1};  // right and left
   for (int i = 0; i < 2; i++)  // right and left attack
   {
      Position posMove(position.getRow() + (isWhite() ? 1 : -1),
                       position.getCol() + cDelta[i]);
      if (posMove.isValid() &&                     // valid position
          board[posMove] != ' ' &&                 // cannot be a space
          board[posMove].isWhite() != isWhite())   // must be a different team
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(board[posMove].getLetter());
         
         // do promotion also if we are at the front rank...
         if (posMove.getRow() == (isWhite() ? 7 : 0))
            addPromotion(moves, move);
         // otherwiese, just a standard movement
         else
            moves.insert(move);
      }
   }
   
   // The pawn can perform an enpassant if:
   // 1. the pawn is on the correct row (4 or 2 for white/black)
   // 2. the pawn to be attacked is beside
   // 3. the spot to move into is empty
   // 4. the pawn beside us has only moved once
   // 5. the pawm beside us has just moved
   for (int i = 0; i < 2; i++)
   {
      Position posMove(position.getRow() + (isWhite() ? 1 : -1),
                       position.getCol() + cDelta[i]);
      Position posKill(position.getRow(),
                       position.getCol() + cDelta[i]);
      
      if (posMove.isValid() &&
          position.getRow() == (isWhite() ? 4 : 3) &&
          board[posMove] == ' ' &&
          board[posKill] == 'p' &&
          board[posKill].isWhite() != isWhite() &&
          board[posKill].justMoved(board.getCurrentMove()))
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(board[posMove].getLetter());
         move.setEnPassant();
         moves.insert(move);
      }
   }
}

/***********************************************************************
 * ROOK : GET MOVES
 ***********************************************************************/
void Rook:: getMoves(set<Move> &moves, const Board &board) const
{
   const Delta delta [] =
   {
            {0,  1},
      {-1,0},      {1,0},
            {0, -1}
   };
   moves = getMovesSlide(board, delta, sizeof(delta) / sizeof(delta[0]));
}

/***********************************************************************
 * KNIGHT : GET MOVES
 ***********************************************************************/
void Knight::getMoves(set<Move> &moves, const Board &board) const
{
   const Delta delta [] =
   {
               {-1,  2}, { 1,  2},
      {-2,  1},                    { 2,  1},
      {-2, -1},                    { 2, -1},
               {-1, -2}, { 1, -2}
   };
   moves = getMovesNoslide(board, delta, sizeof(delta) / sizeof(delta[0]));
}

/***********************************************************************
 * BISHOP : GET MOVES
 ***********************************************************************/
void Bishop :: getMoves(set<Move> &moves, const Board &board) const
{
   const Delta delta[] =
   {
      {-1,  1}, {1,  1},
      {-1, -1}, {1, -1}
   };

   moves = getMovesSlide(board, delta, sizeof(delta) / sizeof(delta[0]));
}

/***********************************************************************
 * QUEEN : GET MOVES
 ***********************************************************************/
void Queen::getMoves(set<Move> &moves, const Board &board) const
{
   const Delta delta [] =
   {
      {-1,  1}, {0,  1}, {1,  1},
      {-1,  0},          {1,  0},
      {-1, -1}, {0, -1}, {1, -1}
   };
   moves = getMovesSlide(board, delta, sizeof(delta) / sizeof(delta[0]));
}

/***********************************************************************
 * KING : ADD CASTLE 
 ***********************************************************************/
void King::addCastle(set <Move> & moves, Move & move, bool isKing) const
{
   move.setWhiteMove(isWhite());
   move.setCastle(isKing);
   moves.insert(move);
}

/***********************************************************************
 * KING : GET MOVES
 ***********************************************************************/
void King::getMoves(set<Move> &moves, const Board &board) const
{
   const Delta delta[] =
   {
      {-1,  1}, {0,  1}, {1,  1},
      {-1,  0},          {1,  0},
      {-1, -1}, {0, -1}, {1, -1}
   };
   moves = getMovesNoslide(board, delta, sizeof(delta) / sizeof(delta[0]));
   
   // check for kingside castle
   if (!isMoved())
   {
      Position posSpace(position.getRow(), 5);
      Position posMove (position.getRow(), 6);
      Position posRook (position.getRow(), 7);
      
      if ( board[posMove]  == ' ' &&
           board[posSpace] == ' ' &&
           board[posRook]  == 'r' &&
           board[posRook].isMoved() == false)
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCastle(true);
         moves.insert(move);
//         addCastle(moves, move, true /* isKing */);
      }
   }
   
   // check for queenside castle
   if (!isMoved())
   {
      Position posSpace1(position.getRow(), 3);
      Position posMove  (position.getRow(), 2);
      Position posSpace2(position.getRow(), 1);
      Position posRook  (position.getRow(), 0);
      
      if ( board[posMove]   == ' ' &&
           board[posSpace1] == ' ' &&
           board[posSpace2] == ' ' &&
           board[posRook]   == 'r' &&
           board[posRook].isMoved() == false)
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         addCastle(moves, move, false /* isKing */);
      }
   }
}

/***********************************************************************
 * PIECE: GET MOVES SLIDE
 * A method to get all the possible moves for any piece that
 * slides
 ***********************************************************************/
set <Move> Piece::getMovesSlide(const Board& board, const Delta deltas[], int numDelta) const
{
   set <Move> possibleMoves;
   for (int i = 0; i < numDelta; i++)
   {
      Position posMove(position, deltas[i]);
      
      while (posMove.isValid() && board[posMove].getLetter() == ' ') {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         possibleMoves.insert(move);
         posMove += deltas[i];
      }
      
      if (posMove.isValid() &&
          (board[posMove].isWhite() != fWhite || board[posMove].getLetter() == ' '))
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         if (board[posMove].getLetter() != ' ')
         {
            move.setCapture(board[posMove].getLetter());
         }
         possibleMoves.insert(move);
      }
   }
   return possibleMoves;
}

/***********************************************************************
 * PIECE: GET MOVES NO SLIDE
 * A method to get all the possible moves for any piece that
 * does not slide
 ***********************************************************************/
set <Move> Piece::getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const
{
   set <Move> possibleMoves;
   for (int i = 0; i < numDelta; i++)
   {
      Position posMove(position, deltas[i]);
      
      if (posMove.isValid() &&
          (board[posMove].isWhite() != fWhite || board[posMove].getLetter() == ' '))
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         if (board[posMove].getLetter() != ' ')
         {
            move.setCapture(board[posMove].getLetter());
         }
         possibleMoves.insert(move);
      }
   }
   return possibleMoves;
}
