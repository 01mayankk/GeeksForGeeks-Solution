class Solution {
public:
    // Depth-First Search function to explore the graph
    // node: current vertex being visited
    // parent: previous vertex (to avoid going backward in undirected graph)
    // adj: adjacency list representation of the graph
    // dist: current distance (depth) from the starting node
    // maxDist: stores the maximum distance found so far (passed by reference)
    // farthest: stores the node which is farthest from the starting node
    void dfs(int node, int parent, vector<vector<int>>& adj, int dist, int &maxDist, int &farthest) {
        // If current distance exceeds the recorded maximum, update it
        if (dist > maxDist) {
            maxDist = dist;
            farthest = node;
        }

        // Explore all neighbors of the current node
        for (int neighbor : adj[node]) {
            // Avoid going back to the parent (prevents revisiting in undirected graph)
            if (neighbor != parent) {
                dfs(neighbor, node, adj, dist + 1, maxDist, farthest);
            }
        }
    }

    int diameter(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list from edge list
        // Each vertex will have a list of connected vertices
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);  // add connection u -> v
            adj[e[1]].push_back(e[0]);  // add connection v -> u (since undirected)
        }

        // Step 2: Perform first DFS from any node (let’s take node 0)
        // This helps us find one endpoint of the longest path (farthest node)
        int farthest = 0;   // to store the farthest node found
        int maxDist = -1;   // to store the maximum distance found
        dfs(0, -1, adj, 0, maxDist, farthest);

        // Step 3: Perform second DFS from that farthest node
        // This finds the actual diameter (longest path) in the tree
        maxDist = -1;  // reset for second DFS
        dfs(farthest, -1, adj, 0, maxDist, farthest);

        // Step 4: The maximum distance found in the second DFS is the diameter
        return maxDist;
    }
};
