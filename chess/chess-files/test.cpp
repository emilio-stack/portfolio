/***********************************************************************
 * Source File:
 *    test.cpp
 * Author:
 *    Emilio Regino, Bradley Payne & Penelope Sanchez
 * Summary:
 *    This will run the testRunner function that runs through the
 *    test cases in the TestPosition and TestMove classes.
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testMove.h"
#include "PieceTest.h"
#include <iostream>

/************************************************
 * TEST RUNNER
 * A function to run all of the test suites for
 * chess
 ************************************************/
void testRunner()
{
   std :: cout << "--------------------------\n";
   std :: cout << "RUNNING TEST SUITES:   \n";
   TestPosition().run();
   TestMove().run();
//   PieceTest().run();
   std :: cout << "ALL TEST SUITES PASSED!\n";
   std :: cout << "--------------------------\n";
}
