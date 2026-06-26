class Solution {
public:
    int countWays(int n, int m) {
        
        const int MOD = 1e9 + 7;

        // dp[i] = Number of ways to tile a floor of size i × m.
        vector<long long> dp(n + 1, 0);

        // Base case:
        // An empty floor has one valid tiling.
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            if (i < m) {
                // Vertical placement is not possible.
                // Only horizontal tiles can be placed.
                dp[i] = 1;
            }
            else if (i == m) {
                // Two possibilities:
                // 1. Place all tiles horizontally.
                // 2. Place all tiles vertically.
                dp[i] = 2;
            }
            else {
                // Option 1:
                // Place one horizontal tile in the current row.
                // Remaining floor = (i-1) × m.
                long long horizontal = dp[i - 1];

                // Option 2:
                // Place m vertical tiles together, occupying
                // the next m rows.
                // Remaining floor = (i-m) × m.
                long long vertical = dp[i - m];

                dp[i] = (horizontal + vertical) % MOD;
            }
        }

        return dp[n];
    }
};