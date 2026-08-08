class Solution {
public:
    // Helper function to perform Depth First Search (DFS)
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1; // Mark the current node as visited
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis); // Recursively visit unvisited neighbors
            }
        }
    }
    
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // If the total number of edges is less than n - 1, 
        // it is impossible to connect all vertices.
        if (edges.size() < n - 1) {
            return -1;
        }
        
        // Create an adjacency list to represent the undirected graph
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> vis(n, 0); // Array to keep track of visited nodes
        int components = 0;    // Counter for the number of connected components
        
        // Traverse all vertices to find and count connected components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;      // Found a new distinct connected component
                dfs(i, adj, vis);  // Perform DFS to mark all reachable vertices in this component
            }
        }
        
        // The minimum number of edge movements required to connect 'c' components is 'c - 1'
        return components - 1;
    }
};