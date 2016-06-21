/*********************************************************************
** Program Filename: TimeTests.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: The functions of the TimeTest class.
** I found the information to use the chrono library here:
** https://solarianprogrammer.com/2012/10/14/cpp-11-timing-code-performance/
*********************************************************************/

#include "TimeTests.hpp"
#include "Factorial.cpp"
#include "Fibonacci.cpp"
#include "Menu.cpp"
#include <iostream>
#include <chrono>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

/*********************************************************************
 ** Function: testRecursion
 ** Description: This requests a value for n to run through two
 ** functions that find an nth fibonacci number. It uses one recursive
 ** function and one nonrecursive function to find the same answer,
 ** which is printed and can be confirmed by the user.
 ** It uses the chrono library to find the time elapsed in milliseconds.
 ** This function prints which method was faster, and also increases
 ** a counter for that method in order to be displayed with the results
 ** of tests completed.
 ** The value for n and the time elapsed for both functions are recorded
 ** in lists to be referred to when displaying tests.
 *********************************************************************/

void TimeTest::testRecursion()
{
    cout << "\nThe recursive and nonrecursive functions are tested by running a Fibonacci problem." << endl;
    cout << "\nEnter a number to test in each of the Fibonacci programs: ";
    count ++;
    int n = getOne();
    nList.push_back(n);
    double t1, t2;
    double diff;

    auto startOne = std::chrono::steady_clock::now();
    cout << "\nThe " << n << "th fibonacci, according to the recursive function, is " << recursiveFib(n) << "." << endl;
    auto endOne = std::chrono::steady_clock::now();
    auto diffOne = endOne - startOne;
    t1 = std::chrono::duration <double, std::milli> (diffOne).count();
    cout << "The recursive function took " << t1 << " milliseconds." << endl;
    recTime.push_back(t1);

    auto startTwo = std::chrono::steady_clock::now();
    cout << "The " << n << "th fibonnaci, according to the nonrecursive function, is " << nonrecursiveFib(n) << "." << endl;
    auto endTwo = std::chrono::steady_clock::now();
    auto diffTwo = endTwo - startTwo;
    t2 = std::chrono::duration <double, std::milli> (diffTwo).count();
    cout << "The nonrecursive function took " << t2 << " milliseconds." << endl;
    nonrecTime.push_back(t2);

    if (t1 > t2)
    {
        diff = t1 - t2;
        cout << "The difference is " << diff << " milliseconds, and the nonrecursive function was faster." << endl;
        difference.push_back(diff);
        nonrCount ++;
    }
    else
    {
        diff = t2 - t1;
        cout << "The difference is " << diff << " milliseconds, and the recursive function was faster." << endl;
        difference.push_back(diff);
        rCount ++;
    }
}

/*********************************************************************
 ** Function: testTailRecursion()
 ** Description: Tests the run time between a tail recursive function
 ** and a non-tail recursive function. Requests a value for n, receives
 ** the same value from both functions, and compares the time (in milliseconds)
 ** that it took for each of the functions to run.
 ** The values for n, as well as the time elapsed to run each function
 ** are pushed to vectors to be displayed later.
 *********************************************************************/

void TimeTest::testTailRecursion()
{
    cout << "\nThe tail recursive and non-tail recursive functions are tested by calculating a factorial." << endl;
    cout << "\nEnter a number to find it's factorial with each of the functions: ";
    countTails ++;
    int n = getOne();
    tList.push_back(n);
    double t1, t2;
    double diff;

    auto startOne = std::chrono::steady_clock::now();
    cout << "\nThe factorial of " << n << ", according to the tail recursive function, is " << factorial(n) << "." << endl;
    auto endOne = std::chrono::steady_clock::now();
    auto diffOne = endOne - startOne;
    t1 = std::chrono::duration <double, std::milli> (diffOne).count();
    cout << "The tail recursive function took " << t1 << " milliseconds." << endl;
    tailTime.push_back(t1);

    auto startTwo = std::chrono::steady_clock::now();
    cout << "\nThe factorial of " << n << ", according to the non-tail recursive function is " << rfactorial(n) << "." << endl;
    auto endTwo = std::chrono::steady_clock::now();
    auto diffTwo = endTwo - startTwo;
    t2 = std::chrono::duration <double, std::milli> (diffTwo).count();
    cout << "The non-tail recursive function took " << t2 << " milliseconds." << endl;
    nontailTime.push_back(t2);

    if (t1 > t2)
    {
        diff = t1 - t2;
        cout << "The difference is " << diff << " milliseconds, and the non-tail recursive function was faster." << endl;
        tDifference.push_back(diff);
        nontCount ++;
    }
    else
    {
        diff = t2 - t1;
        cout << "The difference is " << diff << " milliseconds, and the tail recursive function was faster." << endl;
        tDifference.push_back(diff);
        tCount ++;
    }
}

/*********************************************************************
 ** Function: displayResults()
 ** Description: Displays the results of each test, which have been
 ** broken into two functions.
 *********************************************************************/

void TimeTest::displayResults()
{
    // First, display the results of the recursive function tests
    // The program checks if no tests have been conducted.
    fibResults();

    // Then display the results of the tail recursive function tests
    // Again check if no tests have been conducted.
    facResults();
}

/*********************************************************************
 ** Function: fibResults
 ** Description: Displays the results from the fibonacci tests. first
 ** checks that the vector that holds the values for n is not empty,
 ** otherwise it cycles through the vectors to display the appropriate
 ** information. It also shows which function was faster, and at the end
 ** shows how many times each method ran faster.
 *********************************************************************/

void TimeTest::fibResults()
{
    if (nList.empty())
    {
        cout << "You have not run any tests yet between the recursive and nonrecursive functions." << endl;
        cout << "Run a test and try again." << endl;
    }
    else
    {
        cout << "\nThese are the current results for the Fibonacci tests, which tested recursive and nonrecursive function times: " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Test " << i + 1 << ": " << endl;
            cout << "\tValue for n: " << nList.at(i) << endl;
            cout << "\tTest time for the recursive function: " << recTime.at(i) << " milliseconds" << endl;
            cout << "\tTest time for the nonrecursive function: " << nonrecTime.at(i) << " milliseconds" << endl;
            cout << "\tDifference in test time: " << difference.at(i) << endl;
            if (recTime.at(i) > nonrecTime.at(i))
                cout << "\tThe nonrecursive function was faster" << endl;
            else
                cout << "\tThe recursive function was faster" << endl;
        }
        cout << "The recursive test was faster " << rCount << " times, and the nonrecursive test was faster " << nonrCount << " times." << endl;
    }
}

/*********************************************************************
 ** Function: facResults()
 ** Description: Displays the results from the factorial tests. first
 ** checks that the vector that holds the values for n is not empty,
 ** otherwise it cycles through the vectors to display the appropriate
 ** information. It also shows which function was faster, and at the end
 ** shows how many times each method ran faster.
 *********************************************************************/

void TimeTest::facResults()
{
    if (tList.empty())
    {
        cout << "\nYou have not run any tests yet between the tail recursive and non-tail recursive functions." << endl;
        cout << "Run a test and try again." << endl;
    }
    else
    {
        cout << "\nThese are the current results of the factorial tests, which tested tail recursive and non-tail recursive function times: " << endl;
        for (int i = 0; i < countTails; i++)
        {
            cout << "Test " << i + 1 << ": " << endl;
            cout << "\tValue for n: " << tList.at(i) << endl;
            cout << "\tTest time for the tail recursive function: " << tailTime.at(i) << " milliseconds" << endl;
            cout << "\tTest time for the non-tail recursive function: " << nontailTime.at(i) << " milliseconds" << endl;
            cout << "\tDifference in test time: " << tDifference.at(i) << endl;
            if (tailTime.at(i) > nontailTime.at(i))
                cout << "\tThe non-tail recursive function was faster" << endl;
            else
                cout << "\tThe tail recursive function was faster" << endl;
        }
        cout << "The tail recursive test was faster " << tCount << " times, and the non-tail recursive test was faster " << nontCount << " times." << endl;
    }
}
