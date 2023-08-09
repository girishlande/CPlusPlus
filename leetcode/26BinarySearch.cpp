// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <assert.h>

using namespace std;

class Solution {
public:

    int binarySearch(vector<int>& nums, int target, int lower, int higher) {
        if (nums[lower] == target) return lower;
        if (nums[higher] == target) return higher;
        if (target < nums[lower]) return lower;
        if (target > nums[higher]) return higher+1;

        int mid = (lower + higher) / 2;
        if (mid == lower || mid==higher) {
            if (target < nums[mid]) {
                return mid;
            }
            else {
                return higher;
            }
        }
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) {
            return binarySearch(nums, target, mid, higher);
        }
        else {
            return binarySearch(nums, target, lower, mid);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int lower = 0;
        int higher = nums.size() - 1;
        return binarySearch(nums, target, lower, higher);

        return 0;
    }

};


int main()
{
    vector<int> nums = { 1,2,3,4,5,10 };
    int target = 2;

    /*vector<int> nums = { 5,1,2,3,4};
    int target = 1;*/

    /*vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;*/
    int r = Solution().searchInsert(nums, target);
    cout << "\nPosition:" << r;
}

