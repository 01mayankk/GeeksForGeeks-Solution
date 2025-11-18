class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        // MOD value to prevent overflow in counting paths
        const long long MOD = 1e9 + 7;

        // -----------------------------
        // STEP 1: Build adjacency list
        // -----------------------------
        // Each entry: adj[u] = list of (neighbor, travel_time)
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : roads) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            // Since graph is undirected, add both directions
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // ------------------------------------------
        // STEP 2: Initialize distance & ways arrays
        // ------------------------------------------

        // dist[i] = shortest time needed to reach node i
        vector<long long> dist(n, LLONG_MAX);

        // ways[i] = number of ways to reach node i
        // using the shortest possible time
        vector<long long> ways(n, 0);

        // ------------------------------------------
        // STEP 3: Min-heap for Dijkstra
        // Stores pairs (distance, node)
        // Always processes the smallest distance first
        // ------------------------------------------
        priority_queue<
            pair<long long, int>,                // (dist, node)
            vector<pair<long long, int>>,        // container
            greater<pair<long long, int>>        // min-heap
        > pq;

        // ------------------------------------------
        // STEP 4: Initialize source node (node 0)
        // ------------------------------------------

        dist[0] = 0;     // distance to itself is 0
        ways[0] = 1;     // exactly one way to be at start node
        pq.push({0, 0}); // (distance, node)

        // ------------------------------------------
        // STEP 5: Standard Dijkstra loop
        // ------------------------------------------
        while (!pq.empty()) {

            // Extract node with smallest current distance
            auto [currDist, u] = pq.top();
            pq.pop();

            // If this distance is outdated (not equal to best known),
            // we skip processing this node.
            if (currDist > dist[u])
                continue;

            // ------------------------------------------
            // STEP 6: Relax all adjacent edges
            // ------------------------------------------
            for (auto &[v, w] : adj[u]) {

                long long newDist = currDist + w; // new possible distance to v through u

                // --------------------------------------------------------
                // CASE 1: Found a BETTER (shorter) path to v
                // --------------------------------------------------------
                if (newDist < dist[v]) {

                    // Update the shortest distance
                    dist[v] = newDist;

                    // All shortest ways to u now become the shortest ways to v
                    ways[v] = ways[u];

                    // Push new better distance into the min-heap
                    pq.push({newDist, v});
                }

                // --------------------------------------------------------
                // CASE 2: Found ANOTHER shortest path to v (equal distance)
                // --------------------------------------------------------
                else if (newDist == dist[v]) {

                    // Add all ways to u to ways to v
                    ways[v] = (ways[v] + ways[u]) % MOD;

                    // No need to push into heap again because same shortest dist
                }
            }
        }

        // ------------------------------------------
        // STEP 7: Return number of shortest paths to node n-1
        // ------------------------------------------
        return ways[n - 1] % MOD;
    }
};
