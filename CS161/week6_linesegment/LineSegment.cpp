/*********************************************************************
** Author: Darlene Zouras
** Date: February 8, 2016
** Description: Project 6
** LineSegment.cpp, LineSegment.hpp, Point.cpp, Point.hpp
** This program creates two Point class objects to create a single 
** LineSegment class object. The Point objects can be used 
** to determine the line's length and slope.
*********************************************************************/

// LineSegment.cpp
#include "LineSegment.hpp"

void LineSegment::setEnd1(double x1, double y1)
{	point1.setXCoord(x1);
	point1.setYCoord(y1);	}

void LineSegment::setEnd2(double x2, double y2)
{	point2.setXCoord(x2);
	point2.setYCoord(y2);	}

void LineSegment::getEnd1()
{
	cout << "(" << point1.getXCoord() << ", " << point1.getYCoord() << ")";
}

void LineSegment::getEnd2()
{
	cout << "(" << point2.getXCoord() << ", " << point2.getYCoord() << ")";
}

double LineSegment::length()
{
	double dist = point1.distanceTo(point2);
	return dist;
}

double LineSegment::slope()
{
	double slope;
	double x1 = point1.getXCoord();
	double x2 = point2.getXCoord();
	double y1 = point1.getYCoord();
	double y2 = point2.getYCoord();
	double top = x2 - x1;
	double bottom = y2 - y1;
	if (bottom == 0)
		slope = 0.0;					// I don't know how to set to infinity :(
	else
		slope = (x2 - x1) / (y2 - y1);
	return slope;
}