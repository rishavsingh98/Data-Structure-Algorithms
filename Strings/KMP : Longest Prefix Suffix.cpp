/*
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.
NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example 1:
Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 

Example 2:
Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 
*/
class Solution{
  public:		
	int lps(string s)
	{
	    int n = s.length(), i = 0, j = 1;
	    if(n == 0 or n == 1)
	        return 0;
	    vector<int> kmp(n, 0);
	    for(int it = 1; it < n; it++)
	    {
	        if(s.at(i) == s.at(j))
	        {
	            kmp[it] = i + 1;
	            i++;
	        }
	        else
	        {     
	            i = kmp[i-1];
	            if(s.at(i) == s.at(j))
	            {
	                kmp[it] = i + 1;
	                i++;
	            }
	        }
	        j++;
	    }
	    return kmp[n-1];
	}
};
