class Solution {
public:

    // Recursive function to find a valid path from (i,j) to destination
    bool solve(int i, int j,
               vector<vector<int>>& mat,
               vector<vector<int>>& ans,
               vector<vector<int>>& vis,
               int n) {

        // If cell is outside the matrix or blocked, return false
        if (i >= n || j >= n || mat[i][j] == 0)
            return false;

        // If destination cell is reached
        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1; // Mark destination in answer path
            return true;
        }

        // If this cell has already been explored and
        // determined to be a dead end, skip it
        if (vis[i][j])
            return false;

        // Include current cell in the path
        ans[i][j] = 1;

        // Maximum jump length allowed from current cell
        int jump = mat[i][j];

        // Try all possible jump lengths from 1 to jump
        // Smaller jumps are tried first as required
        for (int k = 1; k <= jump; k++) {

            // Move RIGHT first for the same jump length
            if (solve(i, j + k, mat, ans, vis, n))
                return true;

            // Then move DOWN
            if (solve(i + k, j, mat, ans, vis, n))
                return true;
        }

        // No valid path found through this cell,
        // remove it from the current path
        ans[i][j] = 0;

        // Mark this cell as a dead end so that
        // future recursive calls don't recompute it
        vis[i][j] = 1;

        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {

        // Size of matrix
        int n = mat.size();

        // If starting cell is blocked,
        // no path is possible
        if (mat[0][0] == 0)
            return {{-1}};

        // Stores the final path
        vector<vector<int>> ans(n, vector<int>(n, 0));

        // Memoization matrix:
        // vis[i][j] = 1 means cell (i,j) is a dead end
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // Start DFS + Backtracking from (0,0)
        if (solve(0, 0, mat, ans, vis, n))
            return ans;

        // No valid path exists
        return {{-1}};
    }
};