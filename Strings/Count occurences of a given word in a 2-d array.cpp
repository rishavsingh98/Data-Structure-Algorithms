/*
Find the number of occurrences of a given search word in  a 2d-Array of characters where the word can go up, down, left, right and around 90 degree bends.

Example 1:
Input: 
R = 4, C = 5
mat = {{S,N,B,S,N},
       {B,A,K,E,A},
       {B,K,B,B,K},
       {S,E,B,S,E}}
target = SNAKES
Output:
3
Explanation: 
S N B S N
B A K E A
B K B B K
S E B S E
Total occurrence of the word is 3
and denoted by color.

Example 2:
Input:
R = 3, C = 3 
mat = {{c,a,t},
       {a,t,c},
       {c,t,a}}
target = cat
Output:
5
*/
class Solution{
    public:
    int search(vector<vector<char>>mat, int i, int j, int& max_row, int& max_col, string& target, int index, int& max_size)
    {
        if(i >= 0 and j >= 0 and i < max_row and j < max_col and index < max_size and mat[i][j] == target.at(index))
        { 
            index++;
            if(index == max_size)
                return 1;
            mat[i][j] = ' ';
            int x= search(mat, i-1, j, max_row, max_col, target, index, max_size) 
                 + search(mat, i+1, j, max_row, max_col, target, index, max_size)
                 + search(mat, i, j-1, max_row, max_col, target, index, max_size)
                 + search(mat, i, j+1, max_row, max_col, target, index, max_size);
            return x;
        }        
        else
            return 0;
    }
    
    int findOccurrence(vector<vector<char>> &mat, string target)
    {
        int n = mat.size(), m = mat[0].size(), count = 0, size = target.length();
        for(int i = 0 ; i < n; i++)
            for(int j = 0; j < m; j++)
                count += search(mat, i, j, n, m, target, 0, size);
        
        return count;
    }
};
