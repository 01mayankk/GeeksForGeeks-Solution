class Solution {
public:
    int maxPath = -1;

    void solve(vector<vector<int>>& mat, int r, int c, int xd, int yd, int currentLength) {
        // If the destination is reached, update the maximum path length found so far
        if (r == xd && c == yd) {
            maxPath = max(maxPath, currentLength);
            return;
        }

        // Store the original value to backtrack later
        int originalValue = mat[r][c];
        // Mark the current cell as visited by setting it to 0
        mat[r][c] = 0;

        // Define movements for Up, Down, Left, and Right directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Explore all 4 adjacent directions
        for (int i = 0; i < 4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            // Check if the adjacent cell is within bounds and is traversable (value is 1)
            if (newR >= 0 && newR < mat.size() && newC >= 0 && newC < mat[0].size() && mat[newR][newC] == 1) {
                solve(mat, newR, newC, xd, yd, currentLength + 1);
            }
        }

        // Backtrack: Restore the original value of the cell for other path combinations
        mat[r][c] = originalValue;
    }

    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // If the source or destination cell is blocked, no path is possible
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0) {
            return -1;
        }

        maxPath = -1;
        // Start the recursive backtracking from the source cell with an initial path length of 0
        solve(mat, xs, ys, xd, yd, 0);
        
        return maxPath;
    }
};