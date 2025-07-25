class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Min-heap: {weight, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<bool> visited(V, false);  // To track included vertices in MST
        int mstWeight = 0;               // Total weight of MST
        
        // Start from vertex 0 with weight 0
        pq.push({0, 0});
        
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();  // FIX: Add parentheses
            
            int weight = p.first;
            int vertex = p.second;
            
            // If already visited, skip to avoid cycle
            if (visited[vertex]) continue;
            
            // Include this vertex in MST
            visited[vertex] = true;
            mstWeight += weight;
            
            // Traverse adjacent vertices
            for (auto it : adj[vertex]) {
                int adjVertex = it[0];
                int adjWeight = it[1];
                
                // If not visited, push to heap
                if (!visited[adjVertex]) {
                    pq.push({adjWeight, adjVertex});
                }
            }
        }
        
        return mstWeight;
    }
};
