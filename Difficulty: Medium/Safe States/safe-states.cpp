class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Step 1: Build the reversed graph and compute indegree for each node
        // -------------------------------------------------------------------
        // In the original graph: u -> v
        // In the reversed graph: v -> u
        // This helps us identify which nodes can lead to a terminal node.
        
        vector<vector<int>> adjRev(V);   // Reversed adjacency list
        vector<int> indegree(V, 0);      // Stores indegree of each node in the reversed graph

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            // Reverse the edge direction (v -> u)
            adjRev[v].push_back(u);

            // Increment indegree of 'u' (in reversed graph)
            indegree[u]++;
        }

        // Step 2: Initialize a queue for nodes with indegree = 0
        // -------------------------------------------------------
        // These nodes are terminal nodes in the original graph
        // (since they have no outgoing edges originally)
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i); // Add all terminal nodes
        }

        // Step 3: Apply Kahn’s Algorithm (Topological BFS)
        // ------------------------------------------------
        // Process nodes with 0 indegree and reduce the indegree
        // of their neighbors. If a neighbor’s indegree becomes 0,
        // it also becomes "safe" (i.e., all its paths lead to terminal nodes).
        
        vector<int> safe; // Stores all safe nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            // Traverse all neighbors of current node
            for (int neighbor : adjRev[node]) {
                indegree[neighbor]--; // Decrease indegree
                if (indegree[neighbor] == 0) {
                    // If indegree becomes 0, push to queue
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Sort safe nodes in ascending order (as required by the problem)
        sort(safe.begin(), safe.end());

        // Step 5: Return the list of safe nodes
        return safe;
    }
};
