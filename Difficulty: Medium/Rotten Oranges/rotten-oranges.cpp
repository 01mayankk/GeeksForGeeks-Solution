class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q; // queue for BFS
        int fresh = 0; // count of fresh oranges
        
        // Step 1: Push all rotten oranges into queue
        // and count fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2) {
                    q.push({i, j}); // multi-source BFS
                }
                else if(mat[i][j] == 1) {
                    fresh++; // count fresh oranges
                }
            }
        }
        
        // If no fresh oranges, no time needed
        if(fresh == 0) return 0;
        
        int time = 0;
        
        // Directions: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        // Step 2: BFS traversal
        while(!q.empty()) {
            int size = q.size();
            bool rotted = false; // track if any orange rots in this minute
            
            for(int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();
                
                int x = it.first;
                int y = it.second;
                
                // Check all 4 directions
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    // Check valid cell and fresh orange
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2; // rot it
                        q.push({nx, ny}); // add to queue
                        fresh--; // decrease fresh count
                        rotted = true;
                    }
                }
            }
            
            // If at least one orange rotted, increase time
            if(rotted) time++;
        }
        
        // If fresh oranges still remain, return -1
        if(fresh > 0) return -1;
        
        return time;
    }
};