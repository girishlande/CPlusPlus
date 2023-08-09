// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <assert.h>

using namespace std;

class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            set<char> s;
            set<char> s1;
            vector<char>& jvec = board[i];
            for (int j = 0; j < 9; j++) {
                if (jvec[j] != '.') {
                    if (s.find(jvec[j]) == s.end()) {
                        s.insert(jvec[j]);
                    }
                    else {
                        return false;
                    }

                }
                if (board[j][i]!='.') {
                    if (s1.find(board[j][i]) == s1.end()) {
                        s1.insert(board[j][i]);
                    }
                    else {
                        //cout << "\n failed:" << j << "," << i;
                        return false;
                    }
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int ioffset = i * 3;
                int joffset = j * 3;

                set<char> s;
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        char ch = board[r + ioffset][c + joffset];
                        if (ch != '.') {
                            if (s.find(ch) == s.end()) {
                                s.insert(ch);
                            }
                            else {
                                //cout << "\nfailed:" << (r + ioffset) << "," << (c + joffset);
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};


int main()
{
    vector<vector<char>> board{ {'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}
    };


    vector<vector<char>> board2{ {'8', '3', '.', '.', '7', '.', '.', '.', '.'}
        , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
        , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
        , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
        , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
        , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
        , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
        , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
        , {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

    for (auto a : board) {
        for (auto b : a) {
            cout << b << ' ';
        }
        cout << "\n";
    }
    cout << "\n is valid: " << Solution().isValidSudoku(board);

}

