/*
You are given n identical eggs and you have access to a building with k floors labeled from 1 to k.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= k). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:
Input: n = 1, k = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

Example 2:
Input: n = 2, k = 6
Output: 3

Example 3:
Input: n = 3, k = 14
Output: 4

Constraints:
1 <= n <= 100
1 <= k <= 10^4
*/

//O(nk^2) complexity; TLE in Leetcode Super Egg drop, working in GFG Egg drop puzzle
class Solution {
public:
    int superEggDrop(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1,0));
        int res;
        for(int f = 1; f <= k; f++)
            dp[1][f] = f;
        for (int e = 1; e <= n; e++)
            dp[e][1] = 1;
        for(int egg = 2; egg <= n; egg++)
        {
            for(int floor = 2; floor <= k; floor++)
            {
                dp[egg][floor] = INT_MAX;
                for(int x = 1; x <= floor; x++)
                {
                    res = 1 + max(dp[egg][floor - x], dp[egg-1][x - 1]);
                    if(res < dp[egg][floor])
                        dp[egg][floor] = res;
                }
            }
        }
        return dp[n][k];
    }
};

//Optimized O(nklogk) complexity; Accepted in leetcode and GFG
class Solution {
public:
    int superEggDrop(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1,0));
        int res;
        for(int f = 1; f <= k; f++)
            dp[1][f] = f;
        for (int e = 1; e <= n; e++)
            dp[e][1] = 1;
        for(int egg = 2; egg <= n; egg++)
        {
            for(int floor = 2; floor <= k; floor++)
            {
                dp[egg][floor] = INT_MAX;
                int left = 1, right = floor, mid;
                while(left + 1 < right)
                {
                    mid = (left + right) / 2;
                    int res1 = dp[egg-1][mid - 1];
                    int res2  = dp[egg][floor - mid];
                    if (res1 < res2)
                        left = mid;
                    else if (res1 > res2)
                        right = mid;
                    else
                        left = right = mid;
                }
                dp[egg][floor] = 1 + min(max(dp[egg-1][left - 1],dp[egg][floor - left]),
                              max(dp[egg-1][right - 1],dp[egg][floor - right]));
            }
        }
        return dp[n][k];
    }
};
