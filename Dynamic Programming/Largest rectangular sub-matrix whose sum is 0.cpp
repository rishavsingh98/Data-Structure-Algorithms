/*
Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.
If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one starting from minimum row index. If you still have multiple solutions return the one having greatest row number.

Example 1:

Input: N = 3, M = 3
mat[][] =  1, 2, 3
          -3,-2,-1
           1, 7, 5

Output:  1, 2, 3
        -3,-2,-1

Explanation: This is the largest sub-matrix,
whose sum is 0.
Example 2:

Input: N = 4, M = 4
mat[][] = 9, 7, 16, 5
          1,-6,-7, 3
          1, 8, 7, 9
          7, -2, 0, 10

 Output: -6,-7
          8, 7
         -2, 0 

*/
class Solution{
  public:
    int getMaxLen(vector<int>&A, int& start, int& end, int n)
    {   
        unordered_map<int,int> storesum;
        int sum = 0, maxlen = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i] == 0 and end == -1)
            {
                start = end = i;
                maxlen = 1;
            }
            
            sum += A[i];
            if(sum == 0 and maxlen < i+1)
            {
                start = 0;
                end = i;
                maxlen = i+1;
            }
            
            if(storesum.find(sum) != storesum.end())
            {
                if(i - storesum[sum] > maxlen)
                {
                    start = storesum[sum] + 1;
                    end = i;
                    maxlen = i - storesum[sum];
                }
            }
            else
                storesum[sum] = i;
        }
        return maxlen;
    }
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
  {
          
    int r = a.size(), c = a[0].size();
    int maxArea = INT_MIN, leftBound = 0, rightBound = 0, upBound = 0, downBound = 0;
    for(int left = 0; left < c; left++)
    {
        vector<int> dp(r, 0);
        for(int right = left; right < c; right++)
        {
          for(int i = 0; i < r; i++)
            dp[i] += a[i][right];
          
          int start = 0, end = -1, maxlen, area;
          maxlen = getMaxLen(dp, start, end, r);
          area = (right - left + 1) * maxlen;
          if(maxArea < area)
          {
              maxArea = area;
              leftBound = left;
              rightBound = right;
              upBound = start;
              downBound = end;
          }
          
        }
    }
    
    if(maxArea == INT_MIN)
        return vector<vector<int>> (1,vector<int>(1,-1));
    
    vector<vector<int>> ans(downBound - upBound + 1, vector<int>(rightBound - leftBound + 1, 0));
    for(int i = 0; i <= downBound - upBound; i++)
        for(int j = 0; j <= rightBound - leftBound; j++)
            ans[i][j] = a[i + upBound][j + leftBound];
    return ans;
  }
};
