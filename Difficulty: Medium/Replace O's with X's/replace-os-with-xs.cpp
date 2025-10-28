class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        int n = grid.size();          // total number of rows
        int m = grid[0].size();       // total number of columns

        // visited matrix to mark which cells are already processed
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // queue for BFS traversal (stores positions as pairs)
        queue<pair<int, int>> q;

        // -------------------------------
        // Step 1: Add all 'O's on the borders into the queue
        // -------------------------------
        // Because border 'O's and their connected regions
        // cannot be surrounded fully, they will remain 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if it's a border cell and has 'O'
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 'O') {
                    q.push({i, j});         // push position into queue
                    visited[i][j] = true;   // mark as visited (safe 'O')
                }
            }
        }

        // -------------------------------
        // Step 2: BFS traversal to mark all 'O's
        // connected to border 'O's as safe (not surrounded)
        // -------------------------------

        // 4 possible movement directions — up, down, left, right
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            // take one cell from the queue
            auto [r, c] = q.front();
            q.pop();

            // explore all 4 adjacent cells
            for (int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                // check if inside grid bounds
                // and the cell is 'O' and not visited yet
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                    !visited[nr][nc] && grid[nr][nc] == 'O') {
                    
                    visited[nr][nc] = true;  // mark as safe
                    q.push({nr, nc});        // add to queue for further BFS
                }
            }
        }

        // -------------------------------
        // Step 3: Convert all unvisited 'O's to 'X'
        // -------------------------------
        // The remaining 'O's are NOT connected to border
        // Hence, they are completely surrounded by 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If it's 'O' and not visited (not connected to border)
                if (grid[i][j] == 'O' && !visited[i][j]) {
                    grid[i][j] = 'X';   // replace with 'X'
                }
            }
        }
    }
};
