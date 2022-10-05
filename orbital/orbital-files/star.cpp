/***********************************************************************
 * Source File:
 *    Star: represents a star in the simulator
 * Author:
 *    Emilio Regino
 * Summary:
 *    Handles creating the stars within specified boundary points
 *    handles updating the star phase, handles drawing the star.
 ************************************************************************/

#include "star.h"      // for the Star class definition

/*************************************************************************
 * STAR
 * The default constructor for the star class.
 * Position x is set to 0.0.
 * Posiition y is set to 0.0.
 * Phase is set to 0.
 *************************************************************************/
Star :: Star()
{
   position.setMetersX(0.0);
   position.setMetersY(0.0);
   phase = 0;
}

/*************************************************************************
 * STAR(PTBOUNDARY)
 * The preferred constructor for the star class.
 * Position x is set to randomized coordinate between 0 and the
 * specified boundry x.
 * min and max height are set to be a percent of the max height of
 * the screen.
 * Posiition y is set to randomized coordinate between min height
 * and max height.
 *************************************************************************/
Star :: Star(const Position& ptBoundary)
{   
   position.setMetersX(random(-ptBoundary.getMetersX(), ptBoundary.getMetersX()));
   position.setMetersY(random(-ptBoundary.getMetersY(), ptBoundary.getMetersY()));
   phase = random(0, 255);
}

/*************************************************************************
 * DRAW
 * A method to draw the star
 *************************************************************************/
void Star :: draw()
{
   drawStar(position, phase++);
}
