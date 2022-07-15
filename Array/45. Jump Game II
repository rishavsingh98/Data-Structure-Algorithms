/* 
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 1000

*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = nums[0], n = nums.size(), i = 1, jump = 1,maxjump = 0,currjump;
        if(n <= 1)
            return 0;
        while(i < n)
        {
            maxjump = 0;
            while(curr--)
            {
                if(i >= n)
                    return jump;
                currjump = nums[i] - curr;
                if(currjump > maxjump)
                    maxjump = currjump;
                i++;
            }
            if(i >= n)
                return jump;
            curr = maxjump;
            if(curr<=0)
                return -1;
            jump += 1;
        }
    return jump;
    }
};
