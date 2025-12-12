class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n = mat.size();     // Number of rows (and columns since it's a square matrix)

        // Create a new matrix to store the transpose
        vector<vector<int>> result(n, vector<int>(n));

        // Traverse the matrix and swap rows with columns
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                result[j][i] = mat[i][j]; 
                // Element at (i, j) becomes (j, i) in the transpose
            }
        }

        return result; 
    }
};
