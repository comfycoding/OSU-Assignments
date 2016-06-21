/*********************************************************************
** Author: Darlene Zouras
** Date: January 7, 2016
** Description: Project 2.c
	This program asks for a number of cents and returns how many of each coin they would recieve for the smallest number of coins	
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int change, varQ, varD, varN, varP;

	cout << "Please enter an amount in cents less than a dollar.\n";
	cin >> change;

	varQ = change / 25;
	change = change % 25;
	varD = change / 10;
	change = change % 10;
	varN = change / 5;
	change = change % 5;
	varP = change;

	cout << "Your change will be:\n";
	cout << "Q: " << varQ << endl;
	cout << "D: " << varD << endl;
	cout << "N: " << varN << endl;
	cout << "P: " << varP << endl;

	return 0;
}