/*********************************************************************
** Program Filename: State.hpp
** Author: Darlene Zouras 
** Date: 5/6/2016
** Description: The State class header files.
*********************************************************************/

#ifndef STATE_HPP
#define STATE_HPP
#include <iostream>

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

	int nrOfVehiclesAtELight;
	int nrOfVehiclesAtWLight;
	int nrOfVehiclesAtNLight;
	int nrOfVehiclesAtSLight;
	int carsArrive;
	int carsDepart;
public:
	State();
	void getNSState();
	void getEWState();
	int nrOfVehiclesArrive();
	int nrOfVehiclesDepart();
	void displayRounds(int num);
	void calculateAverage(int arrive, int depart);
};
#endif