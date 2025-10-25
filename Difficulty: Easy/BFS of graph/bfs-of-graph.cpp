class Solution {
  public:
    // Function to return Breadth First Traversal of the given graph.
    vector<int> bfs(vector<vector<int>> &adj) {

        int totalNodes = adj.size();                 // Total number of nodes in the graph (size of adjacency list)

        vector<bool> visited(totalNodes, false);     // Boolean array to keep track of visited nodes
        vector<int> bfsOrder;                        // Vector to store the BFS traversal order
        queue<int> q;                                // Queue to process nodes in FIFO order (essential for BFS)

        // Loop through all nodes to handle disconnected graphs
        for (int start = 0; start < totalNodes; ++start) {
            
            // If the current node has not been visited yet
            if (!visited[start]) {
                
                visited[start] = true;               // Mark the starting node as visited
                q.push(start);                       // Enqueue the starting node

                // Process all nodes reachable from this starting node
                while (!q.empty()) {
                    int node = q.front();            // Get the front node from the queue
                    q.pop();                         // Remove it from the queue
                    bfsOrder.push_back(node);        // Add it to the BFS traversal order

                    // Explore all adjacent (connected) nodes of the current node
                    for (int neighbour : adj[node]) {
                        // If the neighbour hasn't been visited yet
                        if (!visited[neighbour]) {
                            visited[neighbour] = true; // Mark neighbour as visited
                            q.push(neighbour);         // Add neighbour to queue for future processing
                        }
                    }
                }
            }
        }

        return bfsOrder;                             // Return the complete BFS traversal order
    }
};
