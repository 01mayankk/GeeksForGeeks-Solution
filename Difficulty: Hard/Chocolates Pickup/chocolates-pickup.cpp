class Solution {
public:
    int n, m;

    // dp[i][j1][j2] represents:
    // Maximum chocolates that can be collected starting from row i
    // when robot1 is at column j1 and robot2 is at column j2
    int dp[71][71][71];

    int solve(int i, int j1, int j2, vector<vector<int>>& grid) {

        // 🔴 Boundary check:
        // If any robot goes out of grid, this path is invalid
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9; // very small value (acts like -infinity)

        // 🟢 Base Case:
        // If we are at the last row
        if (i == n - 1) {

            // If both robots are on same cell → count once
            if (j1 == j2)
                return grid[i][j1];

            // Otherwise count both cells
            else
                return grid[i][j1] + grid[i][j2];
        }

        // ⚡ Memoization:
        // If already computed, return stored result
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e9; // to store maximum chocolates

        // 🔁 Try all 9 possible moves:
        // Robot1: j1-1, j1, j1+1
        // Robot2: j2-1, j2, j2+1
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {

                int value = 0;

                // 🍫 Collect chocolates at current position

                // If both robots land on same cell → count once
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                // ➡️ Move both robots to next row (i+1)
                value += solve(i + 1, j1 + dj1, j2 + dj2, grid);

                // Update maximum
                maxi = max(maxi, value);
            }
        }

        // 💾 Store result in DP and return
        return dp[i][j1][j2] = maxi;
    }

    int maxChocolate(vector<vector<int>>& grid) {

        // 📏 Grid dimensions
        n = grid.size();
        m = grid[0].size();

        // 🔄 Initialize DP with -1 (means not computed yet)
        memset(dp, -1, sizeof(dp));

        // 🚀 Start from:
        // Robot1 → (0, 0)
        // Robot2 → (0, m-1)
        return solve(0, 0, m - 1, grid);
    }
};