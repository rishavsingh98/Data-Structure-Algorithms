/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example 1:
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        int i = INT_MAX, j = INT_MAX;
        for(auto ele : nums)
        {
            if(ele <= i )
                i = ele;
            else if(ele <= j)
                j = ele;
            else
                return true;
        }
        
        return false;
    }
};
