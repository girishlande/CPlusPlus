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
#include <map>
using namespace std;

class Solution {
public:
    void f(int i, int k, int n, vector<int>& cache, vector<vector<int>>& r) {
        if (k == 1) {
            cache.push_back(i);
            r.push_back(cache);
            cache.pop_back();
        }
        else {
            int c = 0;
            cache.push_back(i);
            for (int j = i+1; j <= n; j++, c++) {
                f(j, k-1, n, cache, r);
            }
            cache.pop_back();
        }
    }

    vector<vector<int>> comb(int n, int k) {
        vector<vector<int>> r;
        for (int i = 1; i <= n; i++) {
            vector<int> cache;
            f(i, k, n, cache, r);
        }
        return r;
    }
};

int main()
{
    vector<vector<int>> r = Solution().comb(1, 1);
    for (auto a : r) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << "\n";
    }

}

