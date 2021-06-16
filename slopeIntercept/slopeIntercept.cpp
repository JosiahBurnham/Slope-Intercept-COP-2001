/**--------------------------------------------------------
file: slopeIntercept.cpp
by:   J.Burnham
org:  COP 2001, 10410
desc: main application file for slope intercept calcuation and visualization.
-----------------------------------------------------------
*/

#include <iostream>			// console output library
#include <iomanip>			// setprecision


#include "fgcugl.h"		// OpenGL library
#include "slopeIntercept.h"	// main application header file
#include "line.h"

// fucntion prototypes
Mode getProblem();
Point getPoint();
void get2Point(Line& line);
void getPointSlope(Line& line);
void displayLine(Line line);
void display2Pt(Line line);
void displayPointSlope(Line line);
void displaySlopeIntercept(Line line);
void drawLine(Line line);


int main()
{
	Line line;
	Mode mode;

	do
	{
		mode = getProblem();
		if (mode != EXIT)
		{
			if (mode == TWO_POINT)
			{
				get2Point(line);		// sets the line object to two-point form
			}
			else if (mode == POINT_SLOPE)
			{
				getPointSlope(line);	// sets the line obejct to point-slope form
			}

			displayLine(line);			// display the line's properties

			if (mode == TWO_POINT)
			{
				display2Pt(line);			// display the two-point form of the line
			}
			else if (mode == POINT_SLOPE)
			{
				displayPointSlope(line);	// display the point-slope form of the line
			}

			displaySlopeIntercept(line);	// display the slope-intercept form of the line
			drawLine(line);			// graph the line
		}

	} while (mode != EXIT);

	return 0;
} // end main



//Input Functions
//---------------------------------------------------------

/**
* Gets the type of problem the user wants to solve
* either a point-slop problem, or a two-point problem
*
* Parameters:
* Returns:
* enum		the mode the user selected.
*/
Mode getProblem()
{
	int choice;

	std::cout << "\nSelect the form that you would like to convert to slope intercept form:" << std::endl;
	std::cout << "\t1) Two-point form (you know the two points of the line)" << std::endl;
	std::cout << "\t2) Point-slope form (you know the line's slope and one point)" << std::endl;
	std::cout << "\t3) exit" << std::endl;
	std::cout << "->";
	std::cin >> choice;


	Mode selectedMode = static_cast<Mode>(choice);

	return selectedMode;
} // end getProblem


/**
*gets the x and y coordinates for a point
*
* Parameters:
* Returns:
*Point		the point struct with x and y positions
*
*/
Point getPoint()
{
	float x, y;

	std::cout << "\nEnter X and Y coordinates separated by spaces: ";
	std::cin >> x >> y;

	Point point = Point(x, y);

	return point;
} // end getPoint


/**
* get the information for the two points in two-point form
*
* Parameters:
* Returns:
*/
void get2Point(Line& line)
{


	std::cout << "\nEnter First Point: " << std::endl;
	Point point1 = getPoint();

	std::cout << "\nEnter Second Point: " << std::endl;
	Point point2 = getPoint();

	line = Line(point1, point2);

	

} // end get2Point


/**
*Get the input for the point-slope form of the line
*
* Parameters:
*	line		the line structure that will be difined
*/
void getPointSlope(Line& line)
{
	std::cout << "\nEnter a point for the line: " << std::endl;
	Point point = getPoint();

	float slope;
	std::cout << "\nEnter the slope of the line: ";
	std::cin >> slope;

	line = Line(point, slope);
	

} // end getPointSlope



//Output Functions
//---------------------------------------------------------

/**
* Displays the properties of the line inputed
*
* Parameters:
*	line		the line that was calculated / inputted
* Returns:
*/
void displayLine(Line line)
{
	// dispaly line properties
	std::cout << std::setprecision(3) << "\nLine:" << std::endl;		// set percision to 3 to format like instructions
	std::cout << "\tPoint-1:  " << "(" << line.getFirstPtX() << ", " << line.getFirstPtY() << ")" << std::endl;
	std::cout << "\tPoint-2:  " << "(" << line.getSecondPtX() << ", " << line.getSecondPtY() << ")" << std::endl;
	std::cout << "\t   Slope = " << line.getSlope() << std::endl;
	std::cout << "\tY-Intcpt = " << line.calcIntercept() << std::endl;
	std::cout << "\t  Length = " << line.calcLineLength() << std::endl;
	std::cout << "\t   Angle = " << line.calcLineAngle() << std::endl;
}	// end displayLine


/**
* Displays the two-point form fo the line inputted
*
* Parameters:
*	line		the line that was calculated / inputted
* Returns:
*/
void display2Pt(Line line)
{
	std::cout << "\nTwo-point form:" << std::endl;
	std::cout << "\t\t" << "(" << line.getSecondPtY() << " - " << line.getFirstPtY() << ")" << std::endl;
	std::cout << "\tm = -------------------" << std::endl;
	std::cout << "\t\t" << "(" << line.getSecondPtX() << " - " << line.getFirstPtX() << ")" << std::endl;
}	// end display2Pt


/**
*Dispalys the point slope form of the line inputted
*
* Parameters:
*	line		the line that was calculated / inputted
* Returns:
*/
void displayPointSlope(Line line)
{
	std::cout << "\nPoint-slope form:" << std::endl;
	std::cout << "\ty - " << line.getFirstPtY() << " = " << line.getSlope() << "(x - " << line.getFirstPtX() << ")" << std::endl;
}	// end displayPointSlope


/**
* Displays the slope-intercept form of the line inputted
*
*Parameters:
*	line		the line thaw was calculated / inputted
* Returns:
*/
void displaySlopeIntercept(Line line)
{
	std::cout << "\nSlope-intercept form:" << std::endl;
	std::cout << "\ty = " << line.getSlope() << "x + " << line.calcIntercept() << std::endl;
}	// end displaySlopeIntercept


/**
*Graphs the line that was inputted / calculated
*
* Parameters:
*	line		the line that was calculated / inputted
*/
void drawLine(Line line)
{
	fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	while (!fgcugl::windowClosing())
	{
		// draw backgroup
		fgcugl::drawQuad(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, fgcugl::Gray);

		// draw x-axis
		fgcugl::drawLine(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2, 2, fgcugl::Cyan);
		//draw y-axis
		fgcugl::drawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, 2, fgcugl::Cyan);

		int xScaler = WINDOW_WIDTH / 2.0;	// shifts the x points into the correct position
		int yScaler = WINDOW_HEIGHT / 2.0;	// shifts the y points into the correct position

		// draw inputted line
		fgcugl::drawLine(line.getFirstPtX() + xScaler, line.getFirstPtY() + yScaler,
			line.getSecondPtX() + xScaler, line.getSecondPtY() + yScaler,
			3, fgcugl::Lime);

		// draw to GL window
		fgcugl::windowPaint();
		fgcugl::getEvents();
	}

	fgcugl::cleanup();

}// end drawLine

