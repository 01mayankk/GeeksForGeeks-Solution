class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        
        int n = houses.size();  // Number of houses (nodes)

        // Min-heap (priority queue) to always pick the minimum cost edge
        // Stores pairs: {cost to connect, node index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Visited array to keep track of nodes already included in MST
        vector<bool> visited(n, false);
        
        // Start Prim's Algorithm from node 0 with cost 0
        pq.push({0, 0});
        
        int totalCost = 0;   // Stores final minimum cost
        int edgesUsed = 0;   // Counts how many nodes are included in MST
        
        // Continue until all nodes are included
        while(edgesUsed < n) {
            
            // Get the edge with minimum cost
            auto [cost, u] = pq.top();
            pq.pop();
            
            // If this node is already included, skip it
            if(visited[u]) continue;
            
            // Include current node in MST
            visited[u] = true;
            
            // Add its cost to total MST cost
            totalCost += cost;
            
            // Increase count of included nodes
            edgesUsed++;
            
            // Explore all other nodes to find possible edges
            for(int v = 0; v < n; v++) {
                
                // Only consider nodes not yet included in MST
                if(!visited[v]) {
                    
                    // Manhattan Distance between house u and house v
                    int dist = abs(houses[u][0] - houses[v][0]) + 
                               abs(houses[u][1] - houses[v][1]);
                    
                    // Push this edge into min-heap
                    pq.push({dist, v});
                }
            }
        }
        
        // Return the minimum cost to connect all houses
        return totalCost;
    }
};