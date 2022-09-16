/*
Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 

Example 1:
Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}

Example 2:
Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}
*/
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> sum(n, -1);
	    for(int i = 0; i<n; i++)
	    {
	        int max_pre = 0;
	        for(int j = 0; j < i ; j++)
	        {
	            if(arr[j] < arr[i] and sum[j] > max_pre)
	                max_pre = sum[j];
	        }
	        sum[i] = max_pre + arr[i];
	    }
	    return *max_element(sum.begin(), sum.end());
	}  
};
