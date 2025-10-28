class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Get the number of rows (n) and columns (m)
        int n = grid.size();
        int m = grid[0].size();
        
        // 'dist' will store the minimum distance from each cell to the nearest 1
        // Initialize all distances as -1 (meaning unvisited)
        vector<vector<int>> dist(n, vector<int>(m, -1));
        
        // Queue to perform BFS
        queue<pair<int, int>> q;
        
        // Step 1: Push all cells that already contain '1' into the queue
        // because their distance to nearest 1 is obviously 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;     // Distance of '1' cell to itself is 0
                    q.push({i, j});     // Push this cell as a BFS starting point
                }
            }
        }
        
        // Step 2: Define the 4 possible directions for movement
        // Down, Up, Right, Left
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Step 3: Multi-Source BFS
        while (!q.empty()) {
            // Take the current cell from queue
            auto [x, y] = q.front();
            q.pop();
            
            // Explore all 4 directions
            for (auto& d : dir) {
                int nx = x + d[0];   // new x-coordinate
                int ny = y + d[1];   // new y-coordinate
                
                // Check boundary conditions and if not already visited
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && dist[nx][ny] == -1) {
                    // Update the distance of this neighboring cell
                    dist[nx][ny] = dist[x][y] + 1;
                    
                    // Push the newly discovered cell into the queue
                    q.push({nx, ny});
                }
            }
        }
        
        // Step 4: Return the matrix containing minimum distances
        return dist;
    }
};
