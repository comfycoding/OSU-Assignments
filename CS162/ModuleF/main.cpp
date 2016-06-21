/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 5/17/2016
** Description: Main file of the Module F assignment.
*********************************************************************/

#include <iostream>
#include <time.h>
#include <string>
#include "Menu.cpp"
#include "State.hpp"
using std::cout;
using std::endl;

/*********************************************************************
 ** Function: main function
 ** Description: The main function of Module F is responsible for
 ** creating the seed to ensure genuinely randomly generated numbers
 ** in the State functions. It then creates the State object, which
 ** generates the list within it.
 ** Then, get the number of times to run through the State loop from
 ** the user. It uses that number to run the displayRounds function
 ** in the State object.
 *********************************************************************/

int main()
{
	srand (time(NULL));		// random number seed

	// Initialize the intersection
	State trafficState;

	cout << "For how many rounds would you like to run the traffic simulation?" << endl;
	int num = getOne();
	trafficState.displayRounds(num);

	return 0;
}
