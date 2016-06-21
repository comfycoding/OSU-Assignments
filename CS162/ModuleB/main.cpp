/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 4/9/2016
** Description: Module B main function
** Creates a Path object to serve as the grid that the multiple
** critter objects move around.
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

    cout << "The critters have moved through every iteration." << endl;
   	
    path.remove();
   	return 0;
}
