/*
A car factory has two assembly lines, and also given an  2D array a[2][] of size N which represent the time taken by each station. Each station is dedicated to some sort of work like engine fitting, body fitting, painting, and so on. So, a car chassis must pass through each of the n stations in order before exiting the factory. The two parallel assemble line perform same task.
From any line one can switch another line diagonally. A 2D array T[2][] of size N is also given, which represent  exit time to switch line 1 to line 2 diagonally.
Also each assembly line takes an entry time ei and exit time xi which may be different for the two lines.

The task is to computing the minimum time it will take to build a car chassis.
One can minimize the total time taken by performing following steps:

 A car chassis must pass through all stations from 1 to N in order(in any of the two assembly lines). i.e. it cannot jump from station i to station j if they are not at one move distance.
The car chassis can move one station forward in the same line, or one station diagonally in the other line. It incurs an extra cost Ti,j to move to station j from line i. No cost is incurred for movement in same line.
The time taken in station j on line i is ai, j.

Example 1:
Input: N = 4
a[2][] = {{4, 5, 3, 2}, 
      {2, 10, 1, 4}}
T[2][] = {{0,7, 4, 5},
           {0,9, 2, 8}}
e[2] = {10,12}, x[2] = {18,7}
Output: 35
*/
class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      int n = a[0].size();
      vector<int> lines;
      lines.push_back(x[0] + a[0][n-1]);
      lines.push_back(x[1] + a[1][n-1]);
      for(int i = n-2; i >= 0; i--)
      {
          int temp0,temp1;
          temp0 = min(lines[0] + a[0][i], lines[1] + T[0][i+1] + a[0][i]);
          temp1 = min(lines[1] + a[1][i], lines[0] + T[1][i+1] + a[1][i]);
          lines[0] = temp0;
          lines[1] = temp1;
      }
      return min(e[0] + lines[0], e[1] + lines[1]);
  }
};
