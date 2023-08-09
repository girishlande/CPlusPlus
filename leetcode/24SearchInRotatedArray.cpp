// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int searchRange(vector<int>& nums, int target, int lower, int higher) {
        if (nums[lower] == target) return lower;
        if (nums[higher] == target) return higher;

        int mid = (lower + higher)/2;
        if (nums[mid] == target) return mid;
        if (mid == lower || mid == higher) return -1;

        int lowValue = nums[lower];
        int highValue = nums[higher];
        int midValue = nums[mid];
        if (lowValue < highValue) {
            // sorted array 
            if (target > midValue && target < highValue)
                return searchRange(nums, target, mid, higher);
            else if (target < midValue && target > lowValue)
                return searchRange(nums, target, lower, mid);
            else
                return -1;
        }
        else {
            //  rotated array 
            if (target > lowValue) {
                if (target > midValue) {
                    if (midValue < lowValue) {
                        return searchRange(nums, target, lower, mid);
                    }
                    else {
                        return searchRange(nums, target, mid, higher);
                    }
                }
                else {
                    return searchRange(nums, target, lower, mid);
                }
            }
            else {
                if (target < midValue) {
                    if (lowValue < midValue) {
                        return searchRange(nums, target, mid, higher);
                    }
                    else {
                        return searchRange(nums, target, lower, mid);
                    }
                }
                else {
                    return searchRange(nums, target, mid, higher);
                }
            }
        }
    }
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int highter = nums.size()-1;
        return searchRange(nums, target, lower, highter);
    }
};


int main()
{
    vector<int> nums = { 4,5,6,7,8,1,2,3};
    int target = 8;
    
    /*vector<int> nums = { 5,1,2,3,4};
    int target = 1;*/

    /*vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;*/
    int index = Solution().search(nums, target);
    cout << "\n" << "search :" << target << " = " << index;
}

