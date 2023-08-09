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

    string addString(vector<string>& cache,int maxWidth, bool last) {
        size_t len = 0;
        for (string s : cache) {
            len += s.length();
        }
        size_t count = cache.size() - 1;
        if (last)
            count = 0;
        vector<string> spaceWords(count,"");
        if (count) {
            int aspace = maxWidth - len;
            int i = 0;
            while (aspace > 0) {
                spaceWords[i] = spaceWords[i] + " ";
                i = (i + 1) % count;
                aspace--;
            }
        }
        string res = "";
        for (size_t j = 0; j < cache.size(); j++) {
            res = res + cache[j];
            if (j < spaceWords.size()) {
                res = res + spaceWords[j];
            }
            else {
                if (last && res.length()<maxWidth) {
                    res = res + " ";
                }
            }
        }

        int s = maxWidth - res.length();
        for (int i = 0; i < s; i++) {
            res = res + " ";
        }
        
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> cache;
        int sum = 0;
        int awidth = maxWidth;

        for (string w : words) {
            int l = w.length();
            if (l > awidth) {
                // Combine strings from cache and add in result
                res.push_back(addString(cache, maxWidth,false));

                // clear cache and reset available width 
                cache.clear();
                awidth = maxWidth;
            }
            cache.push_back(w);
            awidth = awidth - l - 1;
        }
        // Combine strings from cache and add in result
        res.push_back(addString(cache, maxWidth,true));

        return res;
    }
};

int main()
{
    //vector<string> words{ "This", "is", "an", "example", "of", "text", "justification." };
    //vector<string> words{ "What","must","be","acknowledgment","shall","be" };
    // vector<string> words{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    vector<string> words{ "ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country" };
    int maxWidth = 16;
    //int maxWidth = 20;
    vector<string> res = Solution().fullJustify(words, maxWidth);
    for (auto a : res) {
        cout << "\"" << a << "\"\n";
    }

}

