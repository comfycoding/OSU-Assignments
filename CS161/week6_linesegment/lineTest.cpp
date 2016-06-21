// ass6 test

#include <iostream>
#include <cmath>
#include "LineSegment.hpp"
using namespace std;

int main()
{
	LineSegment line1;
	double testx, testy, testx2, testy2;

	cout << "Set test X Coordinate for line1: ";
	cin >> testx;
	cout << "Set test Y Coordinate for line1: ";
	cin >> testy;
	line1.setEnd1(testx, testy);
	cout << "line1 of LineSegment class received " << testx << ", " << testy << " which should be set through the Point class." << endl;
	cout << "The first end point of line segment line1 is "; line1.getEnd1();

	cout << "\n\nSet second test X coordinate for line1: ";
	cin >> testx2;
	cout << "\nSet second test Y Coordinate for line1: ";
	cin >> testy2;
	line1.setEnd2(testx2, testy2);
	cout << "line1 of LineSegment class received " << testx2 << ", " << testy2 << " which should be set through the Point class." << endl;
	cout << "The second end point of line segment line1 is "; line1.getEnd2();

	cout << "\n\nThe distance between the two is " << line1.length() << endl;
	cout << "The slope of line1 is " << line1.slope() << endl;
	return 0;
}

