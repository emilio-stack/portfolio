/***********************************************************************
 * Source File:
 *    Star: represents a star in the simulator
 * Author:
 *    Emilio Regino
 * Summary:
 *    Handles creating the stars within specified boundary points
 *    handles updating the star phase, handles drawing the star.
 ************************************************************************/

#pragma once

#include <stdio.h>
#include <cassert>
#include "point.h"
#include "uiDraw.h"  // for ogstream

using namespace std;

/**************************************************
 * STAR
 * Keeps track of where the star is, and what its
 * phase is. Phase makes it twinkle.
 *************************************************/
class Star
{
public:
   // constructor
   Star();
   Star(const Point& ptBoundary);

   // drawers
   void draw(ogstream& gout);
   
private:
   Point position;
   unsigned char phase;
};
