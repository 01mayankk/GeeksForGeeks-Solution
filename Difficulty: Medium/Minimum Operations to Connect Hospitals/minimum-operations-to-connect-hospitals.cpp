class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        int E = edges.size();
        
        // ------------------------------------------------------------
        // IMPORTANT OBSERVATION:
        // To connect V hospitals (nodes) into one single connected graph,
        // the minimum number of edges required is (V - 1).
        //
        // If we have fewer edges than this, no number of "rearrangements"
        // can connect all nodes. So return -1 immediately.
        // ------------------------------------------------------------
        if (E < V - 1) return -1;

        // ------------------------------------------------------------
        // Build the adjacency list representation of the graph.
        // Since edges are given as undirected connections between hospitals,
        // we store u -> v and v -> u.
        // ------------------------------------------------------------
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);  // add v to u's list
            adj[e[1]].push_back(e[0]);  // add u to v's list
        }
        
        // ------------------------------------------------------------
        // visited[] keeps track of which hospitals we have already explored.
        // Initially, all nodes are unvisited.
        // ------------------------------------------------------------
        vector<bool> visited(V, false);

        int components = 0;  // This will count the number of connected components

        // ------------------------------------------------------------
        // DFS function:
        // This recursively explores all hospitals reachable from 'node'.
        //
        // Once DFS starts from a node, it visits every node in that
        // connected component.
        // ------------------------------------------------------------
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;   // mark current node as visited
            
            // Visit all directly connected neighbors
            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    dfs(nei);       // recursive DFS call for neighbor
                }
            }
        };
        
        // ------------------------------------------------------------
        // MAIN LOGIC:
        // Loop through all nodes.
        // Whenever we find an unvisited node, it means we found a NEW
        // connected component.
        //
        // We then run DFS starting from that node to mark the entire
        // component as visited.
        // ------------------------------------------------------------
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                components++;  // Found a new component
                dfs(i);        // Explore the whole component
            }
        }
        
        // ------------------------------------------------------------
        // FINAL RESULT:
        //
        // Suppose the graph has 'components' separate parts.
        // To connect them into one single connected structure, we need:
        //
        //     (components - 1) operations.
        //
        // Because connecting 2 components needs 1 edge,
        // connecting 3 components needs 2 edges, etc.
        //
        // Since we already checked E >= V-1 earlier, we know
        // enough edges exist to perform these reconnections.
        // ------------------------------------------------------------
        return components - 1;
    }
};
