/*
https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1

You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

Example 1:
Input:
A = "ccad"
Output: "aacd"
Explanation:
In ccad, we choose a and c and after 
doing the replacement operation once we get, 
aacd and this is the lexicographically
smallest string possible. 
 

Example 2:
Input:
A = "abba"
Output: "abba"
Explanation:
In abba, we can get baab after doing the 
replacement operation once for a and b 
but that is not lexicographically smaller 
than abba. So, the answer is abba. 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string LexicographicallyMinimum(string str){
		    // Code here
		    int firstOccr[26];
		    memset(firstOccr,-1,sizeof(firstOccr));
		    int n = str.length(), i, j, flag = 0;
		    for(i = 0; i<n; i++ )
		    {
		        if(firstOccr[(int)str.at(i) - 97] == -1)
		            firstOccr[(int)str.at(i) - 97] = i;
		    }
		    
		    for(i = 0; i < n; i ++)
		    {
		        for(j = 0; j < ((int)str.at(i)-97); j++)
		        {
		            if(firstOccr[j] > firstOccr[(int)(str.at(i) - 97)])
		            {
		                flag = 1;
		                break;
		            }
		        }
		        if(flag)
		            break;
		    }
		    if(flag)
		    {
		        char toswap = str.at(i);
                char frswap = char(j + 97);
                for(i = 0; i< n; i++)
                {
                    if (str.at(i) == toswap)
                        str.at(i) = frswap;
       
                    else if (str.at(i) == frswap)
                        str.at(i) = toswap;
                    
                }
                return str;
		    }
		    else
		        return str;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		string ans = obj.LexicographicallyMinimum(str);
		cout << ans << "\n";
	}
	return 0;
}
