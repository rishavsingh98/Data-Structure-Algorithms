/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 
Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/
class Solution {
public:
    string minWindow(string s, string p)
    {
        unordered_map<char, int> smap , pmap;
        int n1 = s.length(), n2 = p.length();
        
        for(int i = 0; i < n2; i++)
        {
            if(pmap.find(p.at(i)) == pmap.end())
            {
                pmap[p.at(i)] = 1;
                smap[p.at(i)] = 0;
            }
            else
                pmap[p.at(i)]++;
        }
        
        int start = 0, end = 0, count = 0, min_str = INT_MAX, min_start = 0, min_end = n1;
        
        while(end < n1)
        {
            if(smap.find(s.at(end)) != smap.end())
            {   
                if(smap[s.at(end)] < pmap[s.at(end)])
                    count++;
                smap[s.at(end)]++;
            }
            
            while(count == n2)
            {
                if(min_str > end - start + 1)
                {
                    min_str = end - start + 1;
                    min_start = start;
                    min_end = end;
                }
                
                if(smap.find(s.at(start)) != smap.end())
                {
                    if(smap[s.at(start)] <= pmap[s.at(start)])
                        count--;
                    smap[s.at(start)]--;
                }    
                start++;
            }
            
            end++;
        }
        
        
        if(min_str == INT_MAX)
            return "";
        else
            return s.substr(min_start, min_end - min_start + 1);    
    }
};
