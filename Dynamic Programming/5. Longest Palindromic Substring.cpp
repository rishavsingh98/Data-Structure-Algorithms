/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.length()][s.length()];
        int currlen=1,maxlen=1,start=0,end=0;
        for(int i=0;i<s.length();i++)
            dp[i][i] = 1;
        for(int it = 1;it<s.length();it++)
            for(int i=0;i<s.length();i++)
            {
                int j = i+it;
                if(j>=s.length())
                    continue;
                if(it==1)
                {
                    if(s.at(i)==s.at(j))
                    {
                        dp[i][j] = 1;
                        currlen = j - i + 1;
                        if(currlen>maxlen)
                        {
                            maxlen=currlen;
                            start=i;
                            end=j;
                        }
                    }
                    else
                        dp[i][j] = 0;
                    continue;

                }
                if(s.at(i)==s.at(j) && dp[i+1][j-1]==1)
                {
                    dp[i][j] = 1;
                    currlen = j - i + 1;
                    if(currlen>maxlen)
                    {
                        maxlen=currlen;
                        start=i;
                        end=j;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        return s.substr(start,maxlen);
    }
};
