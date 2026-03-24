class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        
        // Edge case: if only one node, it is the answer
        if (V == 1) return {0};

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);  // stores degree of each node

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;   // increment degree of u
            degree[v]++;   // increment degree of v
        }

        // Step 2: Push all leaf nodes (degree = 1) into queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        // Step 3: Remove leaves level by level
        int remainingNodes = V;

        while (remainingNodes > 2) {
            int size = q.size();     // number of current leaves
            remainingNodes -= size;  // remove these leaves

            while (size--) {
                int leaf = q.front();
                q.pop();

                // Reduce degree of neighbors
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;

                    // If neighbor becomes leaf, add to queue
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Step 4: Remaining nodes are centroids (answer)
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};