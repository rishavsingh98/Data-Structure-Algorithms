/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M)
    {      
        int maxArea = INT_MIN, leftBound = 0, rightBound = 0, upBound = 0, downBound = 0, R = M.size(), C = M[0].size();
        int flag = 0;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
            {
                if(M[i][j] == '1')
                {
                    flag = 1;
                    break;
                }
            }
        if(flag == 0)
            return 0;
        
        for(int left = 0; left < C; left++)
        {
            vector<int> dp(R,0);
            for(int right = left; right < C; right++)
            {
                int currsum = 0, start = -1, finish= -1, currMax = INT_MIN, locStart = 0;
                for(int r = 0; r < R; r++)
                    if(M[r][right] == '1')
                        dp[r] += 1;
                    else
                        dp[r] = dp[r] - 100;
                
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
                
                if(currMax > maxArea)
                {
                    maxArea = currMax;
                    leftBound = left;
                    rightBound = right;
                    upBound = start;
                    downBound = finish;
                }
            }
        }
        return maxArea;
  }
};
