class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        
        // dp[i][j] = number of ways to get sum j using i dice
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
        
        // Base case: 0 dice to get sum 0 -> 1 way
        dp[0][0] = 1;
        
        // Iterate over number of dice
        for(int dice = 1; dice <= n; dice++)
        {
            // Iterate over possible sums
            for(int sum = 1; sum <= x; sum++)
            {
                // Try every face value
                for(int face = 1; face <= m; face++)
                {
                    if(sum - face >= 0)
                    {
                        dp[dice][sum] += dp[dice - 1][sum - face];
                    }
                }
            }
        }
        
        // Result: ways to get sum x using n dice
        return dp[n][x];
    }
};