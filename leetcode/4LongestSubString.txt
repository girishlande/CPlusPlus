Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> chars;
        int count=0;
        int maxLen = 0;
        for(size_t i = 0;i<s.length();i++) {
            char ch = s[i];
            if (chars.find(ch)==chars.end()) {
                chars.insert(ch);
                count++;
            } else {
                if (count>maxLen)
                    maxLen = count;
                chars.clear();
                chars.insert(ch);
                size_t j = i-1;
                while(s[j]!=ch) {
                  chars.insert(s[j]);    
                  j--;
                }
                count = chars.size();                                
            }
        }
        
       if (count>maxLen) 
           maxLen = count;
        return maxLen;
    }
};