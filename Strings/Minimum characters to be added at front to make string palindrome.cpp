/*
Given string str of length N. The task is to find the minimum characters to be added at front to make string palindrome.
Note: A palindrome is a word which reads the same backward as forward. Example : madam.

Example 1:
Input:
S = "abc"
Output: 2
Explanation: 
Add 'b' and 'c' at front of above string to make it
palindrome : "cbabc"

Example 2:
Input:
S = "aacecaaaa"
Output: 2
*/
class Solution {
public:
    int minChar(string str)
    {
        int n = str.length(), left = 0, right =  str.length() - 1, end = str.length() - 1;
        while(left < right)
        {
            if(str.at(left) == str.at(right))
            {
                left++;
                right--;
            }
            else if(str.at(0) == str.at(right))
            {
                left = 1;
                end = right;
                right--;
            }
            else
            {
                left = 0;
                right--;
                end = right;
            }
        }
        return n - end - 1;
    }
};
