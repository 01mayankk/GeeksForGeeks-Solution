class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Precompute a 2D prefix sum array to quickly calculate the number of 1s in any subgrid
        // prefix[i+1][j+1] represents the sum of elements from mat[0][0] to mat[i][j]
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                prefix[i + 1][j + 1] = mat[i][j] 
                                     + prefix[i][j + 1] 
                                     + prefix[i + 1][j] 
                                     - prefix[i][j];
            }
        }
        
        // Lambda function to get the sum of 1s in a subgrid from (r1, c1) to (r2, c2) inclusive
        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return prefix[r2 + 1][c2 + 1] 
                 - prefix[r1][c2 + 1] 
                 - prefix[r2 + 1][c1] 
                 + prefix[r1][c1];
        };
        
        vector<int> result;
        
        // Process each query
        for (const auto& q : queries) {
            int r = q[0];
            int c = q[1];
            
            // The maximum possible "radius" of the square extending outward from the center (r, c)
            // It is bounded by the distance to the closest boundary of the matrix
            int max_radius = min({r, c, n - 1 - r, m - 1 - c});
            
            int low = 0;
            int high = max_radius;
            
            // Initialize to -1 to handle cases where even a 1x1 square is invalid (e.g. k=0 and mat[r][c]=1)
            int best_radius = -1;
            
            // Binary search for the maximum valid radius
            while (low <= high) {
                int mid = low + (high - low) / 2;
                
                // Calculate the number of 1s in the square with current radius 'mid'
                int ones_count = getSum(r - mid, c - mid, r + mid, c + mid);
                
                if (ones_count <= k) {
                    // If the count is within the limit, record it and try a larger radius
                    best_radius = mid;
                    low = mid + 1;
                } else {
                    // Otherwise, the square is too large, try a smaller radius
                    high = mid - 1;
                }
            }
            
            // If best_radius remains -1, no valid square exists, so we return -1
            if (best_radius == -1) {
                result.push_back(-1);
            } else {
                // The side length of an odd square with radius 'r' is 2*r + 1
                result.push_back(2 * best_radius + 1);
            }
        }
        
        return result;
    }
};