/*********************************************************************
** Author: Darlene Zouras
** Date: January 7, 2016
** Description: Project 2.b
	This problem converts temperatures in Celsius to Farenheit.
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	float varC, varF;

	cout << "Please enter a Celsius temperature.\n";
	cin >> varC;

	varF = (9*varC)/5 + 32;

	cout << "The equivalent Farenheit temprature is:\n" << varF << endl;
	return 0;
}