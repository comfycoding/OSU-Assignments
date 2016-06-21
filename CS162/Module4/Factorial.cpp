/*********************************************************************
** Program Filename: Factorial.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: These functions find the factorial of n,
** and were printed in the Module 4 assignment document in May 2016.
** I did not edit them in any way.
*********************************************************************/

// the non-tail recursive function
long rfactorial (int n)
{
    if (n == 1)
        return 1;
    else
        return n * rfactorial(n - 1);
}

// and the tail recursive functions
long factorialHelper (int n, int result)
{
    if (n == 1)
        return result;
    else
        return factorialHelper(n - 1, n * result);
}

long factorial(int n)
{
    return factorialHelper(n, 1);
}
