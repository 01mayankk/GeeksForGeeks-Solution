class Solution {
private:
    // Helper function to perform topological sort using DFS
    void topoSort(int node, vector<pair<int, int>> adj[], vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        for (auto& edge : adj[node]) {
            int v = edge.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // Step 1: Create adjacency list
        vector<pair<int, int>> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // Step 2: Find the topological sort of the graph
        vector<bool> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // Step 3: Initialize distance array with INT_MIN
        vector<int> dist(V, INT_MIN);
        dist[src] = 0; // Distance to source is 0

        // Step 4: Process vertices in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // If the current node is reachable, update its adjacent nodes
            if (dist[node] != INT_MIN) {
                for (auto& edge : adj[node]) {
                    int v = edge.first;
                    int weight = edge.second;
                    
                    // Relax the edge to find the longest path
                    if (dist[node] + weight > dist[v]) {
                        dist[v] = dist[node] + weight;
                    }
                }
            }
        }

        return dist;
    }
};