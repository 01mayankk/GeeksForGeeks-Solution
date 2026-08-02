class Solution {
public:
    int count(int n, int m) {
        // Create a DP table where dp[i][j] represents the number of valid sequences 
        // of length i that end with the number j.
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        
        // Base case: For a sequence of length 1, there is exactly 1 valid sequence 
        // ending in each number from 1 to m.
        for (int j = 1; j <= m; ++j) {
            dp[1][j] = 1;
        }
        
        // Fill the DP table for lengths 2 to n
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 1; k <= m; ++k) {
                    // Check the condition: one element must divide the other
                    if (j % k == 0 || k % j == 0) {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        
        // The total number of valid sequences of length n is the sum of sequences
        // ending in any number from 1 to m.
        int total_sequences = 0;
        for (int j = 1; j <= m; ++j) {
            total_sequences += dp[n][j];
        }
        
        return total_sequences;
    }
};