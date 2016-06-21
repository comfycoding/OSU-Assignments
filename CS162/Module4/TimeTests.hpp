/*********************************************************************
** Program Filename: TimeTests.hpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: The header file of the TimeTest class
*********************************************************************/

#ifndef TIMETESTS_HPP
#define TIMETESTS_HPP
#include <vector>
using std::vector;

class TimeTest
{
private:
    // These vectors will hold the information tested by this program
    vector<int> nList, tList;
    vector<double> recTime, nonrecTime, difference;
    vector<double> tailTime, nontailTime, tDifference;
    int count, countTails;
    int rCount, nonrCount;
    int tCount, nontCount;

public:
    // The constructor initializes all of the counters to 0.
    TimeTest() {
        int count = 0, countTails = 0;
        // Counters to help move through the recursive function results
        int rCount = 0, nonrCount = 0;
        // Counters to help move through the tail recursive function results
        int tCount = 0, nontCount = 0;
    }
    void testRecursion();
    void testTailRecursion();
    void displayResults();
    void fibResults();
    void facResults();
};

#endif
