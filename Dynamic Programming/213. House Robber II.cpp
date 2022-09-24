/*
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/
class Solution {
public:
    int rob(vector<int>& arr)
    {
        int prevProfit = 0, neighProfit = arr[0], currProfit = arr[0],n = arr.size();
        if(n == 1)
            return currProfit;
        if(n == 2)
            return max(arr[0], arr[1]);
        for(int i = 1; i<n-1; i++)
        {
            currProfit = max(neighProfit, prevProfit + arr[i]);
            prevProfit = neighProfit;
            neighProfit = currProfit;
        }
        
        int p1 = currProfit;
        prevProfit = 0, neighProfit = arr[1], currProfit = arr[1];
        for(int i = 2; i<n; i++)
        {
            currProfit = max(neighProfit, prevProfit + arr[i]);
            prevProfit = neighProfit;
            neighProfit = currProfit;
        }
        int p2 = currProfit;
        return max(p1, p2);
    }
};
