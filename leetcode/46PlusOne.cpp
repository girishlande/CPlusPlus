// ConsoleApplication20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {
        list<int> r;
        int carry = 1;
        for (int i = digits.size()-1; i >=0; i--) {
            int d = digits[i];
            if (d == 9) {
                carry = 1;
                r.push_front(0);
            }
            else {
                r.push_front(d + carry);
                carry = 0;
            }
        }
        if (carry) {
            r.push_front(carry);
        }
        std::vector<int> rv{ std::begin(r), std::end(r) };
        return rv;
    }
};

int main()
{
    vector<int> digits{ 9,0,9,0,9,0,9,0,0,9 };
    vector<int> v = Solution().plusOne(digits);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }


}

