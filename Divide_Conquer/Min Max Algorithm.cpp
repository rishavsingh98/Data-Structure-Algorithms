/* 
Given an array A of size N of integers. Your task is to find the sum of minimum and maximum elements in the array.

Example 1:
Input:
N = 5
A[] = {-2, 1, -4, 5, 3}
Output: 1
Explanation: min = -4, max =  5. Sum = -4 + 5 = 1
 

Example 2:
Input:
N = 4
A[]  = {1, 3, 4, 1}
Output: 5
Explanation: min = 1, max = 4. Sum = 1 + 4 = 5

*/
class Solution
{

   public:
    pair<int,int> minMaxAlgo(int A[], int i, int j)
    {
    	int N = j - i + 1;
    	pair<int,int> minmax = make_pair(INT_MIN,INT_MAX), left,right;
    	if(N == 1)
    	{
    	    minmax.first = A[i];
    	    minmax.second = A[i];
    	}
    	else if(N==2)
    	{
    	    if(A[i]>A[i+1])
    	    {
    	        minmax.first = A[i+1];
    	        minmax.second = A[i];
    	    }
    	    else
    	    {
    	        minmax.first = A[i];
    	        minmax.second = A[i+1];
    	    }
    	}
    	else
    	{
    	    int mid = i + (j-i) / 2; 
    	    left = minMaxAlgo(A,i,mid);
    	    right = minMaxAlgo(A,mid+1,j);
    	    minmax.first = min(left.first,right.first);
    	    minmax.second = max(left.second,right.second);
    	}
    	return minmax;
    	
    }
    int findSum(int A[],int N)
    {
        pair<int,int> minmax = minMaxAlgo(A,0,N-1);
        return minmax.first+minmax.second;
    }
