// write a function to find number of ways to climb 'n' stairs by using 1 or 2 steps at a time. 
// e.g 1 = 1, 2 = (1,1) (2), 3=(1,1,1) (1,2) (2,1), 4=(1,1,1,1)(1,1,2)(1,2,1)(2,1,1)(2,2)
//
// 1,2,3,5,

#include <iostream>
using namespace std;

// write a function to find number of ways to climb 'n' stairs by using 1 or 2 steps at a time.

int fibbo(int n)
{
    if (n <= 1)
        return n;
    return fibbo(n - 1) + fibbo(n - 2);
}

int countWays(int n)
{
    return fibbo(n + 1);
}

int main()
{
    cout << countWays(1) << endl;
    cout << countWays(2) << endl;
    cout << countWays(3) << endl;
    cout << countWays(4) << endl;

    return 0;
}


