/*********************************************************************
** Program Filename: Menu.cpp
** Author: Darlene Zouras 
** Date: 4/29/2016
** Description: The beginnings of a collection of reusable functions.
*********************************************************************/

//#include "Menu.hpp"
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 ** Function: checkX
 ** Description: Checks for a single integer input above or equal to 0.
 ** Parameters: Receives a single input, if it is an integer that is
 ** greater than 0, returns true.
 *********************************************************************/

bool checkX(int x) {
    if (x > 0 && x % 1 == 0)
        return true;
    else
        return false;
}

/*********************************************************************
 ** Function: getOne
 ** Description: Requests user for an integer input and validates the
 ** integer.
 ** Parameters: Returns one integer back to the function that called it.
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
 ** Function: checkForSmaller
 ** Description: Checks whether an integer x is greater than or less
 ** than an integer y.
 ** Parameters: Receives two integers, if the first is greater than the
 ** second, returns flase. If the first is less than the second,
 ** returns true.
 *********************************************************************/

bool checkForSmaller(int x, int y) {
    if (x > y)
        return false;
    else
        return true;
}

/*********************************************************************
 ** Function: getDouble
 ** Description: Validates an input that requests a double. Simply
 ** checks it against itself as an int- this also prevents text
 ** entries.
 ** Parameters: Returns an acceptable double variable.
 *********************************************************************/

double getDouble() {
    double x;
    cin >> x;
    while ( x == int(x)) {
        cin.clear();
        cin.ignore();
        cout << "Sorry, try again. Enter a number with a decimal place." << endl;
        cin >> x;
    } 

    return x;
}