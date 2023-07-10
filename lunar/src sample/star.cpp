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
#include "random.h"    // for random()

/*************************************************************************
 * STAR
 * The default constructor for the star class.
 * Position x is set to 0.0.
 * Posiition y is set to 0.0.
 * Phase is set to 0.
 *************************************************************************/
Star :: Star()
{
   position.setX(0.0);
   position.setY(0.0);
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
Star :: Star(const Point& ptBoundary)
{
   int maxHeight = ptBoundary.getY() * 0.95;   // The max height a star can have is 95% of the height of the screen
   int minHeight = ptBoundary.getY() * 0.50;   // The min height a star can have is 50% of the height of the screen
   
   position.setX(random(0.0, ptBoundary.getX()));
   position.setY(random(minHeight, maxHeight));
   phase = random(0, 255);
}

/*************************************************************************
 * DRAW
 * A method to draw the star
 *************************************************************************/
void Star :: draw(ogstream& gout)
{
   gout.drawStar(position, phase++);
}
