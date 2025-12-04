class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {

        int n = keys.size();

        // dp[i][j] = minimum cost of Optimal BST using keys from index i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Prefix sum to quickly compute sum of frequencies in any range
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + freq[i];

        // Helper lambda: returns sum(freq[i..j])
        auto sumFreq = [&](int i, int j) {
            return prefix[j + 1] - prefix[i];
        };

        // Base case: cost of single key is freq[i] * 1
        // Level = 1 → cost = freq[i]
        for (int i = 0; i < n; i++)
            dp[i][i] = freq[i];

        // Consider chains (subarrays) of increasing length
        for (int len = 2; len <= n; len++) {

            // i = starting index
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;  // ending index
                dp[i][j] = INT_MAX;

                // Total frequency of interval [i..j]
                // This is added because choosing any root increases level of all nodes in subtree
                int totalFreq = sumFreq(i, j);

                // Try making each key from i to j the root
                for (int r = i; r <= j; r++) {

                    // Left subtree cost (if exists)
                    int left = (r > i) ? dp[i][r - 1] : 0;

                    // Right subtree cost (if exists)
                    int right = (r < j) ? dp[r + 1][j] : 0;

                    // Total cost = left + right + frequencies shifted by 1 level
                    dp[i][j] = min(dp[i][j], left + right + totalFreq);
                }
            }
        }

        // Minimum cost of OBST using all keys
        return dp[0][n - 1];
    }
};
