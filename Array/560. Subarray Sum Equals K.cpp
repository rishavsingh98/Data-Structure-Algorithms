/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ispresent = {};
        int currsum = 0, count = 0, reqd;
        for(auto it : nums)
        {
            currsum += it;
            reqd = currsum - k;
            if(reqd == 0)
                count++;
            if(ispresent.find(reqd) != ispresent.end())
                count += ispresent[reqd];
            ispresent[currsum]++;
        }
        return count;
    }
};
