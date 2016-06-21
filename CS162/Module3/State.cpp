/*********************************************************************
** Program Filename: State.cpp
** Author: Darlene Zouras
** Date: 5/17/2016
** Description: The State class functions.
*********************************************************************/

#include "State.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>	// for the sleep() delay function
#include <deque>
using std::cout;
using std::endl;
using std::deque;

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

	/* deque<int> north;
	deque<int> south;
	deque<int> east;
	deque<int> west; */
		// initialize each of the four lanes.

	nrOfVehiclesAtNLight = 0;
	nrOfVehiclesAtSLight = 0;
	nrOfVehiclesAtELight = 0;
	nrOfVehiclesAtWLight = 0;

	avgCalc = 0;
	avgCalcN = 0;
	avgCalcS = 0;
	avgCalcE = 0;
	avgCalcW = 0;
	carTotal = 0;
	carTotalN = 0;
	carTotalS = 0;
	carTotalE = 0;
	carTotalW = 0;
}

/*********************************************************************
 ** Function: getNSState
 ** Description: This function is called every time the StateList moves
 ** to the next state in its loop. Through if / else statements it is
 ** determined what color the NS light currently is. During a green
 ** light, vehicles arrive and depart, and the number of vehicles at
 ** both the north and south lights are calculated.
 *********************************************************************/

void State::getNSState(int num)	// direction 1 status
{
	// The NS light is Green,
	// Vehicles arriving are generated and added to the CarQueue,
	// and Vehicles departing are generated, removed from the queue.
	if (currentState->NS == 'G')
	{
		// GREEN NORTH
		int aN = nrOfVehiclesArrive();
		for (int i = 0; i < aN; i++)
			north.push_back(num);

		int dN = nrOfVehiclesDepart();
		if (dN > (aN + nrOfVehiclesAtNLight))
			dN = aN + nrOfVehiclesAtNLight;
		carTotalN += dN;
		for (int i = 0; i < dN; i++) {
			avgCalcN += (num - north.front());
			north.pop_front(); }

		// GREEN SOUTH
		int aS = nrOfVehiclesArrive();
		for (int i = 0; i < aS; i++)
			south.push_back(num);

		int dS = nrOfVehiclesDepart();
		if (dS > (aS + nrOfVehiclesAtSLight))
			dS = aS + nrOfVehiclesAtSLight;
		carTotalS += dS;
		for (int i = 0; i < dS; i++) {
			avgCalcS += (num - south.front());
			south.pop_front(); }

		cout << "The North/South light is currently GREEN." << endl;
		cout << "\t" << aN << " new vehicles arrive at the North light." << endl;
		cout << "\t" << dN << " vehicles depart the North light." << endl;
		nrOfVehiclesAtNLight = (nrOfVehiclesAtNLight + aN) - dN;

		cout << "\t" << aS << " new vehicles arrive at the South Light." << endl;
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

void State::getEWState(int num)	// direction 2 status
{
	// The EW light is Green,
	// Vehicles arriving are generated and added to the CarQueue,
	// and Vehicles departing are generated, removed from the queue.
	if (currentState->EW == 'G')
	{
		int aE = nrOfVehiclesArrive();
		for (int i = 0; i < aE; i++)
			east.push_back(num);

		int dE = nrOfVehiclesDepart();
		if (dE > (aE + nrOfVehiclesAtELight))
			dE = aE + nrOfVehiclesAtELight;
		carTotalE += dE;
		for (int i = 0; i < dE; i++) {
			avgCalcE += (num - east.front());
			east.pop_front(); }

		int aW = nrOfVehiclesArrive();
		for (int i = 0; i < aW; i++)
			west.push_back(num);

		int dW = nrOfVehiclesDepart();
		if (dW > (aW + nrOfVehiclesAtWLight))
			dW = aW + nrOfVehiclesAtWLight;
		carTotalW += dW;
		for (int i = 0; i < dW; i++) {
			avgCalcW += (num - west.front());
			west.pop_front(); }

		cout << "The East/West light is currently GREEN." << endl;
		cout << "\t" << aE << " new vehicles arrive at the East light." << endl;
		cout << "\t" << dE << " vehicles depart the East light." << endl;
		nrOfVehiclesAtELight = (nrOfVehiclesAtELight + aE) - dE;

		cout << "\t" << aW << " new vehicles arrive at the West light." << endl;
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
		arriving += ((rand() % 7) + 1); 		// will randomly generate 2 - 14
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
 ** It also calculates the average number of iterations it takes for
 ** a car to wait at a light before it is able to move through.
 *********************************************************************/

void State::displayRounds(int num)
{
	for (int i = 0; i < num; i++)
	{

		cout << "\nDisplaying Round " << (i + 1) << endl;
		// Move through each of the four states
		do {
			getNSState(i);
			getEWState(i);
			cout << endl;
			// move on to next state
			currentState = currentState->next;

			// THE NEXT LINE CAN BE UNCOMMENTED
			// TO GIVE A SHORT DELAY BEFORE EACH STATE CHANGE.
			// sleep(1);
		} while (currentState != state1);
	}

	// Individual averages
	cout << "At the North light, cars waited for " << (avgCalcN / carTotalN) << " iterations on average to pass." << endl;
	cout << "At the South light, cars waited for " << (avgCalcS / carTotalS) << " iterations on average to pass." << endl;
	cout << "At the East light, cars waited for " << (avgCalcE / carTotalE) << " iterations on average to pass." << endl;
	cout << "And at the West light, cars waited for " << (avgCalcW / carTotalW) << " iterations on average to pass." << endl;

	// Entire system averages
	avgCalc = avgCalcN + avgCalcS + avgCalcE + avgCalcW;
	carTotal = carTotalN + carTotalS + carTotalE + carTotalW;
	int average = avgCalc / carTotal;
	cout << "In the entire system, cars waited for " << average << " iterations on average to pass through the intersection." << endl;
}
