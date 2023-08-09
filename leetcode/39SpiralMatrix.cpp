// ConsoleApplication17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:

    void updateDirection(int& dir, int i, int j, int& xmin, int& ymin, int& xmax, int& ymax) {
        switch (dir) {
        case 1: {
            if (i == xmax) {
                dir = 2;
                xmax--;
            }
            break;
        }
        case 2: {
            if (j == ymax) {
                dir = 3;
                ymax--;
            }
            break;
        }
        case 3: {
            if (i == xmin) {
                xmin++;
                dir = 4;
            }
            break;
        }
        case 4: {
            if (j == ymin) {
                ymin++;
                dir = 1;
            }
            break;
        }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        if (matrix.size() == 0) {
            return r;
        }
        int xmin = 0;
        int ymin = 1;
        int xmax = matrix[0].size()-1;
        int ymax = matrix.size()-1;
        int i = 0;
        int j = 0;
        
        int dir = 1;
        if (xmax == 0) {
            dir = 2;
        }
        bool breakflag = false;
        bool dirChange = false;
        while (1) {
            int v = matrix[j][i];
            r.push_back(matrix[j][i]);

            updateDirection(dir, i, j, xmin, ymin, xmax, ymax);
         
            if (dir == 1) {
                if (i == xmax) {
                    break;
                }
                i++;
            }
            else if (dir == 2) {
                if (j == ymax) {
                    break;
                }
                j++;
            }
            else if (dir == 3) {
                if (i == xmin) {
                    break;
                }
                i--;
            }
            else if (dir == 4) {
                if (j == ymin) {
                    break;
                }
                j--;
            }
        }


        return r;
    }
};

int main()
{
    //vector<vector<int>> v{ {1,2,3,4} ,{5,6,7,8},{9,10,11,12} };
    //vector<vector<int>> v{ {1} ,{2},{3},{4} };
    //vector<vector<int>> v{ {1,2,3,4} };
    vector<vector<int>> v{ {1} };
    vector<int> r = Solution().spiralOrder(v);
    for (auto a : r) {
        cout << a << "  ";
    }

}

