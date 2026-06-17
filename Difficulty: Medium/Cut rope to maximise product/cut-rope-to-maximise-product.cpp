class Solution {
public:
    int maxProduct(int n) {

        vector<int> dp(n + 1, 0);

        // Build answers from smaller lengths to larger lengths
        for(int len = 2; len <= n; len++)
        {
            int best = 0;

            // Try every possible first cut
            for(int cut = 1; cut < len; cut++)
            {
                int remaining = len - cut;

                // Either keep remaining piece as it is
                // or cut it further
                best = max(best,
                           cut * max(remaining, dp[remaining]));
            }

            dp[len] = best;
        }

        return dp[n];
    }
};