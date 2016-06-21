/*********************************************************************
** Author: Darlene Zouras
** Date: February 1, 2016
** Description: Project 5.a, Box.cpp and Box.hpp
** This program creates a class called Box. The Box class can be used
** to create Box objects where the height, width, and length can be
** manipulated, and the volume and the surface areas can be calculated.
*********************************************************************/

// Box.hpp is the Box class specification file.
#ifndef BOX_H
#define BOX_H

// Box class declaration
class Box
{
private: 
	double height;
	double width;
	double length;

public:
	Box();
	void setHeight(double);
	void setWidth(double);
	void setLength(double);
	double getVolume();
	double getSurfaceArea();
};
#endif