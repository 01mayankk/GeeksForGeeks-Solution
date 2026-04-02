class Solution {
public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> result;

        // 🔹 Part 1: Start from first row
        for (int col = 0; col < n; col++) {
            int i = 0;       // row index
            int j = col;     // column index

            // Traverse diagonal (↘ direction)
            while (i < n && j >= 0) {
                result.push_back(mat[i][j]);
                i++;    // move down
                j--;    // move left
            }
        }

        // 🔹 Part 2: Start from last column (excluding first row)
        for (int row = 1; row < n; row++) {
            int i = row;     // row index
            int j = n - 1;   // last column

            // Traverse diagonal (↘ direction)
            while (i < n && j >= 0) {
                result.push_back(mat[i][j]);
                i++;    // move down
                j--;    // move left
            }
        }

        return result;
    }
};