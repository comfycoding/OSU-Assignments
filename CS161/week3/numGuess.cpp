/*********************************************************************
** Author: Darlene Zouras
** Date: January 17,2016
** Description: Project 3.c
A guessing game where a user inputs an integer, and someone attempts
to guess the number. The program loops to display whether a guess is
too high or too low, counts the number of attempts, and will display
that number when the guess has been made.
*********************************************************************/

#include <iostream>
using namespace std;

int main ()
{
	int num, guess,
		tries = 1;

	cout << "Enter the number for the player to guess.\n";
	cin >> num;

	cout << "Enter your guess.\n";
	cin >> guess;
	while (guess != num)
	{
		if (guess > num){
			tries ++;
			cout << "Too high - try again.\n";
			cin >> guess;
		}
		if (guess < num){
			tries ++;
			cout << "Too low - try again.\n";
			cin >> guess;
		}
	}
	
	if (tries == 1) {
		cout << "You guessed it in 1 try.\n";
	}
	else {
		cout << "You guessed it in " << tries << " tries.\n";
	}
	return 0;
}