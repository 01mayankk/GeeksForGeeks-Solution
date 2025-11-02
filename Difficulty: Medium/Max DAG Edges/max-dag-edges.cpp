class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        
        // Step 1️⃣: Build adjacency list and indegree array
        // -------------------------------------------------
        // We'll store all outgoing edges from each vertex in 'adj'
        // and track how many incoming edges each vertex has in 'indegree'.
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]); // directed edge u -> v
            indegree[e[1]]++;          // increase indegree of v
        }
        
        
        // Step 2️⃣: Perform Kahn’s Algorithm to get Topological Order
        // ------------------------------------------------------------
        // In a DAG, at least one vertex has indegree 0 (no incoming edges).
        // We process such nodes, and reduce indegree of their neighbors.
        // The resulting order of processing gives us a valid topological order.
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) 
                q.push(i);
        }
        
        vector<int> topo; // stores topological order
        
        while (!q.empty()) {
            int node = q.front(); 
            q.pop();
            topo.push_back(node);
            
            // Reduce indegree of all its neighbors
            for (int nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        
        // Step 3️⃣: Record all existing edges
        // ------------------------------------
        // To quickly check if an edge already exists (u -> v),
        // we'll store this information in a 2D boolean matrix.
        vector<vector<bool>> hasEdge(V, vector<bool>(V, false));
        for (auto &e : edges) {
            hasEdge[e[0]][e[1]] = true;
        }
        
        
        // Step 4️⃣: Count how many new edges can be added
        // -----------------------------------------------
        // In a DAG with topological order [t0, t1, t2, ..., tV-1],
        // you can safely add edges only from earlier → later nodes in this order.
        // (Adding the opposite would create a cycle.)
        
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int u = topo[i];
                int v = topo[j];
                
                // If edge u->v does not already exist, we can add it safely.
                if (!hasEdge[u][v])
                    count++;
            }
        }
        
        
        // Step 5️⃣: Return the total number of new edges that can be added
        // ----------------------------------------------------------------
        return count;
    }
};
