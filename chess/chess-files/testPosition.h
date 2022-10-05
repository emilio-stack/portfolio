/***********************************************************************
 * Header File:
 *    Test position : Test the class position
 * Author:
 *    Emilio Regino, Bradley Payne & Penelope Sanchez
 * Summary:
 *    All the unit tests for position
 ************************************************************************/

#ifndef testPosition_h
#define testPosition_h
#include "position.h"
#include <cassert>
#include <iostream>

/****************************************************
 * TEST POSITION
 * The test suite for the position class
 ****************************************************/
class TestPosition
{
public:

	// A method to run the test suite
	void run()
	{
      std :: cout << "Testing Position: ";
		test_getLocation_firstHalf();
		test_getLocation_secondHalf();
		test_getRow_firstHalf();
		test_getRow_secondHalf();
		test_getRow_middle();
		test_getColumn_bottomLeft();
		test_getColumn_bottomRight();
		test_getColumn_upperLeft();
		test_getColumn_upperRight();
		test_isValid_onLower();
		test_isValid_pastLower();
		test_isValid_onUpper();
		test_isValid_pastUpper();
		test_isValid_middle();
		test_setRow_up();
		test_setRow_down();
		test_setCol_right();
		test_setCol_left();
		test_set_up();
		test_set_upLeft();
		test_set_upRight();
		test_set_left();
		test_set_right();
		test_set_down();
		test_set_downLeft();
		test_set_downRight();
		test_adjustRow_up();
		test_adjustRow_down();
		test_adjustCol_left();
		test_adjustCol_right();
      std :: cout << "Passed!\n";
	}

	// Test the getLocation method on the first half of the board
	void test_getLocation_firstHalf()
	{
		// Setup
		Position pos;
		pos.location = 0;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int value;

		// Exercise
		value = pos.getLocation();

		// Verify
		assert(value == 0);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test the getLocation method on the second half of the board
	void test_getLocation_secondHalf()
	{
		// Setup
		Position pos;
		pos.location = 63;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int value;

		// Exercise
		value = pos.getLocation();

		// Verify
		assert(value == 63);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test getRow on the first half of the board
	void test_getRow_firstHalf()
	{
		// Setup
		Position pos;
		pos.location = 1;
		pos.squareWidth = 100.0;
		pos.squareHeight = 100.0;
		int value;

		// Exercise
		value = pos.getRow();

		// Verify
		assert(value == 0);
		assert(pos.location == 1);
		assert(pos.squareWidth == 100.0);
		assert(pos.squareHeight == 100.0);
	} // Teardown

	// Test getRow on the second half of the board
	void test_getRow_secondHalf()
	{
		// Setup
		Position pos;
		pos.location = 63;
		pos.squareWidth = 100.0;
		pos.squareHeight = 100.0;
		int value;

		// Exercise
		value = pos.getRow();

		// Verify
		assert(value == 7);
		assert(pos.location == 63);
		assert(pos.squareWidth == 100.0);
		assert(pos.squareHeight == 100.0);
	} // Teardown

	// Test getRow on the middle of the board
	void test_getRow_middle()
	{
		// Setup
		Position pos;
		pos.location = 31;
		pos.squareWidth = 100.0;
		pos.squareHeight = 100.0;
		int value;

		// Exercise
		value = pos.getRow();

		// Verify
		assert(value == 3);
		assert(pos.location == 31);
		assert(pos.squareWidth == 100.0);
		assert(pos.squareHeight == 100.0);
	} // Teardown

	// Test getColumn on the bottom right of the board
	void test_getColumn_bottomRight()
	{
		// Setup
		Position pos;
		pos.location = 0;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int value;

		// Exercise
		value = pos.getCol();

		// Verify
		assert(value == 0);
		assert(pos.location == 0);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test getColumn on the bottom left of the board
	void test_getColumn_bottomLeft()
	{
		// Setup
		Position pos;
		pos.location = 7;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int value;

		// Exercise
		value = pos.getCol();

		// Verify
		assert(value == 7);
		assert(pos.location == 7);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test getColumn on the upper right of the board
	void test_getColumn_upperRight()
	{
		// Setup
		Position pos;
		pos.location = 56;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int value;

		// Exercise
		value = pos.getCol();

		// Verify
		assert(value == 0);
		assert(pos.location == 56);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test getColumn on the upper left of the board
	void test_getColumn_upperLeft()
	{
		// Setup
		Position pos;
		pos.location = 63;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int value;

		// Exercise
		value = pos.getCol();

		// Verify
		assert(value == 7);
		assert(pos.location == 63);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	

	// Test isValid on lower boundry
	void test_isValid_onLower()
	{
		// Setup
		Position pos;
		pos.location = 0;
		pos.squareWidth = -1.0;
		pos.squareHeight = -1.0;
		bool value;

		// Exercise
		value = pos.isValid();

		// Verify
		assert(value == true);
		assert(pos.location == 0);
		assert(pos.squareWidth == -1.0);
		assert(pos.squareHeight == -1.0);
	} // Teardown

	// Test isValid past lower boundry
	void test_isValid_pastLower()
	{
		// Setup
		Position pos;
		pos.location = -1;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		bool value;

		// Exercise
		value = pos.isValid();

		// Verify
		assert(value == false);
		assert(pos.location == -1);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test isValid on upper boundry
	void test_isValid_onUpper()
	{
		// Setup
		Position pos;
		pos.location = 63;
		pos.squareWidth = -1.0;
		pos.squareHeight = -1.0;
		bool value;

		// Exercise
		value = pos.isValid();

		// Verify
		assert(value == true);
		assert(pos.location == 63);
		assert(pos.squareWidth == -1.0);
		assert(pos.squareHeight == -1.0);
	} // Teardown

	// Test isValid past upper boundry
	void test_isValid_pastUpper()
	{
		// Setup
		Position pos;
		pos.location = 64;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		bool value;

		// Exercise
		value = pos.isValid();

		// Verify
		assert(value == false);
		assert(pos.location == 64);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test isValid on middle of board
	void test_isValid_middle()
	{
		// Setup
		Position pos;
		pos.location = 31;
		pos.squareWidth = -1.0;
		pos.squareHeight = -1.0;
		bool value;

		// Exercise
		value = pos.isValid();

		// Verify
		assert(value == true);
		assert(pos.location == 31);
		assert(pos.squareWidth == -1.0);
		assert(pos.squareHeight == -1.0);
	} // Teardown

	// Test setRow : move up one row
	void test_setRow_up()
	{
		// Setup
		Position pos;
		pos.location = 31;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 4;

		// Exercise
		pos.setRow(row);

		// Verify
		assert(pos.location == 39);
		assert(pos.getRow() == 4);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test setRow : move down one row
	void test_setRow_down()
	{
		// Setup
		Position pos;
		pos.location = 31;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 2;

		// Exercise
		pos.setRow(row);

		// Verify
		assert(pos.location == 23);
		assert(pos.getRow() == 2);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test setCol : move left one column
	void test_setCol_left()
	{
		// Setup
		Position pos;
		pos.location = 11;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int col = 4;

		// Exercise
		pos.setCol(col);

		// Verify
		assert(pos.location == 12);
		assert(pos.getCol() == 4);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test setCol : move right one column
	void test_setCol_right()
	{
		// Setup
		Position pos;
		pos.location = 11;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int col = 2;

		// Exercise
		pos.setCol(col);

		// Verify
		assert(pos.location == 10);
		assert(pos.getCol() == 2);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test set : up
	void test_set_up()
	{
		// Setup
		Position pos;
		pos.location = 19;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 3;
		int col = 3;

		// Exercise
		pos.set(row, col);

		// Verify
		assert(pos.location == 27);
		assert(pos.getCol() == 3);
		assert(pos.getRow() == 3);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test set : up left
	void test_set_upLeft()
	{
		// Setup
		Position pos;
		pos.location = 19;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 3;
		int col = 4;

		// Exercise
		pos.set(row, col);

		// Verify
		assert(pos.location == 28);
		assert(pos.getCol() == 4);
		assert(pos.getRow() == 3);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test set : up right
	void test_set_upRight()
	{
		// Setup
		Position pos;
		pos.location = 19;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 3;
		int col = 2;

		// Exercise
		pos.set(row, col);

		// Verify
		assert(pos.location == 26);
		assert(pos.getCol() == 2);
		assert(pos.getRow() == 3);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test set : left
	void test_set_left()
	{
		// Setup
		Position pos;
		pos.location = 19;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 2;
		int col = 4;

		// Exercise
		pos.set(row, col);

		// Verify
		assert(pos.location == 20);
		assert(pos.getCol() == 4);
		assert(pos.getRow() == 2);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test set : right
	void test_set_right()
	{
		// Setup
		Position pos;
		pos.location = 19;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 2;
		int col = 2;

		// Exercise
		pos.set(row, col);

		// Verify
		assert(pos.location == 18);
		assert(pos.getCol() == 2);
		assert(pos.getRow() == 2);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test set : down
	void test_set_down()
	{
		// Setup
		Position pos;
		pos.location = 19;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 1;
		int col = 3;

		// Exercise
		pos.set(row, col);

		// Verify
		assert(pos.location == 11);
		assert(pos.getCol() == 3);
		assert(pos.getRow() == 1);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test set : down left
	void test_set_downLeft()
	{
		// Setup
		Position pos;
		pos.location = 19;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 1;
		int col = 4;

		// Exercise
		pos.set(row, col);

		// Verify
		assert(pos.location == 12);
		assert(pos.getCol() == 4);
		assert(pos.getRow() == 1);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test set : down right
	void test_set_downRight()
	{
		// Setup
		Position pos;
		pos.location = 19;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int row = 1;
		int col = 2;

		// Exercise
		pos.set(row, col);

		// Verify
		assert(pos.location == 10);
		assert(pos.getCol() == 2);
		assert(pos.getRow() == 1);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test adjust row : up
	void test_adjustRow_up()
	{
		// Setup
		Position pos;
		pos.location = 11;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int dRow = 2;

		// Exercise
		pos.adjustRow(dRow);

		// Verify
		assert(pos.location == 27);
		assert(pos.getRow() == 3);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test adjust row : down
	void test_adjustRow_down()
	{
		// Setup
		Position pos;
		pos.location = 27;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int dRow = -2;

		// Exercise
		pos.adjustRow(dRow);

		// Verify
		assert(pos.location == 11);
		assert(pos.getRow() == 1);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test adjust col : left
	void test_adjustCol_left()
	{
		// Setup
		Position pos;
		pos.location = 11;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int dCol = 3;

		// Exercise
		pos.adjustCol(dCol);

		// Verify
		assert(pos.location == 14);
		assert(pos.getCol() == 6);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown

	// Test adjust col : right
	void test_adjustCol_right()
	{
		// Setup
		Position pos;
		pos.location = 11;
		pos.squareWidth = 1.0;
		pos.squareHeight = 1.0;
		int dCol = -3;

		// Exercise
		pos.adjustCol(dCol);

		// Verify
		assert(pos.location == 8);
		assert(pos.getCol() == 0);
		assert(pos.squareWidth == 1.0);
		assert(pos.squareHeight == 1.0);
	} // Teardown
};

#endif /* testPosition_h */
