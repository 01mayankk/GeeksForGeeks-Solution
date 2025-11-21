#include <bits/stdc++.h>
using namespace std;

/*
  Solution class implemented for:
  "Shortest Path Using At most One Curved Edge"

  Key idea:
  - Compute shortest distances using only straight edges from 'a' to all nodes
    and from 'b' to all nodes (two Dijkstra runs).
  - Then, for each double-edge (x, y, w1, w2) consider using the curved edge
    (w2) exactly once either in direction x->y or y->x, combining with the
    precomputed straight-only shortest paths.
  - Take the minimum among: pure straight path (no curved edge) and all
    combinations that use one curved edge.
*/

class Solution {
public:

    // Run Dijkstra on straight edges only
    // src : starting vertex
    // V   : number of vertices
    // adj : adjacency list where adj[u] has pairs {v, w} representing
    //       straight edges (w1)
    //
    // Returns: vector<long long> dist of size V where dist[i] is the shortest
    // distance from src to i using only straight edges. If a node is
    // unreachable, its distance will be INF.
    vector<long long> dijkstra(int src, int V,
                               vector<vector<pair<int,int>>> &adj) 
    {
        // A large value to represent "infinity" for unreachable nodes.
        const long long INF = 1e18;

        // dist[i] will hold the shortest discovered distance from src to i.
        vector<long long> dist(V, INF);

        // Min-heap (priority_queue with greater comparator).
        // Each element is {distance, vertex}.
        // We store distance first so the priority queue orders by smallest distance.
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        // Distance to source is zero.
        dist[src] = 0;
        pq.push({0, src});

        // Standard Dijkstra loop.
        while (!pq.empty()) {
            // Get the node with the smallest tentative distance.
            auto [d, u] = pq.top();
            pq.pop();

            // If this popped distance is not equal to current stored dist[u],
            // then we have already found a better path earlier; skip this one.
            if (d != dist[u]) continue;

            // Relax all neighbors of u.
            for (auto &p : adj[u]) {
                int v = p.first;   // neighbor vertex
                int w = p.second;  // edge weight (straight edge)

                // If going to v via u gives a shorter path, update.
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v}); // push new tentative distance
                }
            }
        }

        return dist; // contains shortest straight-only distances from src
    }


    // Main function to compute shortest path from vertex 'a' to vertex 'b'
    // with constraint: use at most one curved edge in the entire path.
    //
    // V     : number of vertices
    // a, b  : start and destination vertices
    // edges : list of E double-edges; each entry is a vector<int> of size 4:
    //         {x, y, w1, w2} representing undirected straight edge of weight w1
    //         and a curved edge of weight w2 between x and y.
    //
    // Returns the shortest path cost satisfying "at most one curved edge", or -1
    // if no such path exists.
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        
        // Use a large INF value for unreachable detection and safe arithmetic.
        const long long INF = 1e18;

        // Build adjacency list using only straight edges (w1).
        // We will run Dijkstra on this graph twice (from a and from b).
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            // e is expected to be size 4: {x, y, w1, w2}
            int x = e[0], y = e[1];
            int w1 = e[2];  // straight edge weight

            // Undirected graph: add both directions for straight edges.
            adj[x].push_back({y, w1});
            adj[y].push_back({x, w1});
        }

        // Compute shortest distances using only straight edges:
        // distA[v] = shortest distance from a -> v (straight edges only)
        // distB[v] = shortest distance from b -> v (straight edges only)
        vector<long long> distA = dijkstra(a, V, adj);
        vector<long long> distB = dijkstra(b, V, adj);

        // Initialize answer with the fully straight path (no curved edge).
        // distA[b] might be INF if b is unreachable using only straight edges.
        long long ans = distA[b];

        // Now consider using exactly one curved edge (w2). For each double-edge
        // (x, y, w1, w2) we have two possibilities:
        // 1) path from a -> ... -> x  (straight only) + curved x->y (w2) + ... -> b (straight only)
        //    cost = distA[x] + w2 + distB[y]
        // 2) similarly using curved y->x:
        //    cost = distA[y] + w2 + distB[x]
        //
        // We try both directions because the graph is undirected but the curved
        // edge can be considered used in either direction in a path.
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            int w2 = e[3];  // curved edge weight

            // If distA[x] is INF then a cannot reach x via straight edges,
            // so option 1 is invalid; likewise distB[y] must be reachable from b.
            if (distA[x] != INF && distB[y] != INF) {
                long long cand = distA[x] + (long long)w2 + distB[y];
                if (cand < ans) ans = cand;
            }

            // Option 2: use curved edge from y -> x
            if (distA[y] != INF && distB[x] != INF) {
                long long cand = distA[y] + (long long)w2 + distB[x];
                if (cand < ans) ans = cand;
            }
        }

        // If the best answer is still INF (or larger), there is no valid path
        // respecting the constraint; return -1 as required.
        if (ans >= INF) return -1;

        // Otherwise, cast to int (problem statement guarantees it fits in 32-bit).
        return (int)ans;
    }
};
