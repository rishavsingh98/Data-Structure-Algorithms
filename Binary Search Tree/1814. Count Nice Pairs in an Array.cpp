/*
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:
0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.
 
Example 1:
Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
*/
class Solution {
public:
    int countNicePairs(vector<int>& nums)
    {
        unordered_map<int, long long> freq;
        long long count = 0, mod = 1e9+7;
        for(auto x : nums)
        {
            int rev  = 0, org = x, rem, nmr;
            while(org)
            {
                rem = org%10;
                rev = rev*10 + rem;
                org /= 10;
            }
            nmr = x - rev;
            if(freq.find(nmr) != freq.end())
                count = (count + freq[nmr]%mod)%mod;
            freq[nmr] = (freq[nmr] + 1)%mod;
        }
        
        return count;        
    }
};
