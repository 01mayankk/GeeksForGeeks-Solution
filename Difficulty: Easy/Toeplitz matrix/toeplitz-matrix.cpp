class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Start from 1 because we compare with previous row & column
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                
                // Check if current element matches top-left diagonal element
                if (mat[i][j] != mat[i - 1][j - 1]) {
                    return false; // Not Toeplitz
                }
            }
        }

        return true; // All diagonals matched
    }
};