/*********************************************************************
** Author: Darlene Zouras
** Date: February 1, 2016
** Description: Project 5.a, Box.cpp and Box.hpp
** This program creates a class called Box. The Box class can be used
** to create Box objects where the height, width, and length can be
** manipulated, and the volume and the surface areas can be calculated.
*********************************************************************/

// Box.cpp is the Box class function implementation file.
#include "Box.hpp"

/* Box::Box
The constructor! Initializes the box class variables. */
Box::Box()
{
	height = 1.0;
	width = 1.0;
	length = 1.0;
}

/* Box::setHeight
Validates the value passed to it before assigning it
to the height member variable. */
void Box::setHeight(double h)
{
	if (h >= 0.0)
		height = h;
	// else it is set to its previous value.
}

/* Box::setWidth
Validates the value passed to it before assigning it
to the width member variable. */
void Box::setWidth(double w)
{
	if (w >= 0.0)
		width = w;
	// else it is set to its previous value.
}

/* Box::setLength
Validates the value passed to it before assigning it
to the length member variable. */
void Box::setLength(double l)
{
	if (l >= 0.0)
		length = l;
	// else it is set to its previous value.
}

/* Box::getVolume
This function calculates and returns the Box object's
volume. */
double Box::getVolume()
{
	return height * width * length;
}

/* Box::getSurfaceArea
This function calculates and returns the Box object's 
surface area. */
double Box::getSurfaceArea()
{
	return (2 * height * length) + (2 * height * width);
}