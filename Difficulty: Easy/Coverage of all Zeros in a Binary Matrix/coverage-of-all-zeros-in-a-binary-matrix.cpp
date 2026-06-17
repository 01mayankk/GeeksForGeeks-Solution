class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {

        // Number of rows and columns
        int n = mat.size();
        int m = mat[0].size();

        // Stores final answer
        int totalCoverage = 0;

        // Traverse every cell of the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Coverage is calculated only for cells containing 0
                if (mat[i][j] == 0) {

                    // Coverage of current 0 cell
                    int coverage = 0;

                    // ---------------- LEFT ----------------
                    // Check if there is at least one 1
                    // between current cell and left boundary
                    for (int col = j - 1; col >= 0; col--) {
                        if (mat[i][col] == 1) {
                            coverage++;
                            break;  // Count only once for this direction
                        }
                    }

                    // ---------------- RIGHT ----------------
                    // Check if there is at least one 1
                    // between current cell and right boundary
                    for (int col = j + 1; col < m; col++) {
                        if (mat[i][col] == 1) {
                            coverage++;
                            break;
                        }
                    }

                    // ---------------- UP ----------------
                    // Check if there is at least one 1
                    // between current cell and top boundary
                    for (int row = i - 1; row >= 0; row--) {
                        if (mat[row][j] == 1) {
                            coverage++;
                            break;
                        }
                    }

                    // ---------------- DOWN ----------------
                    // Check if there is at least one 1
                    // between current cell and bottom boundary
                    for (int row = i + 1; row < n; row++) {
                        if (mat[row][j] == 1) {
                            coverage++;
                            break;
                        }
                    }

                    // Add coverage of current 0 cell
                    totalCoverage += coverage;
                }
            }
        }

        // Return total coverage of all 0 cells
        return totalCoverage;
    }
};