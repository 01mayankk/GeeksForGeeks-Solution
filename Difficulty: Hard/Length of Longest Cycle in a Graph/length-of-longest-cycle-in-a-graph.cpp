class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        
        // Step 1: Create a "next" array since each node has at most one outgoing edge
        vector<int> next(V, -1);
        for (auto &e : edges) {
            next[e[0]] = e[1]; // u -> v
        }
        
        // Step 2: Visited array to avoid re-processing nodes
        vector<bool> vis(V, false);
        
        int maxLen = -1; // stores answer
        
        // Step 3: Traverse every node
        for (int i = 0; i < V; i++) {
            
            // Skip if already visited
            if (vis[i]) continue;
            
            // Map to store visit time of nodes in current traversal
            unordered_map<int, int> timeVisited;
            
            int node = i;
            int time = 0;
            
            // Traverse the path
            while (node != -1 && !vis[node]) {
                
                vis[node] = true;              // mark visited
                timeVisited[node] = time++;   // store visit time
                
                node = next[node];            // move to next node
                
                // If node already seen in current path → cycle found
                if (node != -1 && timeVisited.count(node)) {
                    
                    // cycle length = current time - first visit time
                    int cycleLen = time - timeVisited[node];
                    
                    maxLen = max(maxLen, cycleLen);
                    break;
                }
            }
        }
        
        return maxLen;
    }
};