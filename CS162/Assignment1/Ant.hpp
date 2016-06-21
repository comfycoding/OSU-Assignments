/*********************************************************************
** Program Filename: Ant.hpp
** Author: Darlene Zouras
** Date: 4/8/2016
** Description: Ant class header file.
** Input:
** Output: 
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant {
private:
	int xCoord;
	int yCoord;
	int direction;  // 1 = left, 2 = up, 3 = right, 4 = down
	class Grid;
public:
	Ant();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void move(char cellColor);
};

#endif