class Solution {
public:
    // Function to construct the optimal parenthesis string from dp-split table
    string construct(int i, int j, vector<vector<int>> &split) {
        // If only one matrix is present, return its name: A, B, C...
        if (i == j) {
            return string(1, 'A' + i - 1);
        }

        // Find the position where the final multiplication happened
        int k = split[i][j];

        // Recursively build left and right part
        string left = construct(i, k, split);
        string right = construct(k + 1, j, split);

        return "(" + left + right + ")";
    }
    
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        int m = n - 1;   // Number of matrices = n-1

        // dp[i][j] = minimum cost to multiply matrices from i to j
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        // split[i][j] = index k where we split for optimal cost
        vector<vector<int>> split(m + 1, vector<int>(m + 1, -1));

        // L = chain length (from 2 matrices to m matrices)
        for (int L = 2; L <= m; L++) {
            for (int i = 1; i <= m - L + 1; i++) {
                int j = i + L - 1;
                dp[i][j] = INT_MAX;

                // Try all possible splits
                for (int k = i; k < j; k++) {

                    // Cost = cost of left part + cost of right part + cost of final multiplication
                    int cost = dp[i][k] + dp[k + 1][j] 
                             + arr[i - 1] * arr[k] * arr[j];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;     // store the best split
                    }
                }
            }
        }

        // Build and return the bracket string using splits
        return construct(1, m, split);
    }
};
