// ConsoleApplication16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:

    void reverseStr(string& str)
    {
        int n = str.length();

        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }

    string multiply(string num1, string num2) {

        bool all_zero = true;
        for (int i = 0; i < num1.length(); i++) {
            if (num1[i] != '0')
                all_zero = false;
        }
        if (all_zero) {
            return string("0");
        }
        all_zero = true;
        for (int i = 0; i < num2.length(); i++) {
            if (num2[i] != '0')
                all_zero = false;
        }
        if (all_zero) {
            return string("0");
        }


        vector<string> res;
        size_t maxlength = 0;
        for (int i = num1.length() - 1; i >= 0; i--) {
            char ichar = num1[i];
            int v1 = ichar - 48;
            string temp = "";
            
            for (int k = num1.length() - 1; k > i; k--) {
                temp += '+';
            }
            int carry = 0;
            for (int j = num2.length() - 1; j >= 0; j--) {
                char jchar = num2[j];
                int v2 = jchar - 48;

                int a = v1 * v2;
                a = a + carry;
                int rem = a % 10;
                carry = a / 10;

                temp += to_string(rem);
            }
            if (carry) {
                temp += to_string(carry);
            }
            if (temp.length() > maxlength)
                maxlength = temp.length();

            res.push_back(temp);
        }

        for (auto a : res) {
            cout << a << "\n";
        }

        string result = "";
        int carry = 0;
        for (size_t i = 0; i < maxlength; i++) {
            int sum = 0;

            for (size_t j = 0; j < res.size(); j++) {
                string s = res[j];
                if (i < s.length()) {
                    char ch = s[i];
                    if (ch != '+') {
                        sum = sum + ch - 48;
                    }
                }
            }

            sum = sum + carry;
            int rem = sum % 10;
            carry = sum / 10;

            result = result +  to_string(rem);
        }

        if (carry) {
            result = result + to_string(carry);
        }
        reverseStr(result);

        return result;
    }

};

int main()
{
    string s1 = "123";
    string s2 = "456";
    string ans = Solution().multiply(s1, s2);
    cout << "Ans:" << ans;

}

