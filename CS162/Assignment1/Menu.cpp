/*********************************************************************
** Program Filename: Menu.cpp
** Author: Darlene Zouras 
** Date: 4/8/2016
** Description: The beginnings of a collection of reusable functions.
** Input:
** Output: 
*********************************************************************/

#include "Menu.hpp"
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 ** Function: getOne
 ** Description: Requests user for an integer input and validates the
 ** integer.
 ** Parameters: Returns one integer back to the function that called it.
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

int getOne() {
	int x;
	cin >> x;
    while (!checkX(x)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, try again. Enter one number, then press enter: " << endl;
        cin >> x;
    }

    return x;
}

/*********************************************************************
 ** Function: checkXY
 ** Description: Checks for two integer inputs above 0.
 ** Parameters: 
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

bool checkXY(int x, int y) {
    if (x % 1 == 0 && y % 1 == 0) {
        if (x > 0 && y > 0)
            return true;
        else
            return false;
    }
    else
        return false;
}

/*********************************************************************
 ** Function: checkX
 ** Description: Checks for a single integer input above 0.
 ** Parameters: 
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

bool checkX(int x) {
    if (x > 0 && x % 1 == 0)
        return true;
    else
        return false;
}