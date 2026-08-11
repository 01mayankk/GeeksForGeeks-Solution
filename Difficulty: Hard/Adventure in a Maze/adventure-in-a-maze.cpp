class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        int MOD = 1e9 + 7;
        
        // DP tables to store the number of valid paths and maximum adventure
        vector<vector<long long>> paths(n, vector<long long>(n, 0));
        vector<vector<long long>> maxAdv(n, vector<long long>(n, 0));
        
        // Base case for the starting cell
        paths[0][0] = 1;
        maxAdv[0][0] = grid[0][0];
        
        // Traverse the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // If current cell is reachable
                if (paths[i][j] > 0) {
                    
                    // Check if moving Right is allowed (1 or 3) and within bounds
                    if (j + 1 < n && (grid[i][j] == 1 || grid[i][j] == 3)) {
                        paths[i][j + 1] = (paths[i][j + 1] + paths[i][j]) % MOD;
                        maxAdv[i][j + 1] = max(maxAdv[i][j + 1], maxAdv[i][j] + grid[i][j + 1]);
                    }
                    
                    // Check if moving Down is allowed (2 or 3) and within bounds
                    if (i + 1 < n && (grid[i][j] == 2 || grid[i][j] == 3)) {
                        paths[i + 1][j] = (paths[i + 1][j] + paths[i][j]) % MOD;
                        maxAdv[i + 1][j] = max(maxAdv[i + 1][j], maxAdv[i][j] + grid[i + 1][j]);
                    }
                }
            }
        }
        
        // If the exit cell is unreachable, return {0, 0}
        if (paths[n - 1][n - 1] == 0) {
            return {0, 0};
        }
        
        // Return total paths and maximum adventure
        return {(int)paths[n - 1][n - 1], (int)maxAdv[n - 1][n - 1]};
    }
};