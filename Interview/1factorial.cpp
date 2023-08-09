#include <iostream>
using namespace std;

// write a recursive function to return factorial of a input 
// for e.g factorial(5)
// output: 120

// write definition of following function declaration
int factorial(int n);

int main()
{
    cout << factorial(5);
    return 0;
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}
