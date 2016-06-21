/*********************************************************************
** Program Filename: State.hpp
** Author: Darlene Zouras
** Date: 5/17/2016
** Description: The State class header files.
*********************************************************************/

#ifndef STATE_HPP
#define STATE_HPP
#include <iostream>
#include <deque>
using std::deque;

class State
{
protected:

	// StateList
	// Holds the state of the intersection, the colors of the
	// lights are held as char variables.
	struct StateList
	{
		char NS, EW;
		StateList *next;
		StateList(char ns, char ew, StateList *next1 = NULL)
		{
			NS = ns;
			EW = ew;
			next = next1;
		}
	};

	// The pointer to current and four state pointers
	StateList *currentState;
	StateList *state1;
	StateList *state2;
	StateList *state3;
	StateList *state4;

	// Lane queues
	deque<int> north;
	deque<int> south;
	deque<int> east;
	deque<int> west;

	int nrOfVehiclesAtELight;
	int nrOfVehiclesAtWLight;
	int nrOfVehiclesAtNLight;
	int nrOfVehiclesAtSLight;
	int avgCalc, avgCalcN, avgCalcS, avgCalcE, avgCalcW;
	int carTotal, carTotalN, carTotalS, carTotalE, carTotalW;

public:
	State();
	void getNSState(int num);
	void getEWState(int num);
	int nrOfVehiclesArrive();
	int nrOfVehiclesDepart();
	void displayRounds(int num);
};
#endif
