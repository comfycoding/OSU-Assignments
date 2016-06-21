/*********************************************************************
** Author: Darlene Zouras
** Date: January 25, 2016
** Description: Project 4.a
** This program uses a formula to determine the distance an object
** falls due to gravity for a specific time period. The falling time is
** received as the argument and the function returns the distance
** that the object has fallen for that time.
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

const double gravity = 9.8;

//function prototype
double fallDistance(double fallTime);

/*int main ()
{
	double distance;
	double fTime;

	cout << "In main, input a number a falling time\n";
	cin >> fTime;
	distance = (0.5 * gravity * pow(fTime, 2.0));
	cout << "In main, the equation equals " << distance << endl;
	cout << fTime << " will be sent to the fallDistance function.\n\n";

	distance = fallDistance(fTime);

	cout << "The distance returned to the main function was " << distance << endl;
	return 0;
}*/

/*********************************************************************
** Description:
** The fallDistance function receives the fall time from the main
** function and uses a formula to return the fall distance.
*********************************************************************/
double fallDistance(double fallTime)
{
	return (0.5 * gravity * pow(fallTime, 2.0));
}