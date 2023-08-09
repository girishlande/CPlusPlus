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
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    Solution() {
        off.clear();
        off.push_back(std::make_pair(0, 1));
        off.push_back(std::make_pair(1, 0));
        off.push_back(std::make_pair(0, -1));
        off.push_back(std::make_pair(-1, 0));
    }
    bool validPosition(vector<vector<char>>& b, int row, int col) {
        if (row < 0 || col < 0)
            return false;
        if (row < b.size()) {
            return col < b[row].size();
        }
        return false;
    }
    bool cexist(vector<vector<char>>& board, string word, set<pair<int,int>>& v, int row, int col, int pos) {
        if (pos == word.length())
            return true;
        char current = word[pos];
        for (auto a : off) {
            int nrow = row + a.first;
            int ncol = col + a.second;
            if (validPosition(board,nrow, ncol)) {
                if (v.find({ nrow,ncol }) != v.end())
                    continue;
                if (current == board[nrow][ncol]) {
                    v.insert({ nrow,ncol });
                    bool result = cexist(board, word, v, nrow, ncol, pos + 1);
                    if (result)
                        return true;
                    v.erase({ nrow,ncol });
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return false;
        vector< pair<int, int>> v;
        char f = word[0];
        int i = 0;
        int j = 0;
        for (auto a : board) {
            int j = 0;
            for (auto ch : a) {
                if (ch == f) {
                    v.push_back(std::make_pair(i, j));
                }
                j++;
            }
            i++;
        }

        // Check if word exists starting from (row,col)
        for (auto p : v) {
            int row = p.first;
            int col = p.second;

            set<pair<int, int>> v;
            v.insert({ row,col });
            bool found = cexist(board, word, v, row, col, 1);
            if (found)
                return true;
        }
        return false;
    }

    vector<pair<int, int>> off;
};

int main()
{
    //vector<vector<char>> b = { {'A','B','C','E'} ,{'S','F','C','S'},{'A','D','E','E'} };
    //vector<vector<char>> b = { {'A', 'B', 'C', 'E'} ,{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
    vector<vector<char>> b = { {'A', 'B', 'C', 'E'} ,{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
    string word = "SEE";
    bool found = Solution().exist(b, word);
    cout << "Found:" << found;
    /*for (auto a : b) {
        for (auto v : a) {
            cout << v << " ";
        }
        cout << "\n";
    }*/
}

