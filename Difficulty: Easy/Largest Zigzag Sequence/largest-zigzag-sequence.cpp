class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Base case: if matrix has only 1 element
        if (n == 1) return mat[0][0];

        // Vector to store the maximum sequence sums up to the previous row
        vector<int> prevRow = mat[0];

        // Iterate through each row starting from the second one
        for (int i = 1; i < n; ++i) {
            int max1 = 0, max2 = 0;
            int max1_idx = -1;

            // Find the maximum (max1) and second maximum (max2) in the previous row
            for (int j = 0; j < n; ++j) {
                if (prevRow[j] > max1) {
                    max2 = max1;
                    max1 = prevRow[j];
                    max1_idx = j;
                } else if (prevRow[j] > max2) {
                    max2 = prevRow[j];
                }
            }

            // Vector to store the maximum sequence sums for the current row
            vector<int> currRow(n);
            
            // Calculate max sum for each cell in the current row
            for (int j = 0; j < n; ++j) {
                // If the current column is different from the max1 column, add max1
                if (j != max1_idx) {
                    currRow[j] = mat[i][j] + max1;
                } 
                // Otherwise, add max2 to avoid picking consecutive elements from the same column
                else {
                    currRow[j] = mat[i][j] + max2;
                }
            }
            
            // Update prevRow for the next iteration
            prevRow = currRow;
        }

        // The answer is the maximum value accumulated in the final row
        int maxSum = 0;
        for (int j = 0; j < n; ++j) {
            maxSum = max(maxSum, prevRow[j]);
        }

        return maxSum;
    }
};