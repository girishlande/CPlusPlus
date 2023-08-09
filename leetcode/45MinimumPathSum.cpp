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

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
     
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<int>& t = grid[i];
                if (i == 0 && j==0) {
                    continue;
                }
                else if (i == 0) {
                    t[j] = t[j] + t[j - 1];
                }
                else if (j==0){
                    vector<int>& t1 = grid[i-1];
                    t[j] = t1[j] + t[j];
                }
                else {
                    vector<int>& t1 = grid[i - 1];
                    int left = t[j - 1];
                    int top = t1[j];
                    int curr = t[j];
                    if (left < top) {
                        t[j] = curr + left;
                    }
                    else {
                        t[j] = curr + top;
                    }
                }
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main()
{
    //vector<vector<int>> v1{ {1,0},{0,0} };
    //vector<vector<int>> v1{ {0, 0, 0} ,{0, 1, 0},{0, 0, 0} };
    vector<vector<int>> v1{ {1,2,3} ,{4,5,6} };
    cout << Solution().minPathSum(v1);



}

