/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.
Example 1:
Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".

Example 2:
Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".
*/
class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        
        vector<vector<int>> palinDp(n, vector<int>(n, 1));
        for(int i = 0; i < n-1; i++)
            if(str.at(i) != str.at(i+1))
                palinDp[i][i+1] = 0;
        
        for(int it = 3; it <= n; it++)
        {
            for(int i = 0; i < n - it + 1; i++)
            {
                int j = i + it -1;
                if(palinDp[i+1][j-1] != 1 or str.at(i) != str.at(j))
                    palinDp[i][j] = 0;
            }
        }
        
        vector<int> cuts(n, INT_MAX);
        for(int i = 0; i < n; i++)
        {
            int minCut = INT_MAX;
            if(palinDp[0][i] == 1)
                cuts[i] = 0;
            else
            {
                for(int j = 0; j < i; j++)
                {
                    if(palinDp[j+1][i] and minCut > cuts[j] + 1)
                        minCut = cuts[j] + 1;
                }
                cuts[i] = minCut;
            }
        }
        return cuts[n-1];
    }
};
