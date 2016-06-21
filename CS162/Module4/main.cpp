/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: The main file for the Module 4 program.
*********************************************************************/

#include <vector>
#include <iostream>
#include "TimeTests.hpp"
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int menu();

/*********************************************************************
 ** Function: main
 ** Description: The main function of Module 4, it has a user select
 ** from a menu (which is a function located outside of itself), and
 ** based on the selection, runs different functions from the TimeTest
 ** class object.
 *********************************************************************/

int main()
{
    TimeTest test;
    int pick = menu();

    while (pick != 4)
    {
        // Run a test between the recursive and nonrecursive functions.
        if (pick == 1)
            test.testRecursion();

        // Test between the tail recursive and nontail recursive functions.
        else if (pick == 2)
            test.testTailRecursion();

        // The user has selected to display the test results
        else if (pick == 3)
            test.displayResults();

        // The user has not selected a number 1-4
        else
            cout << "Sorry, that's not one of the options. Try another number." << endl;
        cin.clear();
        cin.ignore();
        pick = menu();
    }

    return 0;
}

/*********************************************************************
 ** Function: menu
 ** Description: The menu displays the user's options within the program.
 ** The options include testing between recursive and non-recursive functions,
 ** testing between tail recursive and non-tail recursive functions,
 ** displaying the results of the tests run so far,
 ** and exiting the program.
 *********************************************************************/

int menu()
{
    int pick;
    cout << "\nProgram options: " << endl;
    cout << "\t1) Test recursive and nonrecursive function speed" << endl;
    cout << "\t2) Test tail recursive and non tail recursive speed" << endl;
    cout << "\t3) Review the results so far" << endl;
    cout << "\t4) Exit the program" << endl;
    cout << "Enter a number: ";
    cin >> pick;
    return pick;
}
