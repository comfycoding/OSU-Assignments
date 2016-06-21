/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 4/13/2016
** Description: Module C main function
** Creates a Path object to serve as the grid that the multiple
** Ant objects move around and breed.
*********************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Path.hpp"
#include "Menu.cpp"


int main(){
	int rowX, rowY, numCritters, numMoves;

    cout << "Enter X rows and Y columns , must be at least (1, 1)." << endl;
    cin >> rowX >> rowY;
    while (!checkXY(rowX, rowY)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, please enter two integers above zero and then press enter." << endl;
        cin >> rowX >> rowY;
    }
    cout << "How many critters on the board?" << endl;
    numCritters = getOne();
    while (!checkForSmaller(numCritters, rowX * rowY)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, you are requesting for more critters than spaces on the grid." << endl;
        cout << "Enter a smaller number of critters, then press enter." << endl;
        numCritters = getOne();
    }

    Path path(rowX, rowY);
    path.setCritters(numCritters);
    cout << "Here are the critter's starting places on the grid:" << endl;
    path.gridDisplay();
    path.findCritters();

    cout << "\n\nHow many turns would you like the critters to move?" << endl;
    numMoves = getOne();
    cout << "The critters will move " << numMoves << " times." << endl;
    
    path.run(numMoves);

    cout << "\nThe critters have moved through every iteration or filled the grid." << endl;
   	
    path.remove();
   	return 0;
}
