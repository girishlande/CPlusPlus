// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool validFlag = true;
        for (char ch : s) {
            if (ch == '{' || ch == '[' || ch == '(') {
                st.push(ch);
            }
            else if (ch == '}') {
                if (st.empty()) return false;
                char top = st.top();
                if (top != '{') {
                    validFlag = false;
                    break;
                }
                st.pop();
            }
            else if (ch == ']') {
                if (st.empty()) return false;
                char top = st.top();
                if (top != '[') {
                    validFlag = false;
                    break;
                }
                st.pop();
            }
            else if (ch == ')') {
                if (st.empty()) return false;
                char top = st.top();
                if (top != '(') {
                    validFlag = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty())
            return false;
        return validFlag;
    }
};

int main()
{
    string s = "]";
    cout << Solution().isValid(s);
    
}

