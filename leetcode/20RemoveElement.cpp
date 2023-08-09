// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;

        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};


int main()
{
    vector<int> v1 = { 1,1,1,2,2,3,3 };
    for (auto i : v1)
        cout << i << " ";
    cout << "\n";
    int k = Solution().removeElement(v1,2);
    for (auto i : v1)
        cout << i << " ";
    cout << "\nK:" << k;
}

