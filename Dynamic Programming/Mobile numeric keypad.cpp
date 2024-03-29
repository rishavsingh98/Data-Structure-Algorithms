/*
Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button or the current button itself (like 00,11, etc.). You are not allowed to press the bottom row corner buttons (i.e. * and # ). Given a number N, the task is to find out the number of possible numbers of the given length.

Example 1:
Input: 1
Output: 10
Explanation: Number of possible numbers 
would be 10 (0, 1, 2, 3, ., 9)  

Example 2:
Input: N = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11,
12, 14, 22, 21, 23, 25 and so on.
If we start with 0, valid numbers 
will be 00, 08 (count: 2)
If we start with 1, valid numbers 
will be 11, 12, 14 (count: 3)
If we start with 2, valid numbers 
will be 22, 21, 23,25 (count: 4)
If we start with 3, valid numbers 
will be 33, 32, 36 (count: 3)
If we start with 4, valid numbers 
will be 44,41,45,47 (count: 4)
If we start with 5, valid numbers 
will be 55,54,52,56,58 (count: 5) 
and so on..
*/
class Solution{
	public:
	long long getCount(int N)
	{
		if(N == 0)
		    return 0;
		if(N==1)
		    return 10;
		    
		long long count = 0;
		vector<vector<long long>> mobile(4, vector<long long>(3, 1));
		mobile[3][0] = 0;
		mobile[3][2] = 0;
		for(int it = 2; it <= N; it++)
		{
		    vector<vector<long long>> temp(4, vector<long long>(3, 0));
		   
		    for(int i = 0; i < 4; i++)
		    {
		        
		        for(int j = 0; j < 3; j++)
		        {
		            if(i == 3 and (j == 0 or j == 2))
		                continue;
		            temp[i][j] += mobile[i][j];
		            
		            if(j > 0)
		                temp[i][j] +=  mobile[i][j-1];
		            if(j < 2)
		                temp[i][j] += mobile[i][j+1];
		            if(i > 0)
		                temp[i][j] += mobile[i-1][j];
		            if(i< 3)
		                temp[i][j] += mobile[i+1][j];
		        }
		    }
		    for(int i = 0; i < 4; i++)
		        for(int j = 0; j < 3; j++)
		            mobile[i][j] = temp[i][j];
		        
		}
		
		for(int i = 0; i < 4; i++)
		    for(int j = 0; j < 3; j++)
		        count += mobile[i][j];
		        
		return count;
	}


};
