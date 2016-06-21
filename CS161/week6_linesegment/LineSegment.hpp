/*********************************************************************
** Author: Darlene Zouras
** Date: February 8, 2016
** Description: Project 6
** LineSegment.cpp, LineSegment.hpp, Point.cpp, Point.hpp
** This program creates two Point class objects to create a single 
** LineSegment class object. The Point objects can be used 
** to determine the line's length and slope.
*********************************************************************/

// LineSegment.hpp
#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP
#include "Point.hpp"

class LineSegment
{
public:
	Point point1;		// The two endpoints
	Point point2;		// belong to the Point class
	void setEnd1(double, double);
	void getEnd1();
	void setEnd2(double, double);
	void getEnd2();
	double length();
	double slope();
};

#endif