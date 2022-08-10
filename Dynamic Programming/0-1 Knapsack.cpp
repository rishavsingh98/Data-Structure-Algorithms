/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:
Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

Example 2:
Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
*/
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][W+1];
       memset(dp, 0, sizeof(dp));
       for(int row = 1; row <= n; row++)
       {
           for(int col = 1; col <= W; col++)
           {
                int prof = 0;
                if(col - wt[row-1] >= 0)
                    prof = val[row-1] + dp[row-1][col - wt[row-1]];
                dp[row][col] = max(prof, dp[row-1][col]);
           }
       }
       return dp[n][W];
    }
};
