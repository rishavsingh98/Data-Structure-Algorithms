/*
You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
*/
class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        //sorting words
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int> dict = {};
        for(string i : words)
        {
            dict[i] = 1;
            int maxchain = 1;
            int l = i.length();
            for(int it=0;it<l;it++)
            {
                int currchain = 0;
                string x = i;
                x.erase(it,1);
                if(dict.find(x)!=dict.end())
                {
                    currchain = 1 + dict[x];  
                }
                if(currchain>maxchain)
                    maxchain = currchain;
            }
            dict[i] = maxchain;
        }
        int max = 0;
        for(string i : words)
            if(dict[i]>max)
                max = dict[i];
        return max;
    }
    
    static bool compare(string s1, string s2)
    {
        if(s1.size() == s2.size())
            return s1 < s2;
        else
            return s1.size() < s2.size();
    }
};
