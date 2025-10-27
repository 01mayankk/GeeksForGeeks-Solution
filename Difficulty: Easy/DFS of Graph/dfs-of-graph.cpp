class Solution {
  public:
  
     // 🔹 Helper function for recursive DFS traversal
    void traversal(int node, vector<vector<int>>& adj, 
                   vector<bool>& visited, vector<int>& result)
    {
        // Step 1: Mark the current node as visited
        visited[node] = true;
        
        // Step 2: Add the current node to the traversal result
        result.push_back(node);
        
        // Step 3: Explore all unvisited neighbors of the current node
        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                // Recursive call to visit the neighbor
                traversal(neighbour, adj, visited, result);
            }
        }
        
        // Step 4: Return (backtrack to previous node)
        return;
    }
    
    // 🔹 Main DFS function (handles disconnected graphs as well)
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();                // Total number of nodes
        vector<bool> visited(n, false);    // Keeps track of visited nodes
        vector<int> result;                // Stores DFS traversal order
        
        // Step 5: Loop through all nodes to handle disconnected components
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                // Perform DFS starting from node i
                traversal(i, adj, visited, result);
            }
        }
        
        // Step 6: Return the complete DFS traversal order
        return result;
    }

};