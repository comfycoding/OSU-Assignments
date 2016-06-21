/*********************************************************************
** Author: Darlene Zouras
** Date: February 8, 2016
** Description: Project 6
** LineSegment.cpp, LineSegment.hpp, Point.cpp, Point.hpp
** This program creates two Point class objects to create a single 
** LineSegment class object. The Point objects can be used 
** to determine the line's length and slope.
*********************************************************************/

//Point.cpp
#include <iostream>
#include <cmath>
#include "Point.hpp"

// Point default constructor
Point::Point()
{
	double xCoord = 0.0;
	double yCoord = 0.0;
}

// Point class Constructor
Point::Point(double xC, double yC)
{
	setXCoord(xC);
	setYCoord(yC);
}

void Point::setXCoord(double xPoint)
{	xCoord = xPoint;	}

double Point::getXCoord() const
{	return xCoord;	}

void Point::setYCoord(double yPoint)
{	yCoord = yPoint;	}

double Point::getYCoord() const
{	return yCoord;	}

double Point::distanceTo(const Point& P)
{	
    double endx = P.getXCoord();
	double endy = P.getYCoord();
	return sqrt( pow(( endx - xCoord ), 2.0) + pow(( endy - yCoord ), 2.0) );
}