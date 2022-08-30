/*
Given a binary matrix. The problem is to find the largest area rectangular sub-matrix with equal number of 1’s and 0’s. Examples:

Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 0},
                    {1, 1, 1, 0},
                    {1, 0, 0, 1} }
Output : 8 sq. units
(Top, left): (0, 0)
(Bottom, right): (3, 1)

Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 1} }            
Output : 6 sq. units
*/
#include<bits/stdc++.h>
using namespace std;

#define MAX_ROW 10
#define MAX_COL 10

int getMaxLen(vector<int>&A, int& start, int& end, int n)
    {   
        int sum = 0, maxlen = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i])
                sum += 1;
            else
                sum -= 1;
            if(sum == 0 and maxlen < i+1)
            {
                start = 0;
                end = i;
                maxlen = i+1;
            }
        }
        return maxlen;
    }
  void maxAreaRectWithSumZero(int a[MAX_ROW][MAX_COL], int r, int c)
  {
          
    int maxArea = INT_MIN, leftBound = 0, rightBound = 0, upBound = 0, downBound = 0;
    for(int left = 0; left < c; left++)
    {
        vector<int> dp(r, 0);
        for(int right = left; right < c; right++)
        {
          for(int i = 0; i < r; i++)
            if(a[i][right])
                dp[i] += 1;
            else
                dp[i] -= 1;
          
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
        cout<<"-1"<<endl;
    vector<vector<int>> ans(downBound - upBound + 1, vector<int>(rightBound - leftBound + 1, 0));
    for(int i = 0; i <= downBound - upBound; i++)
    {
        for(int j = 0; j <= rightBound - leftBound; j++)
            cout<<a[i + upBound][j + leftBound]<<" ";
        cout<<endl;
    }
  }



int main()
{
    
        int mat[MAX_ROW][MAX_COL] = { {0, 0, 1, 1},
                                      {0, 0, 1, 0},
                                      {1, 1, 1, 0},
                                      {1, 0, 0, 1} };
    int row = 4, col = 4;
    maxAreaRectWithSumZero(mat, row, col);
    
    return 0;
}
