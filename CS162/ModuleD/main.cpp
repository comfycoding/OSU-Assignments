/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Module D main function
** Creates a Path object to serve as the grid that the multiple
** Ant and Doodlebug objects move around and breed.
*********************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Path.hpp"
#include "Menu.cpp"

int getCrits();

int main(){
	int rowX, rowY, numAnts, numDoodlebugs, numMoves;

    cout << "Enter X rows and Y columns , must be at least (1, 1)." << endl;
    cin >> rowX >> rowY;
    while (!checkXY(rowX, rowY)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, please enter two integers above zero and then press enter." << endl;
        cin >> rowX >> rowY;
    }

    // Get input for number of Ants
    cout << "How many Ants on the board?" << endl;
    numAnts = getOne();
    while (!checkForSmaller(numAnts, rowX * rowY)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, you are requesting for more critters than spaces on the grid." << endl;
        cout << "Enter fewer Ants, then press enter." << endl;
        numAnts = getOne();
    }

    cout << "There will be " << numAnts << " Ants." << endl;

    // Get input for number of Doodlebugs
    cout << "How many Doodlebugs on the board?" << endl;
    cout << "You can have as many as " << (rowX * rowY) - numAnts - 1 << "." << endl;
    numDoodlebugs = getOne();
    while (!checkForSmaller(numDoodlebugs, (rowX * rowY) - numAnts - 1)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, you are requesting for more critters than spaces on the grid." << endl;
        cout << "Enter fewer Doodlebugs, then press enter." << endl;
        numDoodlebugs = getOne();
    }

    cout << "There will be " << numDoodlebugs << " Doodlebugs." << endl;

    // Initializes the grid and sets the critters
    Path path(rowX, rowY);
    path.setCritters(numAnts, numDoodlebugs);
    cout << "Here are the critter's starting places on the grid:" << endl;
    path.gridDisplay();

    // Get input for number of turns
    cout << "\n\nHow many turns would you like the critters to move?" << endl;
    numMoves = getOne();
    cout << "The critters will move " << numMoves << " times." << endl;
    
    path.run(numMoves); // runs through the program

    cout << "\nThe critters have moved through every iteration or filled the grid." << endl;
    path.remove();      // deletes the grid

   	return 0;
}
