/*
Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) present in the string str.
Note: You have to return the answer module 109+7;
 

Example 1:
Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"
 
Example 2:
Input: 
Str = "aab"
Output: 
4
Explanation:
palindromic subsequence are :"a", "a", "b", "aa"
*/
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        long long int n = str.length(), mod = 1e9+7;
        vector<vector<long long int>> palinDp(n, vector<long long int>(n, 0));
        
        
        for(int i = 0; i < n; i++)
            palinDp[i][i] = 1;
        
        for(int it = 2; it <= n; it++)
        {
            for(int i = n - it ; i >= 0; i--)
            {
                int j = i + it - 1;
                if(str.at(i) == str.at(j))
                    palinDp[i][j] = ((1 + palinDp[i+1][j] % mod) % mod + palinDp[i][j-1] % mod) % mod;
                else
                    palinDp[i][j] = ((palinDp[i+1][j] % mod + palinDp[i][j-1] % mod) % mod - palinDp[i+1][j-1] % mod ) % mod ;
            }
        }
        
        return palinDp[0][n-1] % mod;
    }
     
};
