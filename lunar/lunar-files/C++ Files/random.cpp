/***********************************************************************
 * Header File:
 *    Random: generates random numbers
 * Author:
 *    Bro. Helfrich
 * Summary:
 *    Just some helper functions to generate random numbers
 ************************************************************************/

#include "random.h"
#include <stdlib.h>   // rand
#include <cassert>    // asserts

/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int random(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}

/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the double
 ****************************************************************/
double random(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));

   assert(min <= num && num <= max);

   return num;
}
