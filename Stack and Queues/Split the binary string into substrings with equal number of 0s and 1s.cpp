/*
Given binary string str of length N. The task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have an equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then return -1.

Example 1:
Input:
S = "0100110101"
Output: 4
Explanation: 
The required substrings are 01, 0011, 01 and 01.

Example 2:
Input:
S = "0111100010"
Output: 3
*/
class Solution {
public:
    int maxSubStr(string str){
        stack<char> st;
        int n = str.length(), count = 0;
        while(n--)
        {
            char c = str.at(n);
            if(st.empty())
            {
                count++;
                st.push(c);
            }
            else
            {
                if(st.top() == c)
                    st.push(c);
                else
                    st.pop();
            }
        }
        if(!st.empty())
            return -1;
        return count;
    }
};
