class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Create 2D prefix sum array
        vector<vector<int>> pref(n, vector<int>(m, 0));

        // Build prefix sum matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i][j] = mat[i][j];

                // Add sum from top
                if (i > 0)
                    pref[i][j] += pref[i - 1][j];

                // Add sum from left
                if (j > 0)
                    pref[i][j] += pref[i][j - 1];

                // Remove double-counted top-left area
                if (i > 0 && j > 0)
                    pref[i][j] -= pref[i - 1][j - 1];
            }
        }

        // Step 2: Answer each query in O(1)
        vector<int> result;

        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];

            int sum = pref[r2][c2];

            // Exclude upper area
            if (r1 > 0)
                sum -= pref[r1 - 1][c2];

            // Exclude left area
            if (c1 > 0)
                sum -= pref[r2][c1 - 1];

            // Add back overlapping area
            if (r1 > 0 && c1 > 0)
                sum += pref[r1 - 1][c1 - 1];

            result.push_back(sum);
        }

        return result;
    }
};
