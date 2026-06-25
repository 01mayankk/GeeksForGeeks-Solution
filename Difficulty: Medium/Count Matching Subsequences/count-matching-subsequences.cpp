class Solution {
public:
    int countWays(string &s1, string &s2) {

        const int MOD = 1e9 + 7;

        int n = s1.size();
        int m = s2.size();

        // dp[i][j] = Number of ways to form first 'j' characters
        // of s2 using first 'i' characters of s1.
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // Empty string can always be formed in exactly one way
        // by choosing nothing.
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Ignore current character of s1
                dp[i][j] = dp[i - 1][j];

                // If current characters match,
                // include this character as well.
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }

        return dp[n][m];
    }
};