class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();          // number of rows
        int m = mat[0].size();       // number of columns
        
        int low = 0, high = m - 1;
        
        // Binary search on columns
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Find the row index with maximum element in mid column
            int maxRow = 0;
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            // Get left and right neighbors
            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1e9;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1e9;
            
            // Check if current element is a peak
            if (mat[maxRow][mid] >= left && mat[maxRow][mid] >= right) {
                return {maxRow, mid};  // Peak found
            }
            // Move towards the larger neighbor
            else if (left > mat[maxRow][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // As problem guarantees at least one peak, this line is theoretical
        return {-1, -1};
    }
};
