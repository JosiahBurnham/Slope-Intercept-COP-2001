/**--------------------------------------------------------
file: line.h
by:   J.Burnham
org:  COP 2001, 10410
desc: main configuration header for line class object.
-----------------------------------------------------------
*/

#ifndef LINE_H

#define LINE_H

#include "point.h"

class Line
{
public:
	//constructors
	Line();
	Line(Point point1, Point point2);
	Line(Point point, float slope);

	// accessors
	// getters 
	Point getFirstPoint();
	Point getSecondPoint();
	float getFirstPtX();
	float getFirstPtY();
	float getSecondPtX();
	float getSecondPtY();
	float getSlope();
	
	// setters
	void setFirstPoint(Point value);
	void setSecondPoint(Point value);
	void setFirstPtX(float value);
	void setFirstPtY(float value);
	void setSecondPtX(float value);
	void setSecondPtY(float value);
	void setSlope(float value);

	//member methods
	float diffX();
	float diffY();
	float calcSlope();
	float calcIntercept();
	float calcLineLength();
	float calcLineAngle();
private:
	Point firstPoint;
	Point secondPoint;
	float slope;

private:

};



#endif // LINE_H

