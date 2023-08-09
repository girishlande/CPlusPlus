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

    void displayBoard(vector<string>& b) {
        for (auto a : b) {
            for (auto c : a) {
                cout << c << " ";
            }
            cout << "\n";
        }
    }

    bool isSafe(vector<string>& board, int row, int col, int n) {
        
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q')
                return false;
        }
        {
            int r = row - 1;
            int c = col - 1;
            while (r >= 0 && c >= 0) {
                if (board[r][c] == 'Q')
                    return false;
                r--;
                c--;
            }
        }
        {
            int r = row + 1;
            int c = col - 1;
            while (r < n && c >= 0) {
                if (board[r][c] == 'Q')
                    return false;
                r++;
                c--;
            }
        }
        return true;
    }
    
    bool solveIt(vector<vector<string>>& r, vector<string>& board, int col, int n) {

        if (col >= n) {
            displayBoard(board);
            cout << "\n";
            r.push_back(board);
            return true;
        }

        for (int row = 0; row < n; row++) {

            if (isSafe(board, row, col, n)) {
                string& s = board[row];
                s[col] = 'Q';
                solveIt(r, board, col + 1, n);
                s[col] = '.';
            }
        }

        return false;

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> s;
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string s("");
            for (int j = 0; j < n; j++) {
                s += ".";
            }
            board.push_back(s);
        }

        solveIt(s, board, 0, n);

        return s;
    }
};

int main()
{
    Solution().solveNQueens(4);
}

