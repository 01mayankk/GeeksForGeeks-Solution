class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();

        // dp[i][j] will hold the minimum cost of multiplying matrices from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len represents the length of the subchain being considered (number of matrices)
        for (int len = 2; len < n; len++) {
            // i is the starting index of the subchain
            for (int i = 0; i < n - len; i++) {
                int j = i + len; // j is the ending index of the subchain
                dp[i][j] = INT_MAX;

                // Try every possible position to split the chain between i and j
                for (int k = i + 1; k < j; k++) {
                    // Cost of multiplying the left subchain (i to k)
                    // + cost of multiplying the right subchain (k to j)
                    // + cost of multiplying the resulting two matrices:
                    // arr[i] x arr[k] x arr[j]
                    int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];

                    // Store the minimum cost for multiplying from matrix i to matrix j
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        // Return the minimum cost to multiply the entire chain (from 0 to n-1)
        return dp[0][n - 1];
    }
};
