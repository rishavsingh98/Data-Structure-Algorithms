/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28
*/
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(m, 1);
        for(int i = 0; i < n-1; i++)
        {
            vector<int> temp(m, 1);
            for(int j = m-2; j >= 0; j--)
                temp[j] = dp[j] + temp[j+1];
        
            for(int j = m-1; j >= 0; j--)
                dp[j] = temp[j];
        }
        return dp[0];
    }
};
