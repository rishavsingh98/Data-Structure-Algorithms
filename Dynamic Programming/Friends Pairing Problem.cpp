/*
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.

Example 1:
Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

Example 2: 
Input: N = 2
Output: 2
Explanation:
{1} , {2} : All single.
{1,2} : 1 and 2 are paired.
*/

//O(n) time and O(1) space
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        int prePrev = 1, prev = 2, mod = 1000000007, curr;
        for(long long int i = 3; i<=n; i++)
        {
            curr = (prev % mod + (i-1) % mod * prePrev % mod) % mod;
            prePrev = prev;
            prev = curr;
        }
        return curr;
    }
};  

//O(n) time and O(n) space
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        int mod = 1000000007;
        for(long long int i = 3; i<=n; i++)
            dp[i] = (dp[i-1] % mod + (i-1) % mod * dp[i-2] % mod) % mod ;
        return dp[n];
    }
};   
