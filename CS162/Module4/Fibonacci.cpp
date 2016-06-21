/*********************************************************************
** Program Filename: Fibonacci.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description:
** These functions find an Nth fibonacci numbers,
** found on http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
** written by Julian in September, 2010.
** I have altered these functions only by changing their names.
*********************************************************************/

// the recursive function to find an nth factorial
int recursiveFib(int n)
{
  	if(n==0)
        return 0;
    else if(n==1)
        return 1;
    return ( recursiveFib(n-1) + recursiveFib(n-2) );
}

// and the nonrecursive function to find an nth factorial
int nonrecursiveFib(int n)
{
    int first =0;
    int second=1;
    int counter=2;
    while(counter < n)
    {
        int temp=second;
        second=first+second;
        first=temp;
        ++counter;
    }
    if(n==0)
        return 0;
    else
        return first+second;
}
