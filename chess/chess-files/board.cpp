/***********************************************************************
 * Source File:
 *    Board: Represents the game board for chess
 * Author:
 *    Emilio Regino, Penelope Sanchez
 * Summary:
 *    The Board class provides the client all the functionality to
 *    play a game of chess. It is a collection of pieces and a
 *    small amount of game state.
 ************************************************************************/

#include "board.h"
#include <cassert>
using namespace std;

/***********************************************************************
 * BOARD   :   DISPLAY
 *          Display the board
 ************************************************************************/
void Board :: display(const Position &posHover, const Position &posSelect) const
{
   // draw the base board
   pgout->drawBoard();
   
   // draw the hover and select stuff
   pgout->drawHover(posHover.getLocation());
   pgout->drawSelected(posSelect.getLocation());
   
   // draw the possible moves
   if (posSelect.isValid())
   {
      set <Move> possible;  // The set of possible moves
      board[posSelect.getRow()][posSelect.getCol()]->getMoves(possible, *this);
      set <Move> :: iterator it;
      for (it = possible.begin(); it != possible.end(); it++)
      {
         pgout->drawPossible(it->getDes().getLocation());
      }
   }
   
   // draw pieces
   for (int r = 0; r <= 7; r++)
      for (int c = 0; c <= 7; c++)
         board[r][c]->display(pgout);
}

/***********************************************************************
 * BOARD   :   RESET
 *          Fill the board with the known pieces
 ************************************************************************/
void Board :: reset(bool fFree)
{
   // free up allocated memory if commanded to
   if (fFree)
      free();
   
   // middle of the board
   for (int r = 2; r <= 5; r++)
      for (int c = 0; c <= 7; c++ )
         board[r][c] = new Space(r, c);
   
   
   // pawns
   for (int c = 0; c <= 7; c++)
   {
      board[1][c] = new Pawn(1, c, true  /* isWhite */);
      board[6][c] = new Pawn(6, c, false /* isWhite */);
   }
   
   // White
   board[0][0] = new Rook  (0, 0, true /* isWhite */);
   board[0][1] = new Knight(0, 1, true /* isWhite */);
   board[0][2] = new Bishop(0, 2, true /* isWhite */);
   board[0][3] = new Queen (0, 3, true /* isWhite */);
   board[0][4] = new King  (0, 4, true /* isWhite */);
   board[0][5] = new Bishop(0, 5, true /* isWhite */);
   board[0][6] = new Knight(0, 6, true /* isWhite */);
   board[0][7] = new Rook  (0, 7, true /* isWhite */);
   
   
   // Black
   board[7][0] = new Rook  (7, 0, false /* isWhite */);
   board[7][1] = new Knight(7, 1, false /* isWhite */);
   board[7][2] = new Bishop(7, 2, false /* isWhite */);
   board[7][3] = new Queen (7, 3, false /* isWhite */);
   board[7][4] = new King  (7, 4, false /* isWhite */);
   board[7][5] = new Bishop(7, 5, false /* isWhite */);
   board[7][6] = new Knight(7, 6, false /* isWhite */);
   board[7][7] = new Rook  (7, 7, false /* isWhite */);

   // reset the moves
   currentMove = 0;
   assertBoard();
}

/***********************************************************************
 * BOARD   :   FREE
 *          Free up all the allocated memory
 ************************************************************************/
void Board :: free()
{
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         delete board[r][c];
}

/***********************************************************************
 * BOARD   :   -=
 *          Delete a piece at a given position
 * ARGS     :   pos
 *          The position to delete
 ************************************************************************/
void Board :: operator -= (const Position & pos)
{
   if (pos.isInvalid())
      return;
   
   delete board[pos.getRow()][pos.getCol()];
   board[pos.getRow()][pos.getCol()] = new Space(pos.getRow(), pos.getCol());
}

/***********************************************************************
 * BOARD   :   REMOVE
 *          Delete a piece at a given position AND do not
 *          allocate a space
 * ARGS     :   pos
 *          The position to delete
 ************************************************************************/
void Board :: remove(const Position & pos)
{
   if (pos.isInvalid())
      return;
   
   delete board[pos.getRow()][pos.getCol()];
   board[pos.getRow()][pos.getCol()] = NULL;
}

/***********************************************************************
 * BOARD   :   ASSIGN
 *          Assign a new piece to the board
 * ARGS     :   rhs
 *          The new piece to assign to the position
 ************************************************************************/
const Piece * Board :: operator = (Piece * rhs)
{
   delete board[rhs->getPosition().getRow()][rhs->getPosition().getCol()];
   board[rhs->getPosition().getRow()][rhs->getPosition().getCol()] = rhs;
   return rhs;
}

/***********************************************************************
 * BOARD   :   UNDO
 *          Back up one move. This is done by fetching the
 *          last move off the move list and executing it
 *          backwards.
 * ARGS     :   move
 *          The move to undo.
 ************************************************************************/
void Board :: operator -= (const Move & move)
{
   Position src = move.getSrc();
   Position des = move.getDes();
   
   // castle the king side
   if (move.getCastleK())
      assert(false);
   
   // castle queen side
   else if (move.getCastleQ())
      assert(false);
   
   // en-passant
   else if (move.getEnPassant())
      assert(false);
   
   // promotion
   else if (move.getPromotion() != PIECE_EMPTY)
      assert(false);
   
   // capture?
   else if (move.getCapture() != PIECE_EMPTY)
      assert(false);
   
   // standard move
   else
      swap(src, des);
}

/***********************************************************************
 * BOARD   :   ASSERT BOARD
 *          Verify the board is well formed
 ************************************************************************/
void Board :: assertBoard()
{
#ifndef NDEBUG
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
      {
         Position pos = board[r][c]->getPosition();
         assert(pos.getRow() == r);
         assert(pos.getCol() == c);
      }
   assert(currentMove >= 0);
   
#endif // NDEBUG
}

/***********************************************************************
 * BOARD   :   SWAP BOARD
 *          Swap two pieces on the board
 ************************************************************************/
void Board :: swap(const Position &pos1, const Position &pos2)
{
   assertBoard();
   assert(pos1.isValid());
   assert(pos2.isValid());
   
   // perform the swap from the board's perspective
   Piece *p = board[pos1.getRow()][pos1.getCol()];
   board[pos1.getRow()][pos1.getCol()] = board[pos2.getRow()][pos2.getCol()];
   board[pos2.getRow()][pos2.getCol()] = p;
   
   // update the position of the piece so the piece is where
   // it thinks it is. Otherwise, it is lost!
   (*this)[pos1] = pos1;
   (*this)[pos2] = pos2;
   
   // mark that this piece has moved
   (*this)[pos1].setLastMove(currentMove);
   (*this)[pos2].setLastMove(currentMove);
   
   // make sure everything worked correctly
   assertBoard();
}

/***********************************************************************
 * BOARD   :   MOVE
 *          Execute a move according to the contained
 *          instructions.
 ************************************************************************/
void Board :: move(const Move &move)
{
   Position src = move.getSrc();
   Position des = move.getDes();
   assert(board[src.getRow()][src.getCol()]->getLetter() != ' ' );
   assert(src.isValid());
   assert(des.isValid());
   
   // Castle King side
   if (move.getCastleK())
   {
      int row = (move.getWhiteMove() ? 0 : 7);
      
      // king and rook better be in his position
      assert(board[row][4]->getLetter() == 'k');
      assert(board[row][5]->getLetter() == ' ');
      assert(board[row][6]->getLetter() == ' ');
      assert(board[row][7]->getLetter() == 'r');
      
      // move the king
      src.set(row, 6);
      des.set(row, 4);
      swap(src, des);
      
      // move the rook
      src.set(row, 5);
      des.set(row, 7);
      swap(src, des);
   }
   
   // Castle Queen side
   else if (move.getCastleQ())
   {
      int row = (move.getWhiteMove() ? 0 : 7);
      
      // king and rook better be in his position
      assert(board[row][4]->getLetter() == 'k');
      assert(board[row][3]->getLetter() == ' ');
      assert(board[row][2]->getLetter() == ' ');
      assert(board[row][1]->getLetter() == ' ');
      assert(board[row][0]->getLetter() == 'r');
      
      // move the king
      src.set(row, 2);
      des.set(row, 4);
      swap(src, des);
      
      // move the rook
      src.set(row, 3);
      des.set(row, 0);
      swap(src, des);
   }
   
   else if (move.getEnPassant())
   {
      // target location of the pawn better be empty
      // the piece beside the pawn better be filled with a pawn
      assert(board[des.getRow()][des.getCol()]->getLetter() == ' ');
      assert(board[src.getRow()][src.getCol()]->getLetter() == 'p');
      assert(board[src.getRow()][des.getCol()]->getLetter() == 'p');
      
      // move the pawn
      swap(src, des);
      
      // kill the oponent
      Position posKill(src.getRow(), des.getCol());
      *this -= posKill;
   }
   
   // promotion?
   else if (move.getPromotion() != PIECE_EMPTY)
   {
      assert(board[src.getRow()][src.getCol()]->getLetter() == 'p');
      assert(move.getPromotion() == 'Q' || move.getPromotion() == 'R' ||
             move.getPromotion() == 'B' || move.getPromotion() == 'N');
      *this -= src;
      remove(des);
      assert(board[des.getRow()][des.getCol()] == NULL);
      switch (move.getPromotion())
      {
         case 'Q':
            *this = new Queen (des.getRow(), des.getCol(), move.getWhiteMove());
            break;
         case 'R':
            *this = new Rook  (des.getRow(), des.getCol(), move.getWhiteMove());
            break;
         case 'B':
            *this = new Bishop(des.getRow(), des.getCol(), move.getWhiteMove());
            break;
         case 'N':
            *this = new Knight(des.getRow(), des.getCol(), move.getWhiteMove());
            break;
         default:
            *this = new Pawn  (des.getRow(), des.getCol(), move.getWhiteMove());
            assert(false);
      }
      assert(board[des.getRow()][des.getCol()] != NULL);
   }
   
   // capture?
   else if (move.getCapture() != PIECE_EMPTY)
   {
      assert(board[des.getRow()][des.getCol()]->getLetter() != ' ');
      assert(board[src.getRow()][src.getCol()]->getLetter() != ' ');
      assert(board[src.getRow()][src.getCol()]->isWhite() ==
             move.getWhiteMove());
      assert(board[des.getRow()][des.getCol()]->isWhite() !=
             move.getWhiteMove());
      
      // delete the piece
      *this -= des;
      
      // swap the piece
      swap(src, des);
   }
   
   // otherwise, a normal piecemove
   else
   {
      assert(board[des.getRow()][des.getCol()]->getLetter() == ' ');
      assert(board[src.getRow()][src.getCol()]->getLetter() != ' ');
      assert(board[src.getRow()][src.getCol()]->isWhite() ==
             move.getWhiteMove());
      
      // swap the piece
      swap(src, des);
   }
   
   assertBoard();
   // advance by one move
   currentMove++;

}
