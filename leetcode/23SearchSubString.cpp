// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void permute(string a, int l, int r)
    {
        // Base case 
        if (l == r)
            cout << a << endl;
        else
        {
            // Permutations made 
            for (int i = l; i <= r; i++)
            {

                // Swapping done 
                swap(a[l], a[i]);

                // Recursion called 
                permute(a, l + 1, r);

                //backtrack 
                swap(a[l], a[i]);
            }
        }
    }

    void permuteVec(vector<string>& a, int l, int r, vector<string>& outputv)
    {
        // Base case 
        if (l == r) {
            string cstr("");
            for (auto a1 : a) {
                cstr += a1;
            }
            outputv.push_back(cstr);
        } 
        else
        {
            // Permutations made 
            for (int i = l; i <= r; i++)
            {

                // Swapping done 
                swap(a[l], a[i]);

                // Recursion called 
                permuteVec(a, l + 1, r, outputv);

                //backtrack 
                swap(a[l], a[i]);
            }
        }
    }

    int strStr(string haystack, string needle,int& nextstartIndex) {
        int i = 0;
        int j = 0;
        if (nextstartIndex != -1)
            j = nextstartIndex;
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
                nextstartIndex = j;
                return j - i;
            }
        }
        nextstartIndex = -1;
        return -1;
    }
    vector<string> getAllPermutations(vector<string>& words) {
        vector<string> v;
        permuteVec(words, 0, words.size() - 1, v);
        return v;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> sub;
        set<int> sub1;
        vector<string> p = Solution().getAllPermutations(words);
        for (auto a : p) {
            int nextstartIndex = -1;
            while (1) {
                int index = strStr(s, a, nextstartIndex);
                if (index != -1 && sub1.find(index) == sub1.end()) {
                    sub.push_back(index);
                    sub1.insert(index);
                }
                if (nextstartIndex == -1)
                    break;
                else
                    nextstartIndex = index + 1;
            }
        }
        return sub;
    }
};


int main()
{
    string s = "a";
    vector<string> words = { "a" };
    vector<int> output = Solution().findSubstring(s, words);

    for (auto i : output) {
        cout << i << "   ";
    }
    /*vector<string> v = { "A","B","C" };
    vector<string> p = Solution().getAllPermutations(v);
    for (auto a : p) {
        cout << a << "\n";
    }*/

}

