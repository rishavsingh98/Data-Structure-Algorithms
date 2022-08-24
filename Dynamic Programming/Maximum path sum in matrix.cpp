/*
Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].
Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

Example 1:
Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

Example 2:
Input: N = 2
Matrix = {{2, 2},
          {2, 2}}
Output: 4
Explaination: No matter which path is 
chosen, the output is 4.
*/
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<int> dp(N, INT_MIN);
        for(int i = 0; i < N; i++)
            dp[i] = Matrix[N-1][i];
        for(int i = N-2; i >= 0 ; i--)
        {
            vector<int> temp(N, INT_MIN);
            for(int j = 0; j < N; j++)
            {
                if(j == 0 and j == N-1)
                    temp[j] = Matrix[i][j] + dp[j];
                else if(j == 0)
                    temp[j] = Matrix[i][j] + max(dp[j], dp[j+1]);
                else if(j == N-1)
                    temp[j] = Matrix[i][j] + max(dp[j], dp[j-1]);
                else
                    temp[j] = Matrix[i][j] + max(dp[j],max(dp[j-1], dp[j+1]));
                    
            }
            dp = temp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
