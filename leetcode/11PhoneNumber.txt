// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getLetters(char num) {
        switch (num) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        }
        return "";
    }

    void getCombinations(string digits, vector<string>& output, string prefix) {
        string newDigits = digits.substr(1, digits.length());
        char digit = digits[0];
        string letters = getLetters(digit);
        for (auto ch : letters) {
            if (digits.length() == 1) {
                output.push_back(prefix + ch);
            }
            else {
                getCombinations(newDigits, output, prefix + ch);
            }
        }
    }

    vector<string> letterCombinations(string s) {
        s.erase(std::remove(s.begin(), s.end(), '1'), s.end());
        vector<string> output;
        string prefix = "";
        if (s.empty()) return output;
        getCombinations(s,output,prefix);
        return output;
    }
};

int main()
{
	Solution s1;
	
    vector<string> output = s1.letterCombinations("");
    for (auto x : output) {
        cout << x << "\n";
    }

    return 0;
}

