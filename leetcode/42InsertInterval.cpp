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
    void copyRest(vector<vector<int>>& input, vector<vector<int>>& output, size_t index) {
        for (size_t i = index; i < input.size(); i++) {
            output.push_back(input[i]);
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> r;
        if (intervals.size() == 0) {
            r.push_back(newInterval);
            return r;
        }
        int s = newInterval[0];
        int e = newInterval[1];
        for (size_t i = 0; i < intervals.size(); i++) {
            vector<int>& v = intervals[i];
            int v1 = v[0];
            int v2 = v[1];

            if (s <= v1 && e >= v2) {
                for (size_t j = i + 1; j < intervals.size(); j++) {
                    vector<int>& vj = intervals[j];
                    int v3 = vj[0];
                    int v4 = vj[1];
                    if (e < v3) {
                        r.push_back({ s,e });
                        copyRest(intervals, r, j);
                        return r;
                    }
                    if (e >= v3 && e <= v4) {
                        r.push_back({ s,v4 });
                        copyRest(intervals, r, j+1);
                        return r;
                    }
                }
                r.push_back({ s,e });
                return r;
            }
            if (s < v1 && e >= v1 && e <= v2) {
                r.push_back({ s,v2 });
                copyRest(intervals, r, i+1);
                return r;
            }
            if (s < v1 && e < v1) {
                // vector is smaller than next element
                r.push_back({ s,e });
                copyRest(intervals, r, i);
                return r;
            }
            if (s > v2 && e > v2) {
                // Vector is greater than current element
                r.push_back(v);
                continue;
            }
            if (s >= v1 && e <= v2) {
                // s is completely within bounds of some vector
                return intervals;
            }
            if (s >= v1 && s <= v2 && e > v2) {
                // overlapping with current vector. Find the end vector
                for (size_t j = i+1; j < intervals.size(); j++) {
                    vector<int>& vj = intervals[j];
                    int v3 = vj[0];
                    int v4 = vj[1];
                    if (e < v3) {
                        r.push_back({ v1,e });
                        copyRest(intervals, r, j);
                        return r;
                    }
                    else if (e >= v3 && e <= v4) {
                        r.push_back({ v1,v4 });
                        copyRest(intervals, r, j+1);
                        return r;
                    }
                }
                r.push_back({ v1,e });
                return r;
            }
        }

        if (intervals.size() == r.size()) {
            r.push_back(newInterval);
        }
        return r;
    }
};

int main()
{
    vector<vector<int>> nums = { {1,2},{3,5},{6,7},{8,10},{12,16} };
    vector<int> newint = { 4,8 };

    /*vector<vector<int>> nums = { {1,3} ,{6,9} };
    vector<int> newint = { 2,5 };*/
    //vector<int> newint = { 2,2 };

    /*vector<vector<int>> nums = { {1,2} ,{3,5},{6,7},{8,10},{12,16} }; 
    vector<int> newint = { 4,8 };*/

    vector<vector<int>> v = Solution().insert(nums,newint);
    for (auto a : v) {
        cout << "[";
        for (auto b : a) {
            cout << b << ",";
        }
        cout << "]";
        cout << ", ";
    }
}

