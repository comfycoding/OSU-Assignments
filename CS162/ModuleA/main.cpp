/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 4/5/2016
** Description: Module A main function
** This program places a Critter object randomly on a grid. The critter
** moves randomly around the grid in no more than 4 spaces in any
** direction. When the critter moves off of the grid, it is squashed.
** Input: Receives the size of the grid from the user.
** Output: Displays the grids each turn until the critter is squished.
*********************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Path.hpp"


int main(){
	int rowX, rowY;

    cout << "Enter X rows and Y columns , must be at least (1, 1)." << endl;
    cin >> rowX >> rowY;
    Path pathTest(rowX, rowY);
    pathTest.updateLocation();
    pathTest.gridDisplay();
    
    while (pathTest.updateLocation() == true) {
    	cout << "\nMoving critter..." << endl;
    	pathTest.gridDisplay();
    }
    pathTest.squashed();
   	
   	return 0;
}
