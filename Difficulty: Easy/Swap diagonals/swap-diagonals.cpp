class Solution {
public:
    void swapDiagonal(vector<vector<int>> &mat) {
        int n = mat.size();  // Since matrix is square

        // Loop through each row
        for (int i = 0; i < n; i++) {
            // Swap major diagonal element with minor diagonal element
            // Major diagonal index: (i, i)
            // Minor diagonal index: (i, n - i - 1)
            swap(mat[i][i], mat[i][n - i - 1]);
        }
    }
};
