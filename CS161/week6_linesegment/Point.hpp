/*********************************************************************
** Author: Darlene Zouras
** Date: February 8, 2016
** Description: Project 6
** LineSegment.cpp, LineSegment.hpp, Point.cpp, Point.hpp
** This program creates two Point class objects to create a single 
** LineSegment class object. The Point objects can be used 
** to determine the line's length and slope.
*********************************************************************/

// Point.hpp
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
using namespace std;

/****************************************************************************
Point class
****************************************************************************/
class Point
{
private:
	double xCoord;
	double yCoord;

public:
	Point();
	Point(double, double);
	void setXCoord(double);
	double getXCoord() const;
	void setYCoord(double);
	double getYCoord() const;
	double distanceTo(const Point &);
};

#endif