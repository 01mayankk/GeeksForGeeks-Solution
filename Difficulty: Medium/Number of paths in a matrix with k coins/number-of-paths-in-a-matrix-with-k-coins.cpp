class Solution {
  public:
    int n, m;
    // dp[i][j][k] → stores the number of paths from (i, j) to (n-1, m-1)
    // such that the total coins collected equals k
    int dp[101][101][101];

    // Recursive helper function to count paths
    int solve(vector<vector<int>>& mat, int i, int j, int k) {
        // 🧭 Base Case 1: If we go out of matrix boundaries → no valid path
        if (i >= n || j >= m) return 0;

        // 🧭 Base Case 2: If we reach the bottom-right corner
        // Check if the coins collected so far equal the target k
        if (i == n - 1 && j == m - 1) {
            return (k == mat[i][j]) ? 1 : 0;
        }

        // 🧭 Base Case 3: If the remaining sum (k) becomes negative → no valid path
        if (k < 0) return 0;

        // 🔁 If already computed, return the stored value to avoid recomputation
        if (dp[i][j][k] != -1) return dp[i][j][k];

        // 🎯 Subtract current cell's coins from remaining sum
        int remaining = k - mat[i][j];

        // 🚶 Explore two possible moves:
        // 1. Move Right → (i, j+1)
        // 2. Move Down → (i+1, j)
        int right = solve(mat, i, j + 1, remaining);
        int down  = solve(mat, i + 1, j, remaining);

        // 💾 Store and return the total number of valid paths from this state
        return dp[i][j][k] = right + down;
    }

    // Main function to initialize DP and start recursion
    int numberOfPath(vector<vector<int>>& mat, int k) {
        n = mat.size();     // number of rows
        m = mat[0].size();  // number of columns

        // Initialize DP array with -1 (uncomputed states)
        memset(dp, -1, sizeof(dp));

        // Start recursion from top-left corner (0,0) with total k coins to collect
        return solve(mat, 0, 0, k);
    }
};
