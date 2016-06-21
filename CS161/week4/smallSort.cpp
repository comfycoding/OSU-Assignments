/*********************************************************************
** Author: Darlene Zouras
** Date: January 26, 2016
** Description: Project 4.b
** This void function takes three int paremeters by reference and sorts
** their values from the smallest number to the largest.
*********************************************************************/

#include <iostream>
using namespace std;

//function prototype
void smallSort(int &numA, int &numB, int &numC);

/*int main()
{
	int a = 7;
	int b = 5;
	int c = 9;
	cout << "In main, a is " << a << ", b is " << b << ", and c is " << c << ".\n";
	smallSort(a, b, c);
	cout << "Now, a is " << a << ", b is " << b << ", and c is " << c << ".\n";
}*/

/*********************************************************************
** Description:
** The smallSort function uses three reference variables and sorts
** them in ascending order through a loop until each number is in
** order from smallest to largest.
*********************************************************************/
void smallSort(int &numA, int &numB, int &numC)
{
	// these variables exist to temporarily hold the num variables
	// while they are being swapped
	int holdA, holdB, holdC;

	while (numA > numB || numA > numC || numB > numC)
	{
		if (numA > numB){
			holdB = numB;
			holdA = numA;
			numA = holdB;
			numB = holdA;
		}
		if (numB > numC){
			holdC = numC;
			holdB = numB;
			numB = holdC;
			numC = holdB;
		}
	}
}	