class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        // A very small value to represent an impossible state.
        const int NEG = -1e9;

        // dp[i][j] = Maximum dot product using:
        // - First i elements of array 'a'
        // - First j elements of array 'b'
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG));

        // If no elements of b are used, dot product is 0
        // because remaining positions can be filled with zeros.
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        // Build the DP table
        for (int i = 1; i <= n; i++) {
            // We cannot match more than i elements of b
            for (int j = 1; j <= min(i, m); j++) {

                // Option 1:
                // Skip current element of 'a'
                // (equivalent to inserting 0 in b at this position)
                dp[i][j] = dp[i - 1][j];

                // Option 2:
                // Match current elements of a and b
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - 1] + a[i - 1] * b[j - 1]);
            }
        }

        return dp[n][m];
    }
};