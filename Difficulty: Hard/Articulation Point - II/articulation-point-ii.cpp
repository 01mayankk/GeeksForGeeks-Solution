class Solution {
public:

    // DFS function to find articulation points using Tarjan's Algorithm
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc,
             vector<int>& low, vector<bool>& visited,
             vector<bool>& isAP, int& timer) {

        // Mark current node as visited
        visited[u] = true;

        // Initialize discovery time and low value
        disc[u] = low[u] = timer++;

        int children = 0;  // Count of children in DFS tree

        // Traverse all adjacent vertices
        for (int v : adj[u]) {

            // Case 1: If v is not visited → Tree Edge
            if (!visited[v]) {
                children++;

                // Recur for child node
                dfs(v, u, adj, disc, low, visited, isAP, timer);

                // Update low value of current node using child
                low[u] = min(low[u], low[v]);

                // Check articulation point condition for non-root node
                // If no back edge from subtree rooted at v to ancestors of u
                if (parent != -1 && low[v] >= disc[u]) {
                    isAP[u] = true;
                }
            }

            // Case 2: Back Edge (ignore edge to parent)
            else if (v != parent) {
                // Update low value using back edge
                low[u] = min(low[u], disc[v]);
            }
        }

        // Special case: If u is root of DFS tree
        // and has more than one child → articulation point
        if (parent == -1 && children > 1) {
            isAP[u] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {

        // Step 1: Create adjacency list for graph
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            // Since graph is undirected, add both directions
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Initialize required arrays
        vector<int> disc(V, -1);      // Discovery time of nodes
        vector<int> low(V, -1);       // Lowest reachable discovery time
        vector<bool> visited(V, false);
        vector<bool> isAP(V, false);  // Mark articulation points

        int timer = 0;  // Global timer for DFS

        // Step 3: Run DFS for each unvisited node (for disconnected graph)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, isAP, timer);
            }
        }

        // Step 4: Collect all articulation points
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isAP[i]) {
                result.push_back(i);
            }
        }

        // Step 5: If no articulation point found, return {-1}
        if (result.empty()) return {-1};

        return result;
    }
};