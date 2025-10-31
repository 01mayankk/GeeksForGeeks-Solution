#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list for the undirected graph
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;  // Initialize shortest cycle length as infinity

        // Step 2: Run BFS from every vertex to find the shortest cycle
        for (int i = 0; i < V; i++) {
            // dist[] stores distance of each node from current source 'i'
            vector<int> dist(V, -1);

            // parent[] stores the immediate parent of each node in BFS
            vector<int> parent(V, -1);

            // Queue for BFS
            queue<int> q;

            // Start BFS from node i
            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                // Explore all adjacent vertices
                for (int neigh : adj[node]) {
                    // If neighbour not visited yet
                    if (dist[neigh] == -1) {
                        dist[neigh] = dist[node] + 1;
                        parent[neigh] = node;
                        q.push(neigh);
                    } 
                    // If neighbour already visited and is not parent of current node
                    // then we found a cycle
                    else if (parent[node] != neigh) {
                        // Length of cycle = distance to both nodes + 1 (for current edge)
                        ans = min(ans, dist[node] + dist[neigh] + 1);
                    }
                }
            }
        }

        // Step 3: If no cycle found, return -1
        if (ans == INT_MAX) return -1;

        // Step 4: Return length of shortest cycle
        return ans;
    }
};
