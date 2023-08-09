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
    int lengthOfLastWord(string s) {
        bool f = false;
        bool word_started = false;
        int cnt = 0;
        for (size_t i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (word_started) {
                    return cnt;
                }
                continue;
            }
            word_started = true;
            cnt++;
            if (i == 0)
                break;
        }
        return cnt;
    }
};

int main()
{
    string s = "a";
    cout << Solution().lengthOfLastWord(s);

}

