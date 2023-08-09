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
    void merge2(vector<int>& v1, vector<int>& v2, vector<int>& v3) {
        set<int> r;
        for (int x : v1) {
            r.insert(x);
        }
        for (int y : v2) {
            r.insert(y);
        }
        v3.clear();
        v3.push_back(*(r.begin()));
        auto it = r.end();
        --it;
        v3.push_back(*it);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> r;
        set<int> processed;
        int i = 0;
        int size = intervals.size();
        while (i < size) {
            vector<int> c1 = intervals[i];
            if (processed.find(i) != processed.end()) {
                i++;
                continue;
            }
            for (int j = i + 1; j < size; j++) {
                if (processed.find(j) != processed.end()) {
                    continue;
                }
                vector<int>& c2 = intervals[j];
                if ((c1[1] >= c2[0] && c1[1] <= c2[1]) ||
                    (c2[1] >= c1[0] && c2[1] <= c1[1])) {
                    vector<int> c3;
                    merge2(c1, c2, c3);
                    processed.insert(j);
                    processed.insert(i);
                    intervals.push_back(c3);
                    break;
                }
            }
            i++;
            size = intervals.size();
        }

        for (int i = 0; i < intervals.size(); i++) {
            if (processed.find(i) == processed.end()) {
                r.push_back(intervals[i]);
            }
        }
        return r;
    }
};

int main()
{
    //vector<vector<int>> nums{ {1,3} ,{2,6},{8,10},{15,18} };
    //vector<vector<int>> nums{ {1, 4} ,{4, 5} };
    vector<vector<int>> nums{{2, 3}, { 4, 6 }, { 5, 7 }, { 3, 4 }};
    //vector<vector<int>> nums{ {2, 3},{4, 5},{6, 7},{8, 9},{1, 10} };

    vector<vector<int>> v = Solution().merge(nums);
    for (auto a : v) {
        cout << "[";
        for (auto b : a) {
            cout << b << ",";
        }
        cout << "]";
        cout << ",";
    }
}

