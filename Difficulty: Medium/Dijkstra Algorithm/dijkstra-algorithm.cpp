class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Create adjacency list from edge list
        // Each node u has a list of pairs (v, weight)
        vector<vector<pair<int, int>>> adjList(V);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];  // start node
            int v = edges[i][1];  // end node
            int w = edges[i][2];  // weight of edge u-v

            // Since it's an undirected graph, add both directions
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w}); // Remove if the graph is directed
        }
        
        // Step 2: Create a min-heap (priority queue) to get the node with the smallest distance
        // The pair is (distance from source, node index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Step 3: Initialize distance vector with infinite distance
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;  // Distance to source is 0
        pq.push({0, src});  // Push source into the priority queue
        
        // Step 4: Dijkstra's main loop
        while (!pq.empty()) {
            // Get the node with the smallest known distance
            pair<int, int> P = pq.top();
            pq.pop();
            int dist = P.first;   // Current known shortest distance to node
            int node = P.second;  // Current node

            // Traverse all neighbors of the current node
            for (auto& it : adjList[node]) {
                int neighbor = it.first;     // Neighbor node
                int weight = it.second;      // Edge weight to neighbor

                // If a shorter path to neighbor is found
                if (distance[neighbor] > dist + weight) {
                    distance[neighbor] = dist + weight;  // Update distance
                    pq.push({distance[neighbor], neighbor});  // Push neighbor to queue
                }
            }
        }
        
        // Step 5: Return the shortest distances from source to all nodes
        return distance;
    }
};
