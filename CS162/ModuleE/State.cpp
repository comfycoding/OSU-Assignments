/*********************************************************************
** Program Filename: State.cpp
** Author: Darlene Zouras 
** Date: 5/6/2016
** Description: The State class functions.
*********************************************************************/

#include "State.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>	// for the sleep() delay function
using std::cout;
using std::endl;

/*********************************************************************
 ** Function: Constructor
 ** Description: When a State object is created, it initializes the
 ** StateList list and puts the four states in order. The first state
 ** is set as the currentState pointer.
 *********************************************************************/

State::State()
{
	char G, Y, R;

	// initialize the entire list
	state1 = new StateList('G', 'R');
		// the first node is NR G, EW R.
	state2 = new StateList('Y', 'R');
	state1->next = state2;
		// the second node is NR Y, EW R.
	state3 = new StateList('R', 'G');
	state2->next = state3;
		// the third node is NR R, EW G.
	state4 = new StateList('R', 'Y');
	state3->next = state4;
	state4->next = state1;
		// the fourth node is NR R, EW Y.

	currentState = state1;
		// initialize the current state to state 1

	nrOfVehiclesAtNLight = 0;
	nrOfVehiclesAtSLight = 0;
	nrOfVehiclesAtELight = 0;
	nrOfVehiclesAtWLight = 0;
	carsArrive = 0;
	carsDepart = 0;
}

/*********************************************************************
 ** Function: getNSState
 ** Description: This function is called every time the StateList moves
 ** to the next state in its loop. Through if / else statements it is
 ** determined what color the NS light currently is. During a green
 ** light, vehicles arrive and depart, and the number of vehicles at 
 ** both the north and south lights are calculated.
 *********************************************************************/

void State::getNSState()	// direction 1 status
{
	// The NS light is Green,
	// Vehicles arriving are generated,
	// and Vehicles departing are generated.
	// The vehicles waiting when the light turns is calculated.
	if (currentState->NS == 'G')
	{ 
		int aN = nrOfVehiclesArrive();
		int dN = nrOfVehiclesDepart();
		if (dN > (aN + nrOfVehiclesAtNLight))
			dN = aN + nrOfVehiclesAtNLight;
		calculateAverage(aN, dN);

		int aS = nrOfVehiclesArrive();
		int dS = nrOfVehiclesDepart();
		if (dS > (aS + nrOfVehiclesAtSLight))
			dS = aS + nrOfVehiclesAtSLight;
		calculateAverage(aS, dS);

		cout << "The North/South light is currently GREEN." << endl;
		// cout << "\t" << nrOfVehiclesAtNLight << " vehicles have been waiting at the North light." << endl;
		cout << "\t" << aN << " vehicles arrive at the North light." << endl;
		cout << "\t" << dN << " vehicles depart the North light." << endl;
		nrOfVehiclesAtNLight = (nrOfVehiclesAtNLight + aN) - dN;
		// cout << "\t" << nrOfVehiclesAtSLight << " vehicles have been waiting at the South light." << endl;
		cout << "\t" << aS << " vehicles arrive at the South Light." << endl;
		cout << "\t" << dS << " vehicles depart the South Light." << endl;
		nrOfVehiclesAtSLight = (nrOfVehiclesAtSLight + aS) - dS;
	}
	
	// The NS light is Yellow,
	// Report the number of vehicles that stopped
	// (at the end of the Green light).
	else if (currentState->NS == 'Y')
	{
		cout << "The North/South light is currently YELLOW." << endl;
		cout << "\t" << nrOfVehiclesAtNLight << " vehicles stop at the North light." << endl;
		cout << "\t" << nrOfVehiclesAtSLight << " vehicles stop at the South light." << endl;
	}

	// The NS light is Red,
	// These cars have been waiting since the Green light turned Yellow.
	else
	{
		cout << "The North/South light is currently RED." << endl;
		cout << "\t" << nrOfVehiclesAtNLight << " vehicles are stopped at the North light." << endl;
		cout << "\t" << nrOfVehiclesAtSLight << " vehicles are stopped at the South light." << endl;
	}
}

/*********************************************************************
 ** Function: getEWState
 ** Description: This function is called every time the StateList moves
 ** to the next state in its loop. Through if / else statements it is
 ** determined what color the EW light currently is. During a green
 ** light, vehicles arrive and depart, and the number of vehicles at 
 ** both the east and south lights are calculated.
 *********************************************************************/

void State::getEWState()	// direction 2 status
{
	// The EW light is Green,
	// Vehicles arriving are generated,
	// and Vehicles departing are generated.
	// The vehicles waiting when the light turns is calculated.
	if (currentState->EW == 'G')
	{
		int aE = nrOfVehiclesArrive();
		int dE = nrOfVehiclesDepart();
		if (dE > (aE + nrOfVehiclesAtELight))
			dE = aE + nrOfVehiclesAtELight;
		calculateAverage(aE, dE);

		int aW = nrOfVehiclesArrive();
		int dW = nrOfVehiclesDepart();
		if (dW > (aW + nrOfVehiclesAtWLight))
			dW = aW + nrOfVehiclesAtWLight;
		calculateAverage(aW, dW);

		cout << "The East/West light is currently GREEN." << endl;
		// cout << "\t" << nrOfVehiclesAtELight << " vehicles have been waiting at the East light." << endl;
		cout << "\t" << aE << " new vehicles arrive at the East light." << endl;
		cout << "\t" << dE << " vehicles depart the East light." << endl;
		nrOfVehiclesAtELight = (nrOfVehiclesAtELight + aE) - dE;
		// cout << "\t" << nrOfVehiclesAtWLight << " vehicles have been waiting at the West light." << endl;
		cout << "\t" << aW << " vehicles arrive at the West light." << endl;
		cout << "\t" << dW << " vehicles depart the West light." << endl;
		nrOfVehiclesAtWLight = (nrOfVehiclesAtWLight + aW) - dW;
	}

	// The EW light is Yellow,
	// Report the number of vehicles that stopped
	// (at the end of the Green light).
	else if (currentState->EW == 'Y')
	{
		cout << "The East/West light is currently YELLOW." << endl;
		cout << "\t" << nrOfVehiclesAtELight << " vehicles stop at the East light." << endl;
		cout << "\t" << nrOfVehiclesAtWLight << " vehicles stop at the West light." << endl;
	}

	// The EW light is Red,
	// These cars have been waiting since the Green light turned Yellow.
	else
	{
		cout << "The East/West light is currently RED." << endl;
		cout << "\t" << nrOfVehiclesAtELight << " vehicles are stopped at the East light." << endl;
		cout << "\t" << nrOfVehiclesAtWLight << " vehicles are stopped at the West light." << endl;
	}
}

/*********************************************************************
 ** Function: nrOfVehiclesArrive
 ** Description: Randomly generates a number between 2 and 16 (with 
 ** slightly higher probability of the numbers in the middle) for number
 ** of cars that arrive at a green light.
 *********************************************************************/

int State::nrOfVehiclesArrive()
{
	int arriving = 0;
	for (int i = 0; i < 2; i++) {
		arriving += ((rand() % 8) + 1); 		// will randomly generate 2 - 16
	}
	return arriving;
}

/*********************************************************************
 ** Function: nrOfVehiclesDepart
 ** Description: Randomly generates a number between 2 and 12 (with
 ** slightly higher probability of the numbers in the middle) for number
 ** of cras that drive through the green light.
 *********************************************************************/

int State::nrOfVehiclesDepart()
{
	int departing = 0;
	for (int i = 0; i < 2; i++) {
		departing += ((rand() % 6) + 1);		// will randomly generate 2 - 12
	}
	return departing;
}

/*********************************************************************
 ** Function: displayRounds
 ** Description: Iterates through the list and displays each state
 ** of the intersection. It will make a complete loop through the list
 ** for as many times as is specified by a user in the main function.
 *********************************************************************/

void State::displayRounds(int num)
{
	for (int i = 0; i < num; i++)
	{
		
		cout << "\nDisplaying Round " << (i + 1) << endl;
		// Move through each of the four states
		do {
			getNSState();
			getEWState();
			cout << endl;
			// move on to next state
			currentState = currentState->next;
			sleep(1);
		} while (currentState != state1);
	}

	// calculate data averages
	carsArrive = carsArrive / (4 * num);
	carsDepart = carsDepart / (4 * num);
	int average = (carsArrive - carsDepart);
	cout << "On average, " << carsArrive << " new cars arrive at a stop light." << endl;
	cout << "And on average, " << carsDepart << " cars are able to get through a green light." << endl;
	cout << "There are, on average, " << average << " new cars waiting at the end of every green light." << endl;
}

/*********************************************************************
 ** Function: calculageAverage
 ** Description: Receives numbers for cars that arrive and depart
 ** through green lights, and stores them in a counter variable to be
 ** used later.
 *********************************************************************/

void State::calculateAverage(int arrive, int depart)
{
	carsArrive += arrive;
	carsDepart += depart;
}