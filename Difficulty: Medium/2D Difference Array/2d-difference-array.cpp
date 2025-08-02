class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // Get the dimensions of the input matrix
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Create a 2D difference matrix of size (n+1) x (m+1)
        // We use an extra row and column to avoid boundary checks during updates
        vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));

        // Step 2: Apply each operation in the operations list to the diff matrix
        // Each operation is in the format: [value, r1, c1, r2, c2]
        for (const auto& op : opr) {
            int v = op[0];               // Value to add
            int r1 = op[1], c1 = op[2];  // Top-left corner of the rectangle
            int r2 = op[3], c2 = op[4];  // Bottom-right corner of the rectangle

            // Apply the 2D difference array technique:
            // Add value v at (r1, c1)
            diff[r1][c1] += v;

            // Subtract value v just below the bottom edge of the rectangle
            if (r2 + 1 < n) diff[r2 + 1][c1] -= v;

            // Subtract value v just right of the right edge of the rectangle
            if (c2 + 1 < m) diff[r1][c2 + 1] -= v;

            // Add value v at the cell diagonally opposite to compensate over-subtraction
            if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += v;
        }

        // Step 3: Convert the diff matrix into a prefix sum matrix horizontally (left to right)
        // This accumulates values across each row
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        // Step 4: Now compute the vertical prefix sum (top to bottom)
        // This accumulates values down each column
        for (int j = 0; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                diff[i][j] += diff[i - 1][j];
            }
        }

        // Step 5: Add the final diff values to the original matrix to get the updated matrix
        // This step gives the result after applying all the operations
        vector<vector<int>> result(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[i][j] = mat[i][j] + diff[i][j];  // Apply the difference
            }
        }

        return result;
    }
};
