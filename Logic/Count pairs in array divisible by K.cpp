/*
Given an array A[] and positive integer K, the task is to count total number of pairs in the array whose sum is divisible by K.

Example 1:
Input : A[] = {2, 2, 1, 7, 5, 3}, K = 4
Output : 5
Explanation : There are five pairs possible whose sum is divisible by '4' i.e., (2, 2), (1, 7), (7, 5), (1, 3) and (5, 3)

Example 2:
Input : A[] = {5, 9, 36, 74, 52, 31, 42}, K = 3
Output : 7 
Explanation : There are seven pairs whose sum is divisible by 3, i.e, (9, 36), (9,42), (74, 52), (36, 42), (74, 31), (31, 5) and (5, 52).
*/
class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        unordered_map<int,int> divMap;
        long long count = 0;
        for(int i = 0; i < n; i++)
        {
            int curr = A[i]%K;
            int req = (K - curr)%K;
            if(divMap.find(req) != divMap.end())
                count += divMap[req];
            divMap[curr]++;
        }
        return count;
    }
};
