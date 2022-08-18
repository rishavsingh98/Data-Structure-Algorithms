/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive fences have the same colors. Since the answer can be large return it modulo 10^9 + 7.

Example 1:
Input:
N=3,  K=2 
Output: 6

Example 2:
Input:
N=2,  K=4
Output: 16
*/
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        unsigned long long mod = 1000000007, prePrev = k, prev = k*k % 1000000007, curr;
        if(n == 1)
            return prePrev;
        else if(n == 2)
            return prev;
        for(int i = 2; i < n; i++)
        {
            curr = (k-1) * ( prev % mod + prePrev % mod) % mod;
            prePrev = prev;
            prev = curr;
        }
        return curr;
    }
};
