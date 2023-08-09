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
    vector<int> searchRangeFromSeed(vector<int>& nums, int seed, int target) {

    }

    bool searchSeedPoint(vector<int>& nums, int target, int& seedPoint, int& previous) {

        previous = 0;
        int i = 0;
        for (i = 0; i < nums.size(); ) {
            if (nums[i] == target) {
                seedPoint = i;
                return true;
            }
            else {
                previous = i;

                // check if we crossed the range 
                if (nums[i] > target) {

                    // start searching backward direction linearly
                    int j = i;
                    while (j > previous) {
                        if (nums[j] == target) {
                            seedPoint = j;
                            return true;
                        }
                        j--;
                    }
                    return false;
                }

                // Increment i exponentially
                if (i == 0) {
                    i = 1;
                }
                else {
                    i = i * 2;
                }
            }
        }

        int j = i - 1;
        while (j > previous) {
            if (nums[j] == target) {
                seedPoint = j;
                return true;
            }
            j--;
        }
        return false;
    }

    void notFoundVector(vector<int>& vec) {
        vec.clear();
        vec.push_back(-1);
        vec.push_back(-1);
    }

    bool searchRight(vector<int>& nums, int target, int& startIndex,int& rightlimit, int& outindex) {
        int i = startIndex;
        int prev_i = i;
        int m = 1;
        while (i <= rightlimit) {
            if (nums[i] == target) {
                outindex = i;
                return true;
            }
            else {
                if (target < nums[i]) {
                    break;
                }
                prev_i = i;
                i = i + m;
                m = m * 2;
            }
        }

        startIndex = prev_i;
        rightlimit = i;
        return false;
    }

    bool searchLeft(vector<int>& nums, int target, int& startIndex, int& leftlimit, int& outindex) {
        int i = startIndex;
        int prev_i = i;
        int m = 1;
        while (i >= leftlimit) {
            if (nums[i] == target) {
                outindex = i;
                return true;
            }
            else {
                if (target > nums[i]) {
                    break;
                }
                prev_i = i;
                i = i - m;
                m = m * 2;
            }
        }

        startIndex = prev_i;
        leftlimit = i;
        return false;
    }

    // Search in right direction.
    // If found search in right further as long as you don't reach end
    // If not found, search left in last returned range.
    // If not found search in right in last returned range. 
    // Till you find or it reached end.

    vector<int> searchRange1(vector<int>& nums, int target) {
        vector<int> output;
        int size = nums.size();
        if (size == 0) {
            notFoundVector(output);
            return output;
        }
        if (nums[0] > target || target > nums[size - 1]) {
            notFoundVector(output);
            return output;
        }
        int outindex = 0;
        int startIndex = 0;
        int rightlimit = nums.size() - 1;
        bool found = searchRight(nums, target, startIndex, rightlimit, outindex);
        while (!found) {
            if (startIndex == rightlimit) {
                break;
            }
            found = searchRight(nums, target, startIndex, rightlimit, outindex);
        }

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> r;
        int prev = 0;
        int seedPoint = 0;

        // Find first occurance of target 
        bool refFound = searchSeedPoint(nums, target, seedPoint, prev);

        if (!refFound) {
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }

        int i = seedPoint;
        // Find first occurance
        while (i > prev) {
            if (nums[i] == target) {
                i--;
            }
            else {
                i++;
                break;
            }
        }
        r.push_back(i);
    }


    bool RightSearch(vector<int>& a, int t, int startIndex, int& limit) {
        assert(startIndex < limit);

        int size = a.size();
        int i = startIndex;
        while (i < size) {
            if (a[i] == t) {
                return i;
            }
            else if (a[i] > t) {
                limit = i;
                return false;  // not found
            }
            else {

            }
        }
    }
};


int main()
{
    vector<int> nums = { 5,7,7,8,8,10 };
    int target = 8;

    /*vector<int> nums = { 5,1,2,3,4};
    int target = 1;*/

    /*vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;*/
    vector<int> r = Solution().searchRange1(nums, target);

}

