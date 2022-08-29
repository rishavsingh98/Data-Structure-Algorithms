/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/
//O(N) time and O(N) space
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> storesum;
        int start = 0, end = -1, sum = 0, maxlen = 0;
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
};
