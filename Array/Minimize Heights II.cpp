/* 
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K.
Decrease the height of the tower by K ( you can do this operation only if the height of the tower is greater than or equal to K)
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

Example 1:
Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.

Example 2:
Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as
{6, 12, 9, 13, 17}. The difference between 
the largest and the smallest is 17-6 = 11.

Constraints
1 ≤ K ≤ 10^4
1 ≤ N ≤ 10^5
1 ≤ Arr[i] ≤ 10^5

*/

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int minDiff = arr[n-1] - arr[0],cmin,cmax;
        for(int i = 0;i<n-1;i++)
        {
            cmin = min(arr[0]+k,arr[i+1]-k);
            cmax = max(arr[n-1]-k,arr[i]+k);
            if(cmin<0)
                continue;
            minDiff = min(minDiff,cmax-cmin);
        }
        return minDiff;
    }
};
