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

using namespace std;

class Solution {
public:

    string addBinary(string a, string b) {
        size_t c = 0;
        string r = "";
        stringstream ss;
        int carry = 0;
        while (c < a.length() && c < b.length()) {
            c++;
            char ac = a[a.length() - c];
            char bc = b[b.length() - c];
            if ((ac == '1' && bc == '0') || (ac == '0' && bc == '1')) {
                if (carry) {
                    ss << '0';
                }
                else {
                    ss << '1';
                }
            }
            else if (ac == '0' && bc == '0') {
                if (carry == 0) {
                    ss << '0';
                }
                else {
                    ss << '1';
                    carry = 0;
                }
            }
            else if (ac == '1' && bc == '1') {
                if (carry == 1) {
                    ss << '1';
                }
                else {
                    ss << '0';
                }
                carry = 1;
            }
        }
        
        while (c < a.length()) {
            c++;
            char ac = a[a.length() - c];
            if (ac == '0') {
                if (carry) {
                    ss << '1';
                    carry = 0;
                }
                else {
                    ss << '0';
                }
            }
            else if (ac=='1') {
                if (carry) {
                    ss << '0';
                }
                else {
                    ss << '1';
                }
            }
        }
        while (c < b.length()) {
            c++;
            char bc = b[b.length() - c];
            if (bc == '0') {
                if (carry) {
                    ss << '1';
                    carry = 0;
                }
                else {
                    ss << '0';
                }
            }
            else if (bc == '1') {
                if (carry) {
                    ss << '0';
                }
                else {
                    ss << '1';
                }
            }
        }
        if (carry) {
            ss << '1';
        }
        string res = ss.str();
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    string a = "11", b = "01";
    cout << Solution().addBinary(a, b);

}

