class Solution {
  public:
  
    // DFS function to visit all reachable vertices
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
    {
        // Mark current node as visited
        visited[node] = true;
        
        // Traverse all adjacent vertices
        for(int neighbour : adj[node])
        {
            // If neighbour is not visited, visit it
            if(!visited[neighbour])
            {
                dfs(neighbour, adj, visited);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {
        
        // Step 1: Create adjacency list
        vector<vector<int>> adj(V);
        
        // Convert edge list into adjacency list
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        // Visited array to keep track of visited vertices
        vector<bool> visited(V, false);
        
        // Variable to store possible mother vertex
        int candidate = -1;
        
        /*
            Step 2:
            Find candidate mother vertex
            
            The last vertex from which DFS finishes
            can be a possible mother vertex.
        */
        for(int i = 0; i < V; i++)
        {
            // Start DFS only if vertex is unvisited
            if(!visited[i])
            {
                dfs(i, adj, visited);
                
                // Store current vertex as candidate
                candidate = i;
            }
        }
        
        /*
            Step 3:
            Verify whether candidate is actually
            a mother vertex or not
        */
        
        // Reset visited array
        fill(visited.begin(), visited.end(), false);
        
        // Perform DFS from candidate vertex
        dfs(candidate, adj, visited);
        
        // Check if all vertices are reachable
        for(int i = 0; i < V; i++)
        {
            // If any vertex is not reachable
            if(!visited[i])
            {
                return -1;
            }
        }
        
        /*
            Step 4:
            Multiple mother vertices may exist.
            
            We need to return the smallest one,
            so check all smaller vertices.
        */
        
        int answer = candidate;
        
        for(int i = 0; i < candidate; i++)
        {
            // Reset visited array for fresh DFS
            fill(visited.begin(), visited.end(), false);
            
            // Run DFS from current vertex
            dfs(i, adj, visited);
            
            bool canReachAll = true;
            
            // Check whether all vertices are reachable
            for(int j = 0; j < V; j++)
            {
                if(!visited[j])
                {
                    canReachAll = false;
                    break;
                }
            }
            
            // Smallest mother vertex found
            if(canReachAll)
            {
                answer = i;
                break;
            }
        }
        
        // Return final answer
        return answer;
    }
};