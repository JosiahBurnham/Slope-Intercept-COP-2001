/**--------------------------------------------------------
file: slopeIntercept.h
by:   J.Burnham
org:  COP 2001, 10410
desc: main configuration header for slope intercept calcuation and visualization.
-----------------------------------------------------------
*/
#ifndef SLOPE_INTERCEPT_H
#define SLOPE_INTERCEPT_H

#include <string>

#include "fgcugl.h" // fgcu OpenGl library

// Global constants
//---------------------------------------------------------
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 400;
const std::string WINDOW_TITLE = "Graph of Line";

// calculator modes
enum Mode
{
	TWO_POINT = 1,
	POINT_SLOPE,
	EXIT
};

#endif // SLOPE_INTERCEPT_H
