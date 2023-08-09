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

    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> c;

        for (int j = 0; j < matrix.size(); j++) {
            vector<int> t;
            for (int i = matrix.size() - 1; i >= 0; i--) {
                vector<int>& x = matrix[i];
                t.push_back(x[j]);
            }
            c.push_back(t);
        }

        matrix = c;
    }
};

int main()
{
    vector<vector<int>> m{ {1, 2, 3} ,{4, 5, 6},{7, 8, 9} };
    for (int i = 0; i < m.size(); i++) {
        vector<int>& x = m[i];
        for (auto a : x) {
            cout << a << " ";
        }
        cout << "\n";
    }

    Solution().rotate(m);

    cout << "\n after rotating:\n";
    for (int i = 0; i < m.size(); i++) {
        vector<int>& x = m[i];
        for (auto a : x) {
            cout << a << " ";
        }
        cout << "\n";
    }


}

//Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//    Output : [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
//
//    Input : matrix = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
//    Output : [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]