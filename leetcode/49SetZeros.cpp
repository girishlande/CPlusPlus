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

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> r;
        set<int> c;
        int i = 0;
        int j = 0;
        for (auto& rm : matrix) {
            j = 0;
            for (auto& cm : rm) {
                if (cm == 0) {
                    c.insert(j);
                    r.insert(i);
                }
                j++;
            }
            i++;
        }

        for (int i = 0; i < matrix.size(); i++) {
            vector<int>& v = matrix[i];
            bool f1 = false;
            if (r.find(i) != r.end()) {
                f1 = true;
            }
            for (int j = 0; j < v.size(); j++) {
                if (f1) {
                    v[j] = 0;
                }
                else if (c.find(j) != c.end()) {
                    v[j] = 0;
                }
            }
        }

    }
};

int main()
{
    //vector<vector<int>> m = { {1,1,1} ,{1,0,1},{1,1,1} };
    vector<vector<int>> m = { {0,1,2,0} ,{3,4,5,2},{1,3,1,5} };

    Solution().setZeroes(m);

    for (int i = 0; i < m.size(); i++) {
        vector<int>& v = m[i];
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << "\n";
    }

}

