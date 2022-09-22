/* 
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/
class Solution {
  public:
    bool DFS(int v, vector<bool>& visited, vector<bool>& recStack, vector<int> adj[])
    {
        if(visited[v] == false)
        {
            visited[v] = true;
            recStack[v] = true;
            
            for(int i = 0; i < adj[v].size(); i++)
            {
                if(!visited[adj[v][i]] and DFS(adj[v][i], visited, recStack, adj))
                    return true;
                else if(recStack[adj[v][i]])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        
        for(int i = 0; i < V; i++)
            if(!visited[i] and DFS(i, visited, recStack, adj))
                return true;
        
        return false;
    }
};
