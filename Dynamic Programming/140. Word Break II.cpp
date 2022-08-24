/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Example 2:
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []

Constraints:
1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/
class Solution {
public:
    unordered_map<string, vector<string>> dp;
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        vector<string> dict;
        int n = s.length();
        if(dp.find(s) != dp.end())
            return dp[s];
        else if(n == 0)
        {
            dict.push_back("");
            return dict;
        }
        for(auto word: wordDict)
        {
            string sentence = "";
            int wsize = word.length();
            if(s.substr(0,wsize) == word)
            {
                vector<string> retDict = wordBreak(s.substr(wsize), wordDict);
                for(auto sen: retDict)
                {
                    if(sen == "")
                        dict.push_back(word);
                    else
                        dict.push_back(word + " " + sen);
                }
            }
        }
        dp[s] = dict;
        return dict;
    }
};
