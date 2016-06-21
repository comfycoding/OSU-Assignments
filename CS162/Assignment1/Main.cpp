/*********************************************************************
** Program Filename: Main.cpp
** Author: Darlene Zouras
** Date: 4/8/2016
** Description: The main function file for the Langton's Ant simulation
** program (assignment 1).
** Input: Receives the dimensions for the grid, as well as the location 
** for the ant (unless the ant is randomized). Finally, it receives the
** number of moves that the ant will move around the grid.
** Output: Displays the grid for every turn when the ant makes its move.
*********************************************************************/

#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Grid.hpp"
#include "Menu.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    char randAnt;
    int gridX, gridY;
    int antX, antY;
    int numMoves;

    // Prompts user and sets the size of the grid
    cout << "What is the size of the grid?" << endl;
    cout << "Enter width and height, then press Enter:" << endl;
    cin >> gridX >> gridY;
    while (!checkXY(gridX, gridY)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, try again. Two numbers, then press enter: " << endl;
        cin >> gridX >> gridY;
    }
    cout << "The grid will be " << gridX << " by " << gridY << "." << endl;

    // Prompts user and either sets the ant to a random position
    // or user sets the starting place of the ant
    cout << "Start the Ant in a random position?" << endl;
    cout << "Y or N?" << endl;
    cin >> randAnt;
    if (randAnt == 'Y' || randAnt == 'y') {
        srand (time(NULL));
        antX = rand() % gridX + 1;
        antY = rand() % gridY + 1;
    }
    else {
        cout << "Where shall the Ant start?" << endl;
        cout << "Enter two numbers, then press Enter:" << endl;
        cin >> antX >> antY;
        while (!checkXY(antX, antY)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, try again. Two numbers, then press enter: " << endl;
        cin >> antX >> antY;
        }
    }
    cout << "The Ant will start at " << antX << ", " << antY << "." << endl;

    // Asks the user how many turns the ant will move.
    cout << "How many turns will the ant move?" << endl;
    cout << "To best see the Langton's Ant pattern, take at least 100 steps!" << endl;
    numMoves = getOne();
    
    //Initializes the grid.
    Grid grid(gridX, gridY, antX, antY, numMoves);

    //And then runs the sequence.
    grid.run();

    return 0;
}