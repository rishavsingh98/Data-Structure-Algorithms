/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 
Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

//50ms solution using bool vector
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2) return false;
        sum = sum / 2;
        vector<bool> dp(sum+1,false);
        dp[0] = true;
        
        for(int& num : nums)
        {
            for(int i=sum; i>=num; i--)
            {
                if(dp[i-num])
                {
                    dp[i] = true;
                }
            }
        }
        
        return dp[sum];
    }
};

//1800ms solution using set
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2) return false;
        int target = sum / 2;
        set<int> dp;
        dp.insert(0);
        for(auto num: nums)
        {
            set<int> nextDp = dp;
            for(auto i: dp)
            {
                int sum = num + i;
                if(sum == target)
                    return true;
                nextDp.insert(sum);
            }
            dp = nextDp;
        }
        return false;
    }
};
