/*********************************************************************
** Author: Darlene Zouras
** Date: January 17, 2016
** Description: Project 3.a
This program takes a number of integers (set by the user) and returns
the smallest and largest of those integers.
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int numInt, loopNum, numBig, numSmall, num=1;

	cout << "How many integers would you like to enter?\n";
	cin >> numInt;

	cout << "Please enter " << numInt << " integers.\n";
	do {
		cin >> loopNum;

		if (num==1)
		{
			numSmall = loopNum;
			numBig = loopNum;
		}
		else if (loopNum > numBig)
			numBig = loopNum;
		else if (loopNum < numSmall)
			numSmall = loopNum;

		num++;
	} while (num <= numInt);

	cout << "min: " << numSmall << endl;
	cout << "max: " << numBig << endl;
	return 0;
}