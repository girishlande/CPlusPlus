// ConsoleApplication17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (x == 1.0) {
            return x;
        }
        long long an = abs(n);
        double r = x;
        for (int i = 1; i < an; i++) {
            r = r * x;
        }
        if (n < 0) {
            r = 1.0 / r;
        }
        return r;
    }
};

int main()
{
    // double x = 2.00000; int n = 10;
    // double x = 2.10000; int n = 3;
    // double x = 2.00000; int n = -2;
    // double x = 1.00000; int n = 2147483647;
    double x = 2.00000; long long n = -2147483648;

    cout << Solution().myPow(x, n);
}

