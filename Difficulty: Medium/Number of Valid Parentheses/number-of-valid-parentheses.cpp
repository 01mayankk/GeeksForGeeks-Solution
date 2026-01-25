class Solution {
  public:
    int findWays(int n) {

        // If length is odd, valid parentheses are impossible
        if (n % 2 == 1)
            return 0;

        // Number of pairs of parentheses
        int pairs = n / 2;

        // dp[i] will store the number of valid parentheses
        // expressions with i pairs of brackets
        vector<long long> dp(pairs + 1, 0);

        // Base case:
        // One valid expression with 0 pairs (empty string)
        dp[0] = 1;

        // Calculate Catalan numbers using DP
        for (int i = 1; i <= pairs; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[pairs];
    }
};
