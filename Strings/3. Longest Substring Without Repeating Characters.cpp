/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0, l = 0, r = 0, n = s.length();
        unordered_set<char> charmap;
        for(int i = 0 ; i  < n ; i++)
        {
            while(charmap.find(s[r]) != charmap.end())
            {
                charmap.erase(s[l]);
                l++;
            }
            charmap.insert(s[r]);
            maxLength = max(maxLength, (r - l + 1));
            r++;
        }
        return maxLength;
    }
};
