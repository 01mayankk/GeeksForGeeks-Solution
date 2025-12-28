class Solution {
  public:
    // Function to count elements <= mid in the matrix
    int countLessEqual(vector<vector<int>> &mat, int mid) {
        int n = mat.size();
        int i = 0, j = n - 1;
        int count = 0;

        // Start from top-right corner
        while (i < n && j >= 0) {
            if (mat[i][j] <= mid) {
                // All elements in this row till column j are <= mid
                count += (j + 1);
                i++;  // move down
            } else {
                j--;  // move left
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        
        int low = mat[0][0];            // smallest element
        int high = mat[n - 1][n - 1];   // largest element
        int ans = -1;

        // Binary search on value range
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int cnt = countLessEqual(mat, mid);

            if (cnt >= k) {
                ans = mid;       // possible answer
                high = mid - 1;  // search smaller
            } else {
                low = mid + 1;   // search larger
            }
        }
        return ans;
    }
};
