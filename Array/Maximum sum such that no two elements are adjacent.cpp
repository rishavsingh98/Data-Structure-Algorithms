/*
Given an array arr[] of positive numbers, the task is to find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array.

Examples: 
Input: arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: Pick the subsequence {5, 100, 5}.
The sum is 110 and no two elements are adjacent. This is the highest possible sum.

Input: arr[] = {3, 2, 7, 10}
Output: 13
Explanation: The subsequence is {3, 10}. This gives sum = 13.
This is the highest possible sum of a subsequence following the given criteria
*/
//DP Soln time: O(n); space: O(n)
class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = arr[0];
        for(int i = 2; i <= n ; i++)
            dp[i] = max(dp[i-1], dp[i-2] + arr[i-1]);
        return dp[n];
    }
};

//Space Opt Soln time: O(n); space: O(1)
class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        int prevProfit = 0, neighProfit = arr[0], currProfit = arr[0];
        for(int i = 1; i<n; i++)
        {
            currProfit = max(neighProfit, prevProfit + arr[i]);
            prevProfit = neighProfit;
            neighProfit = currProfit;
        }
        return currProfit;
    }
};
