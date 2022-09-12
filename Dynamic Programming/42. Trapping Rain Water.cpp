/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 
Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/
//O(n) time and O(n) space (DP Soln)
class Solution{
    public:
    long long trappingWater(int arr[], int n)
    {
        long long maxLeft[n], maxRight[n], maxVal = 0, water = 0;
        for(int i = 0; i < n; i++)
        {
            maxLeft[i] = maxVal;
            if(maxVal <= arr[i])
                maxVal = arr[i];
        }
        maxVal = 0;
        for(int i = n-1; i >= 0; i--)
        {
            maxRight[i] = maxVal;
            if(maxVal <= arr[i])
                maxVal = arr[i];
        }
        
        for(int i = 0; i<n; i++)
        {
            long long level = min(maxLeft[i], maxRight[i]);
            if(level - arr[i] > 0)
                water += level - arr[i];
        }
        return water;
    }
};
//O(n) time and O(1) space (Two Pointer Soln)
class Solution {
public:
    int trap(vector<int>& arr)
    {
        int n = arr.size();
        long long maxLeft = 0, maxRight = 0, left = 0, right = n-1, water = 0;
        
        while(left < right)// 
        {
            if(arr[left] < arr[right])
            {
                arr[left] >= maxLeft ? (maxLeft = arr[left]) : (water += (maxLeft - arr[left])) ;
                left++;
            }
            else
            {
                arr[right] >= maxRight ? (maxRight = arr[right]) : (water += (maxRight - arr[right]));
                right--;
            }
        }
        return water;
    }
};
