// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = false;
        if (dividend < 0) {
            dividend *= -1;
            flag = !flag;
        }
        if (divisor < 0) {
            divisor *= -1;
            flag = !flag;
        }
        int ans = 0;
        while (dividend > 0) {
            dividend = dividend - divisor;
            if(dividend>=0)
                ans++;
        }

        if (flag)
            ans *= -1;

        return ans;
    }
};


int main()
{
    int dividend = -47483648;
    int divisor = -1;
    int k = Solution().divide(dividend, divisor);
    cout << "\nK:" << k;
}

