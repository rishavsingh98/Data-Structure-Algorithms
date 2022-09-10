/*
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

Example 1:
Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
*/
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_map<char,int> cmap;
        int n = str.length() , start = 0, end = 0, count = 0, min_str = str.length(), curr_count = 0;
        for(int i = 0; i <n ; i++)
        { 
          if(cmap.find(str.at(i)) == cmap.end())
          {
            cmap[str.at(i)] = 0;
            count++;
          }
        }
        while(end < n)
        {
            if(cmap[str.at(end)] == 0)
                curr_count++;
            
            cmap[str.at(end)]++;
            
            if(curr_count == count)
            {
                min_str = min(min_str, end - start + 1);
                while(curr_count == count)
                {
                    min_str = min(min_str, end - start + 1);
                    cmap[str.at(start)]--;
                    if(cmap[str.at(start)] == 0)
                        curr_count--;
                    start++;
                }
                
            }
            end++;
        }
        return min_str;
        
    }
};
