/*
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:
Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.
*/
class Solution
{
    public:
    bool ispar(string x)
    {
        stack<char> st;
        int n = x.length();
        for(int i = 0; i<n; i++)
        {
            char c = x.at(i);
            
            if(st.empty() or c == '(' or c == '{' or c == '[')
                st.push(c);
            
            else if((c == ')' and st.top() == '(')
                 or (c == '}' and st.top() == '{') 
                 or (c == ']' and st.top() == '['))
                 st.pop();
            
            else
                break;
        }
        
        if(!st.empty())
            return false;
        else
            return true;
    }

};
