// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class Solution {
public:
	int valueOfChar(char ch) {
		switch (ch) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		}
		return 0;
	}

	char valueOfNum(int n) {
		switch (n) {
		case 1: return 'I';
		case 5: return 'V';
		case 10: return 'X';
		case 50: return 'L';
        case 100: return 'C';
        case 500: return 'D';
        case 1000: return 'M';
		}
		return 0;
	}

    void updateString(string& output, int n,int count) {
        char ch = valueOfNum(n);
        for (int i = 0; i < count; i++) {
            output += ch;
        }
    }
	string intToRoman(int num) {
        // Divide the number by 1000 , 500, 100 and so on
        string output = "";
        int r = num / 1000;
        if (r >= 1) {
            int sol = r * 1000;
            num = num - sol; // new number
            updateString(output, 1000, r);
        }
        if (num / 900 == 1) {
            output += "CM";
            num = num - 900;
        }
        if (num / 500 == 1) {
            output += 'D';
            num = num - 500;
        }
        if (num / 400 == 1) {
            output += "CD";
            num = num - 400;
        }
        r = num / 100;
        if (r >= 1) {
            int sol = r * 100;
            num = num - sol;
            updateString(output, 100, r);
        }
        if (num / 90 == 1) {
            output += "XC";
            num = num - 90;
        }
        if (num / 50 == 1) {
            output += 'L';
            num = num - 50;
        }
        if (num / 40 == 1) {
            output += "XL";
            num = num - 40;
        }
        r = num / 10;
        if (r >= 1) {
            int sol = r * 10;
            num = num - sol;
            updateString(output, 10, r);
        }
        if (num == 9) {
            output += "IX";
            num = num - 9;
        }
        if (num/5 == 1) {
            output += 'V';
            num = num - 5;
        }
        if (num == 4) {
            output += "IV";
            num = num - 4;
        }
        r = num;
        if (r >= 1) {
            int sol = r * 1;
            num = num - sol;
            updateString(output, 1, r);
        }
        return output;
	}
};

int main()
{
	Solution s1;
	
    //Input: num = 1994
    //Output : "MCMXCIV"
    for (int i = 1; i < 1000; i++) {
        int n = i;
        string output = s1.intToRoman(n);
        cout << "\nInt:" << n << " Roman:" << output.c_str();
    }
    return 0;
}

