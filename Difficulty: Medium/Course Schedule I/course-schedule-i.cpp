class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        // -------------------------------
        // Step 1: Create adjacency list
        // -------------------------------
        // adj[u] will store all courses that depend on course u
        vector<vector<int>> adj(n);
        
        // -------------------------------
        // Step 2: Create indegree array
        // -------------------------------
        // indegree[i] = number of prerequisites required for course i
        vector<int> indegree(n, 0);
        
        // -------------------------------
        // Step 3: Build the graph
        // -------------------------------
        // For each pair [course, prereq]:
        // You must take 'prereq' before 'course'
        // So we add edge: prereq → course
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            
            adj[prereq].push_back(course); // directed edge
            
            // Increase indegree of the course
            indegree[course]++;
        }
        
        // -------------------------------
        // Step 4: Initialize queue
        // -------------------------------
        // Push all courses with NO prerequisites (indegree = 0)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // -------------------------------
        // Step 5: Perform BFS (Kahn's Algorithm)
        // -------------------------------
        int count = 0; // counts how many courses we can complete
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // We can "take" this course
            count++;
            
            // Visit all courses dependent on current course
            for (int neighbor : adj[node]) {
                indegree[neighbor]--; // remove dependency
                
                // If no more prerequisites left, add to queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // -------------------------------
        // Step 6: Check for cycle
        // -------------------------------
        // If count == n → all courses completed → NO cycle
        // If count < n → some courses couldn't be completed → CYCLE exists
        return count == n;
    }
};