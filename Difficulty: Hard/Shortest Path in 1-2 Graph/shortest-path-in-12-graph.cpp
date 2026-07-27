class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        // Create an adjacency list: adj[u] will contain pairs of (neighbor, weight)
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // The graph is undirected
        }
        
        // Min-heap priority queue to store {distance, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Distance array initialized to a very large value (representing infinity)
        vector<int> dist(V, 1e9);
        
        // Initialize the source vertex
        pq.push({0, src});
        dist[src] = 0;
        
        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // If we reached the destination, return the shortest distance found
            if (u == dest) {
                return currentDist;
            }
            
            // If we already found a shorter path to 'u', skip it
            if (currentDist > dist[u]) {
                continue;
            }
            
            // Traverse all adjacent vertices of 'u'
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                // Relaxation step: Update if a shorter path to 'v' is found
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // If the destination is unreachable after exploring all possibilities, return -1
        return dist[dest] == 1e9 ? -1 : dist[dest];
    }
};