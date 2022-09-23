/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ans;
        deque<int> Q;
        Q.push_back(0);
            
        for(int i = 1; i < k; i++)   
        {
            while(!Q.empty() and nums[i] > nums[Q.back()])
                Q.pop_back();  
            Q.push_back(i);
        }
        ans.push_back(nums[Q.front()]);
        
        for(int i = k; i < nums.size(); i++)
        {
            while(!Q.empty() and Q.front() < i-k+1)
                Q.pop_front();
            
            while(!Q.empty() and nums[i] > nums[Q.back()])
                Q.pop_back();
            
            Q.push_back(i);
            ans.push_back(nums[Q.front()]);
        }
        return ans;
    }
};
