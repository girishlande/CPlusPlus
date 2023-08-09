// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        bool flag = false;
        int started = 0;
        while (j < haystack.length()) {
            if (haystack[j] == needle[i]) {
                if (!flag) {
                    started = j;
                    flag = true;
                }
                i++;
            }
            else {
                if (flag) {
                    j = started;
                    i = 0;
                }
                flag = false;
            }
            j++;
            if (i == needle.length()) {
                return j - i;
            }
        }
        return -1;
    }
};


int main()
{
    string s1 = "mississippi";
    string s2 = "issipi";
    string s3 = "issip";
    int k = Solution().strStr(s1,s2);
    cout << "\nK:" << k;
}

