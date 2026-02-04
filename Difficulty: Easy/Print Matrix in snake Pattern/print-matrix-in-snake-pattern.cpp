class Solution {
  public:
    vector<int> snakePattern(vector<vector<int>> matrix) {
        // This vector will store the final snake pattern traversal
        vector<int> result;

        // Number of rows in the matrix
        int row = matrix.size();

        // Number of columns in the matrix
        int col = matrix[0].size();

        // Traverse each row of the matrix
        for (int i = 0; i < row; i++) {

            // Traverse columns in each row
            for (int j = 0; j < col; j++) {

                // If the row index is odd, traverse from right to left
                if (i % 2 != 0) {
                    // Access element from the end of the row
                    int val = matrix[i][col - j - 1];
                    result.push_back(val);
                }
                // If the row index is even, traverse from left to right
                else {
                    result.push_back(matrix[i][j]);
                }
            }
        }

        // Return the snake pattern traversal
        return result;
    }
};
