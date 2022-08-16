/*
Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:
Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Example 2:
Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.
*/
//O(n^2) time O(n^2) space
class Solution{
public:
    int nCr(int n, int r){
        if(r>n)
            return 0;
        vector<int>vec{1};
        vector<vector<int>>pascal(n+1,vec);
        pascal[1].push_back(1);
        int i, j, mod = 1000000007;
        for(i = 2; i <= n; i++)
        {
            for(j = 1; j <= (i/2); j++)
                pascal[i].push_back((pascal[i-1][j-1] + pascal[i-1][j]) % mod); 
            for(; j <= i; j++)
                pascal[i].push_back(pascal[i][i-j] % mod);
        }
        return pascal[n][r];
    }
};

//O(nr) time O(r) space
class Solution{
public:
    int nCr(int n, int r){
        if(r>n)
            return 0;
        if(r > n-r) r = n-r;
        vector<int>pascal(r+1,0);
        pascal[0] = 1;
        int i, j, mod = 1000000007;
        for(i = 1; i <= n; i++)
        {
            for( j = min(r,n); j > 0 ; j--)
                pascal[j] = (pascal[j-1] + pascal[j]) % mod;
        }
        return pascal[r];
    }
};
