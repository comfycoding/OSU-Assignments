/*********************************************************************
** Author: Darlene Zouras
** Date: January 7, 2016
** Description: Project 2.a
	This program requests five numbers from the user and returns the average of the five numbers.
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	float var1, var2, var3, var4, var5;

	cout << "Please enter five numbers.\n";
	cin >> var1;
	cin >> var2;
	cin >> var3;
	cin >> var4;
	cin >> var5;

	float out = (var1 + var2 + var3 + var4 + var5) / 5;

	cout << "The average of those numbers is:\n" << out << endl;
	return 0;
}