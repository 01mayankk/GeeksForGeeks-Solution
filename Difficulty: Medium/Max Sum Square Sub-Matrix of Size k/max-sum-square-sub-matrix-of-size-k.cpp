class Solution {
public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        // pref[i][j] stores the sum of elements in the sub-matrix 
        // from top-left (0, 0) to (i - 1, j - 1).
        // Using size (n + 1) x (n + 1) handles 1-based indexing to easily manage boundary conditions.
        vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
        
        // Step 1: Build the 2D Prefix Sum Array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // Current cell value + sum above + sum to the left - overlap (top-left double counted)
                pref[i][j] = mat[i - 1][j - 1] 
                           + pref[i - 1][j] 
                           + pref[i][j - 1] 
                           - pref[i - 1][j - 1];
            }
        }
        
        int maxSum = INT_MIN;
        
        // Step 2: Iterate over all possible bottom-right corners (i, j) of k x k sub-matrices
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                // Calculate sum of k x k sub-matrix ending at (i, j) using the Inclusion-Exclusion Principle:
                // Total area up to (i, j) 
                // - area above the sub-matrix 
                // - area to the left of the sub-matrix 
                // + area subtracted twice (top-left overlap)
                int currentSum = pref[i][j] 
                               - pref[i - k][j] 
                               - pref[i][j - k] 
                               + pref[i - k][j - k];
                
                // Track the maximum sum found so far
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};