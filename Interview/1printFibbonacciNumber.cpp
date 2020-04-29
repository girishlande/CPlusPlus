
#include <iostream>
using namespace std;

// Write a function to print nth number in Fibonacci series?
// 1 1 2 3 5 8 13 21 ...
// e.g fibbo(6) = 8
//     fibbo(2) = 1

// write definition of following function
int fibbo(int n);

int main()
{
    cout << fibbo(1) << endl;
    cout << fibbo(2) << endl;
    cout << fibbo(3) << endl;
    cout << fibbo(4) << endl;
    cout << fibbo(5) << endl;
    cout << fibbo(6) << endl;

    return 0;
}

int fibbo(int n)
{
    if (n <= 1)
        return n;
    return fibbo(n - 1) + fibbo(n - 2);
}