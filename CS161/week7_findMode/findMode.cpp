/*********************************************************************
** Author: Darlene Zouras
** Date: February 15, 2016
** Description: Project 7
** findMode.cpp
** This function accepts an array and its size and returns a vector that
** contains the mode(s) of the array in ascending order.
** It does this with 4 loops: a while loop to push each unique integer
** found in the array to a vector, a for loop that counts how many times
** each unique integer occurs in the array, a for loop that determines
** the highest of those incidences, and a final for loop to push the 
** largest incidence to the modeHolder vector to be returned
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findMode(int testArray[], int testSize);	// function prototype

// the findMode function
vector<int> findMode(int array[], int size)
{
	vector<int> modeHolder;		// This vector will hold the mode(s).
	vector<int>	uniqueNums;		// These vectors hold unique integers
	vector<int> numNums;		// and the numbers of times they're found
								// in the arrays.
	int count = 0;
	int indexA = 0;				// used as an array counter
	int indexV = 0;				// used as a vector counter
	int highHold = 0;

	sort(array, array + size);	// sorts the array
	
	// This loop pushes each unique integer into the uniqueNums vector
	while (indexA < size)
	{
		if (indexA == 0)
		{	uniqueNums.push_back(array[indexA]);
			indexA++;	}
		else if (uniqueNums[indexV] == array[indexA])
			indexA++;
		else if (uniqueNums[indexV] != array[indexA])
			{	uniqueNums.push_back(array[indexA]);
				indexA++;
				indexV++;	}
	}

	// This for loop counts how many any of the numbers held
	// in the uniqueNums vector happens in the original array
	for (int numV = 0; numV < uniqueNums.size(); numV++)
	{
		for (int numA =0; numA < size; numA++)
		{
			if (uniqueNums[numV] == array[numA])
				count++;
		}
		numNums.push_back(count);
		count = 0;
	}

	// This loop determs which are the highest incidence.
	highHold = numNums[0];
	for (int num =1; num < numNums.size(); num++)
	{
		if (numNums[num] > highHold)
			highHold = numNums[num];
	}

	// When the highHold number matches the space in the
	// numNums vector, it will push the value from the parallel
	// uniqueNums vector into the modeHolder
	for (int num=0; num < numNums.size(); num++)
	{
		if (numNums[num] == highHold)
			modeHolder.push_back(uniqueNums[num]);
	}

	return modeHolder;
}