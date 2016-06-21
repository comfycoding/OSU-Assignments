/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: The main function of the Module 1 assignment. In the 
** main function a menu is called, and the input from the user determines
** which process to run from that point.
*********************************************************************/

#include <iostream>
#include "Menu.cpp"
#include "reverseString.cpp"
#include "addArray.cpp"
#include "triangle.cpp"

using std::cin;
using std::cout;
using std::endl;

int menu();         // menu prototype

/*********************************************************************
 ** Function: main
 ** Description: Calls the menu function, which returns an option 
 ** for which task should be completed. It then calls any of the other
 ** functions, depending on the user request.
 *********************************************************************/

int main() {
    int pick = menu();

    while ( pick != 4) {
        if (pick == 1) {
            reverseMain();
            pick = menu();
        }
        else if (pick == 2) {
            addMain();
            cin.clear();
            cin.ignore();
            pick = menu();
        }
        else if (pick == 3) {
            triMain();
            pick = menu();
        }
        else {
            cout << "Sorry, that is not one of the options." << endl;
            pick = menu();
        }
    }

    cout << "Exiting the program." << endl;
    return 0;
}

/*********************************************************************
 ** Function: menu
 ** Description: Displays the options to the user and also receives the
 ** input and returns it to the main function.
 *********************************************************************/

int menu() {
    int num = 0;

    cout << "\nPlease select one of the options: " << endl;
    cout << "\t1: Reverse a string." << endl;
    cout << "\t2: Add up the contents of an array." << endl;
    cout << "\t3: Sum up a triangular number." << endl;
    cout << "\t4: Exit the program." << endl;
    num = getOne();

    return num;
}