/**--------------------------------------------------------
file: point.cpp
by:   J.Burnham
org:  COP 2001, 10410
desc: main implementation file for point class object.
-----------------------------------------------------------
*/

#include "point.h"

// constructors
//---------------------------------------------------------

/**
*default constructor - initialize empty point
*/
Point::Point()
{
	xCoordinate = 0.0;
	yCoordinate = 0.0;
}


/**
*properties  constructor - initialize to parameter values
*/
Point::Point(float xpos, float ypos)
{
	xCoordinate = xpos;
	yCoordinate = ypos;
}

//accessors
//-----------------------------------------------------------
// getters
float Point::getXCoor(){ return xCoordinate; }
float Point::getYCoor(){ return yCoordinate; }

// setters
void Point::setXCoor(float value){ xCoordinate = value; }
void Point::setYCoor(float value){ yCoordinate = value; }