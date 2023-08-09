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
    string countAndSay(int n) {
        if (n == 1)
            return string("1");
        else if (n == 2)
            return string("11");
        else {
            string s = countAndSay(n - 1);
            char ch = s[0];
            int i = 1;
            std::vector<char> v;
            int count = 1;
            //std::string str(v.begin(), v.end());
            while (i < s.length()) {
                if (s[i] != ch) {
                    // push count
                    std::string s1 = std::to_string(count);
                    for(auto a:s1)
                        v.push_back(a);
                    // push character
                    v.push_back(ch);
                    count = 1;
                    ch = s[i];
                }
                else {
                    count++;
                }
                i++;
            }
            std::string s1 = std::to_string(count);
            for (auto a : s1)
                v.push_back(a);
            v.push_back(ch);
            return string(v.begin(), v.end());
        }
    }
};


int main()
{
    for (int i = 1; i < 10; i++) {
        cout << Solution().countAndSay(i);
        cout << "\n";
    }
}

