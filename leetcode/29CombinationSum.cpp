// ConsoleApplication16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    void findNumbers(vector<int> ar, int sum, vector<vector<int>>& res, vector<int>& r, int i) {
        if (sum == 0) {
            res.push_back(r);
            return;
        }

        while (i < ar.size() && sum - ar[i] >= 0) {
            r.push_back(ar[i]);

            findNumbers(ar, sum - ar[i], res, r, i);
            i++;

            r.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        
        vector<int> r;
        vector<vector<int>> res;

        findNumbers(arr, target, res, r, 0);
        return res;
    }
};

int main()
{
    vector<int> n1{ 2,3,6,7 };
    vector<int> n2{ 2,3,4,5 };
    
    vector<vector<int>> res = Solution().combinationSum(n2,8);
    for (auto x : res) {
        cout << "[";
        for (auto y : x) {
            cout << y << ",";
        }
        cout << "]\n";
    }
    //vector<vector<int>> res = Solution().combinationSum(n2, 8);

}

