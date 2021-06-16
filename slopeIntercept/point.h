/**--------------------------------------------------------
file: point.h
by:   J.Burnham
org:  COP 2001, 10410
desc: main configuration header for point class object.
-----------------------------------------------------------
*/

#ifndef POINT_H
#define POINT_H

class Point
{
public:
	// constructors
	Point();
	Point(float xpos, float ypos);

	//accessors
	// getters
	float getXCoor();
	float getYCoor();

	// setters
	void setXCoor(float value);
	void setYCoor(float value);

private:
	//properties
	float xCoordinate;
	float yCoordinate;

 };

#endif // POINT_H
