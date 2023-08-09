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

    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int lsum = sum;
        for (size_t i = 1; i < nums.size();i++) {
            int c = nums[i];
            if ((sum + c) > sum && (sum + c) > c) {
                sum = sum + c;
            } else if (c > sum) {
                sum = c;
            } else {
                sum = sum + c;
            }
            
            if (sum > lsum) {
                lsum = sum;
            }
        }
        return lsum;
    }
};

int main()
{
    //vector<int> v{ -2,1,-3,4,-1,2,1,-5,4 };
    //vector<int> v{ 5,4,-1,7,8 };
    //vector<int> v{ 1 };
    vector<int> v{ 1,2 };
    cout << Solution().maxSubArray(v);

}

