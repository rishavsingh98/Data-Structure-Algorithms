/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
*/
class Solution{
    public:
    void backtrack(vector<vector<int>> &m, int n, int i, int j, vector<vector<int>> &visited, string path, vector<string>& soln)
    {
        if(i == n-1 and j == n-1)
        {
            soln.push_back(path);
            visited[i][j]=0;
            return;
        }
        else if(visited[i][j] == 1 or m[i][j] == 0)
            return;
        else
        {
            visited[i][j] = 1;
            if(i+1 < n and m[i+1][j] != 0 and visited[i+1][j] == 0)
                backtrack(m, n, i+1, j, visited, path + "D", soln);
            if(j-1 >= 0 and m[i][j-1] != 0 and visited[i][j-1] == 0)
                backtrack(m, n, i, j-1, visited, path + "L", soln);
            if(j+1 < n and m[i][j+1] != 0 and visited[i][j+1] == 0)
                backtrack(m, n, i, j+1, visited, path + "R", soln);
            if(i-1 >= 0 and m[i-1][j] != 0 and visited[i-1][j] == 0)
                backtrack(m, n, i-1, j, visited, path + "U", soln);
            visited[i][j] = 0;
            return;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<string> soln;
        backtrack(m, n, 0, 0, visited, "", soln);
        return soln;
    }
};
