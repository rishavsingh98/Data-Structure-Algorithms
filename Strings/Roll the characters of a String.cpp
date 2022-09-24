/*
Given a string S and an array roll where roll[i] represents rolling first roll[i] characters in the string, the task is to apply every roll[i] on the string and output the final string. Rolling means increasing the ASCII value of character, like rolling ‘z’ would result in ‘a’, rolling ‘b’ would result in ‘c’, etc.

Example 1:
Input: s = "bca"
roll[] = {1, 2, 3} 
Output: eeb
Explanation: arr[0] = 1 means roll 
first character of string -> cca
arr[1] = 2 means roll 
first two characters of string -> dda
arr[2] = 3 means roll
first three characters of string -> eeb
So final ans is "eeb".
*/
class Solution{
	public:
	string findRollOut(string s, long long arr[], int n)
	{
	    vector<int> suffixsum(n+1, 0);
	    
	    for(int i = 0; i < n; i++)
	        suffixsum[arr[i]]++;
	    
	    int prevSum = 0;
	    for(int i = n; i > 0; i--)
	    {
	        suffixsum[i] += prevSum;
	        int c = s.at(i-1) - 'a';
	        c += suffixsum[i];
	        c %= 26;
	        c += 'a';
	        s.at(i-1) = c;
	        prevSum = suffixsum[i];
	    }
	    return s;
	}
};
