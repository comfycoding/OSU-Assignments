/*********************************************************************
** Author: Darlene Zouras
** Date: January 26, 2016
** Description: Project 4.c
** The function named hailstone receives a starting
** integer as its parameter and returns the number of steps it takes to
** reach 1. The function contains a while loop and nested if/else loops.
*********************************************************************/
#include <iostream>
using namespace std;

//function prototype
int hailstone(int startInt);

/*int main()
{
	int startInt;
	int num;

	cout << "Please enter a starting number.\n";
	cin >> startInt;
	num = hailstone(startInt);
	cout << "Number of steps to reach one is " << num << endl;

}*/

/*********************************************************************
** Description:
** The hailstone function receives an integer from the  main function
** and will run a while loop which contains if/else functions which
** determine whether the variable startInt is even or odd. Depending
** on that, it will run through one of two formulas until the startInt
** variable equals 1. The function counts and returns the number of
** iterations of the while loop.
*********************************************************************/
int hailstone(int startInt)
{
	int count=0;

	while (startInt != 1) {
		if (startInt % 2 == 0) {
			startInt = (startInt / 2);
			count++;
		}

		else {
			startInt = (startInt * 3) + 1;
			count++;
		}
	}

	return count;
}