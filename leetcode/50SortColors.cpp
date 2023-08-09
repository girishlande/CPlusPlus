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
#include <sstream>
#include<set>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int g = 0;
        int b = 0;
        for (int c : nums) {
            if (c == 0) r++;
            if (c == 1) g++;
            if (c == 2) b++;
        }
        int i = 0;
        while (r-- > 0) {
            nums[i++] = 0;
        }
        while (g-- > 0) {
            nums[i++] = 1;
        }
        while (b-- > 0) {
            nums[i++] = 2;
        }
    }
};

int main()
{
    vector<int> m = { 2,0,2,1,1,0 };

    Solution().sortColors(m);
    for (auto a : m) {
        cout << a << " ";
    }

}

