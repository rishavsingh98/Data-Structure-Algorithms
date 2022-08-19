/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:
Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.

Example 2:
Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2
*/
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, INT_MIN);
        dp[0] = 0;
        for(int i = 1; i<=n; i++)
        {
            if(i-x >= 0 and dp[i] < 1 + dp[i-x])
                dp[i] = 1 + dp[i-x];
            if(i-y >= 0 and dp[i] < 1 + dp[i-y])
                dp[i] = 1 + dp[i-y];
            if(i-z >= 0 and dp[i] < 1 + dp[i-z])
                dp[i] = 1 + dp[i-z];
        }
        if(dp[n] < 0)
            return 0;
        return dp[n];
    }
};
