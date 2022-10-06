/*
Given a string S, find the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. If there exists more than one such substring return any of them. Print the longest non-overlapping substring. If no such substring exists print -1.
Note: Multiple Answers are possible but you have to print the substring which occurs atleat twice first.
For Example: "ablhiabohi". Here both "ab" and "hi" are possible answers. But you will have to return "ab" as because it repeats before "hi".

Example 1:
Input:
N = 13
S = "geeksforgeeks"
Output: geeks
Explanation: The string "geeks" is the longest Substring of S which is repeating but not overlapping.

Example 2:
Input:
N = 8
S = "heyhheyi"
Output: hey
Explanation: The string "hey" is the longest Substring of S which is repeating but not overlapping.
*/
class Solution {
  public:
    string longestSubstring(string S, int n)
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int maxlen = 0, stIndex = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(S.at(i-1) == S.at(j-1) and i!=j)
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(maxlen < dp[i][j])
                    {
                        maxlen = dp[i][j];
                        stIndex = i - maxlen;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }
        return maxlen == 0 ? "-1" : S.substr(stIndex, maxlen);
    }
};
