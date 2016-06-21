/*********************************************************************
** Author: Darlene Zouras
** Date: January 17, 2016
** Description: Project 3.b
Prompts the user to input the name of a text file that holds a series of integers,
it opens and reads that text file, closes it, and writes a new text file 
that has the sum of the numbers from the original file.
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream inputFile;					// file stream objects
	ofstream outputFile; 	
	string filename;		
	int nums, numSum = 0, numOfNums = 0;					// numbers read within file

	cout << "enter the filename: " << endl;
	cin >> filename;

	inputFile.open(filename.c_str()); 	// opens the input file

	if (inputFile.fail())
		cout << "could not access file\n";
	else
	{
		cout << "reading file\n";
		while (inputFile >> nums)		// runs as long as a value is read
			{
				numSum += nums;
				numOfNums++;
			}
		inputFile.close();

		outputFile.open("sum.txt");		// opens file to be written
		outputFile << numSum << endl;
		outputFile.close();
		cout << "sum.txt written\n";
	}

	return 0;
}