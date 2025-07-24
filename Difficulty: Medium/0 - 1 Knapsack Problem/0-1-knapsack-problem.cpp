class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // dp[w] will store the maximum value that can be achieved with capacity w
        vector<int> dp(W + 1, 0);  // Initially, for all weights, max value is 0

        // Loop over all items
        int n = val.size();
        for (int i = 0; i < n; i++) {

            // Traverse weights in reverse to make sure each item is only considered once (0/1 condition)
            for (int w = W; w >= wt[i]; w--) {

                // Two options:
                // 1. Don't take the current item: dp[w] (value remains the same)
                // 2. Take the current item:
                //    - Add its value: val[i]
                //    - Reduce weight by its weight: w - wt[i]
                //    - Add best value from remaining capacity: dp[w - wt[i]]

                // Take the better of the two options
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }

        // dp[W] now contains the maximum value we can get with total capacity W
        return dp[W];
    }
};