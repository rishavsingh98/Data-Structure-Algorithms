/*
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

Example 1:
Input:nums = {2, 8, 5, 4}
Output: 1
Explaination:
swap 8 with 4.

Example 2:
Input:nums = {10, 19, 6, 3, 5}
Output: 2
Explaination:
swap 10 with 3 and swap 19 with 5.
*/
class Solution 
{
    public:
  int minSwaps(vector<int>&nums)
	{
	    map<int, int> index;
	    int swaps = 0, cycles, n = nums.size();
	    for(int i = 0; i < n; i++)
	        index[nums[i]] = i;
	    
	    sort(nums.begin(), nums.end());
	    vector<bool> visited(n, false);
	    
	    for(int i = 0; i < n; i++)
	    {
	        if(visited[i] or index[nums[i]] == i)
	            continue;
	       int j = i;
	       cycles = 0;
	       while(!visited[j])
	       {
	           visited[j] = true;
	           j = index[nums[j]];
	           cycles++;
	       }
	       swaps += (cycles-1);
	    }
	    
	    return swaps;
	}
};
