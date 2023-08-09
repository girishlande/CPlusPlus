// ConsoleApplication16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

class Solution {
public:

    int jump(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return 0;
        }
        int jumpcount = 0;
        for (int i = 0; i < nums.size(); ) {

            int c = nums[i];
            int w = 0;
            int maxw = 0;
            int maxIndex = i + 1;
            for (int j = i + c; j > i; j--) {
                if (j >= nums.size()-1) {
                    jumpcount++;
                    return jumpcount;
                }
                int cw = nums[j] - w;
                if (cw > maxw) {
                    maxw = cw;
                    maxIndex = j;
                }
                w++;
            }
            i = maxIndex;
            jumpcount++;
            if (i == nums.size()) {
                break;
            }
        }

        return jumpcount;
    }
};

int main()
{
    vector<int> a{ 2,3,0,1,4 };
    int x = Solution().jump(a);
    cout << x;
}


