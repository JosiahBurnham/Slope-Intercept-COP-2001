/**--------------------------------------------------------
file: line.cpp
by:   J.Burnham
org:  COP 2001, 10410
desc: main implementation file for line class object.
-----------------------------------------------------------
*/
#define	_USE_MATH_DEFINES	// enable M_PI
#include <math.h>			// sqrt, pow

#include "line.h"


//constructors
//---------------------------------------------------------
/**
*default constructor - initialize empty point
*/
Line::Line()
{
	firstPoint = Point();
	secondPoint = Point();
	slope = 0;

}


/**
*properties  constructor - initialize to parameter values
*/
Line::Line(Point point1, Point point2)
{
	firstPoint = point1;
	secondPoint = point2;
	slope = calcSlope();	// slope is not given in two-point form
}


/**
*properties  constructor - initialize to parameter values
*/
Line::Line(Point point, float slope)
{
	firstPoint = point;
	this->slope = slope;
	secondPoint = Point(0, calcIntercept()); // in point slope the second point is set to (0,y-int)
}

// accessors
//---------------------------------------------------------
// getters 
Point Line::getFirstPoint(){ return firstPoint; }
Point Line::getSecondPoint(){ return secondPoint; }
float Line::getFirstPtX(){ return firstPoint.getXCoor(); }
float Line::getFirstPtY(){ return firstPoint.getYCoor(); }
float Line::getSecondPtX(){ return secondPoint.getXCoor(); }
float Line::getSecondPtY(){ return secondPoint.getYCoor(); }
float Line::getSlope(){ return slope; }

// setters
void Line::setFirstPoint(Point value){ firstPoint = value; }
void Line::setSecondPoint(Point value){ secondPoint = value; }
void Line::setFirstPtX(float value){ firstPoint.setXCoor(value); }
void Line::setFirstPtY(float value){ firstPoint.setYCoor(value); }
void Line::setSecondPtX(float value){ secondPoint.setXCoor(value); }
void Line::setSecondPtY(float value){ secondPoint.setYCoor(value); }
void Line::setSlope(float value){ slope = value; }

//member methods
//---------------------------------------------------------
/**
* calculates the difference in the x-coordinates of two points
* 
* Parameters:
*	point1	- the first point
*	point2	- the second point
* Returns:
*	float	- the differenence in the x-coordinates of the points
*/
float Line::diffX(){ return  secondPoint.getXCoor() - firstPoint.getXCoor(); }


/**
* calculates the difference in the y-coordinates of two points
*
* Parameters:
*	point1	- the first point
*	point2	- the second point
* Returns:
*	float	- the differenence in the y-coordinates of the points
*/
float Line::diffY(){ return secondPoint.getYCoor() - firstPoint.getYCoor(); }


/**
*calcuates the slope of a line in the two-point form
*
* Parameters:
*	point1		- the first point
*	point2		- the second point
* Returns:
*	float		the slope of the two points
*/
float Line::calcSlope()
{
	return Line::diffY() / Line::diffX();
}


/**
*calcultes the y intercept of a line given a slope and a point
*
* Parameters:
*	point		a point on a line
*	slope		a slope of a line
* Returns:
*	float		the y-intercept of the line
*/
float Line::calcIntercept()
{
	float yIntercept = firstPoint.getYCoor() - (slope * firstPoint.getXCoor());
	return yIntercept;
}


/**
* calculates the length of a line
*
* Parameters:
*	point1		- the first point
*	point2		- the second point
* Returns:
*	float		-the length of the line
*/
float Line::calcLineLength()
{
	float length = sqrt(pow(diffX(), 2) + pow(diffY(), 2));
	return length;
}


/**
*calculates the angle of a line
*
* Parameters:
*	point1		- first point
*	point2		- second point
* Returns:
*	float		- the angle of the line passed
*/
float Line::calcLineAngle(){

	float radians = atan2(diffY(), diffX());
	float angle = radians * 180.0 / M_PI;		// relative to the x-axis
	float degrees = 90.0 - angle;				// rotate angle to the left 90 degrees
	float cardinal = (degrees > 0.0 ? degrees : degrees + 360.0);		// fix negative cardinal degrees

	return cardinal;
}