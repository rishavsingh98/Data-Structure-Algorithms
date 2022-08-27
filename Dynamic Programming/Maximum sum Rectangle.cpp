/*
Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.
Example 1:

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29
Explanation:
The matrix is as follows and the
blue rectangle denotes the maximum sum
rectangle.
Thumbnail
Example 2:

Input:
R=2
C=2
M=[[-1,-2],[-3,-4]]
Output:
-1
*/
class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int mini = INT_MIN, flag = 0;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
            {
                if(M[i][j] > 0)
                    flag = 1;
                mini = max(mini, M[i][j]);
            }
        if(flag == 0)
            return mini;
        
        int maxSum = INT_MIN, leftBound = 0, rightBound = 0, upBound = 0, downBound = 0;
        for(int left = 0; left < C; left++)
        {
            vector<int> dp(R,0);
            for(int right = left; right < C; right++)
            {
                int currsum = 0, start = -1, finish= -1, currMax = INT_MIN, locStart = 0;
                for(int r = 0; r < R; r++)
                    dp[r] += M[r][right];
                
                for(int r = 0; r < R; r++)
                {
                    currsum += dp[r];
                    if(currsum < 0)
                    {
                        currsum = 0;
                        locStart = r + 1;
                    }
                    else
                    {
                        if(currsum > currMax )
                        {
                            currMax = currsum;
                            start = locStart;
                            finish = r;
                        }
                        
                    }
                }
                if(finish == -1)
                {    
                    currMax = *max_element(dp.begin(),dp.end());
                    start = finish = distance(dp.begin(), max_element(dp.begin(),dp.end()));
                }
                
                if(currMax > maxSum)
                {
                    maxSum = currMax;
                    leftBound = left;
                    rightBound = right;
                    upBound = start;
                    downBound = finish;
                }
            }
        }
        return maxSum;
    }
};
