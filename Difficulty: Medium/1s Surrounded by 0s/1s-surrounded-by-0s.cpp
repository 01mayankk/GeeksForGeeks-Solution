class Solution {
public:

    // DFS function to visit all connected 1's
    void dfs(int row, int col,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             int n, int m) {

        // Mark current cell as visited
        vis[row][col] = 1;

        // 4 possible directions
        // Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Traverse all 4 directions
        for (int i = 0; i < 4; i++) {

            int nr = row + dr[i]; // new row
            int nc = col + dc[i]; // new column

            // Check:
            // 1. Inside grid
            // 2. Cell contains 1
            // 3. Not visited yet
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                grid[nr][nc] == 1 &&
                !vis[nr][nc]) {

                // Visit connected cell
                dfs(nr, nc, grid, vis, n, m);
            }
        }
    }

    int cntOnes(vector<vector<int>>& grid) {

        // Number of rows
        int n = grid.size();

        // Number of columns
        int m = grid[0].size();

        // Visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        /*
            IDEA:
            -----
            Any 1 connected to boundary can move out.

            So:
            1. Start DFS from all boundary 1's
            2. Mark all reachable 1's
            3. Remaining unvisited 1's are trapped
        */

        // ==========================
        // Traverse first & last column
        // ==========================
        for (int i = 0; i < n; i++) {

            // First column
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, grid, vis, n, m);
            }

            // Last column
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfs(i, m - 1, grid, vis, n, m);
            }
        }

        // ==========================
        // Traverse first & last row
        // ==========================
        for (int j = 0; j < m; j++) {

            // First row
            if (grid[0][j] == 1 && !vis[0][j]) {
                dfs(0, j, grid, vis, n, m);
            }

            // Last row
            if (grid[n - 1][j] == 1 && !vis[n - 1][j]) {
                dfs(n - 1, j, grid, vis, n, m);
            }
        }

        // Variable to store trapped 1's count
        int count = 0;

        // Traverse whole grid
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // If cell contains 1
                // and not visited,
                // then it is trapped
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        // Return answer
        return count;
    }
};