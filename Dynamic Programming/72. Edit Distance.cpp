
/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.length(), s2 = word2.length();
        int dp[s1+1][s2+1], counter1 = s2, counter2 = s1;
        
        for(int i = 0; i <= s2; i++)
            dp[s1][i] = counter1--;
        for(int i = 0; i<= s1; i++)
            dp[i][s2] = counter2--;
        
        for(int i = s1-1; i >= 0 ; i--)
        {
            for(int j = s2-1; j >= 0 ;j--)
            {
                if(word1.at(i) == word2.at(j))
                    dp[i][j] = dp[i+1][j+1];
                else
                    dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
            }
        }
        return dp[0][0];
    }
};
