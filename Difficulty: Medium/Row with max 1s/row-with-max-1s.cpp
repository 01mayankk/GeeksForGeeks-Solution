class Solution {
  public:
    // Function to find the index of the row with the maximum number of 1s
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();         // Total number of rows
        int m = arr[0].size();      // Total number of columns

        int row = -1;               // Initialize result to -1 (in case no 1s are found)
        int j = m - 1;              // Start from the top-right corner (last column of first row)

        // Traverse each row
        for (int i = 0; i < n; i++) {
            // Move left while the current element is 1
            while (j >= 0 && arr[i][j] == 1) {
                j--;                // Move left to count more 1s in the current row
                row = i;            // Update the row index to the current row
            }
            // After moving left, if we encounter 0, we move to the next row
            // Since rows are sorted, no need to check remaining elements in this row
        }

        // Return the row index with the maximum number of 1s
        // If no 1s were found in any row, returns -1
        return row;
    }
};
