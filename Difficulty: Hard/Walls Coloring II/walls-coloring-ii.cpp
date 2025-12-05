class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;

        int k = costs[0].size();
        if (k == 0) return 0;

        // If only one color is available but there are multiple walls,
        // it is impossible to paint adjacent walls with different colors.
        if (k == 1 && n > 1) return -1;

        // dp[j] = minimum cost to paint up to the previous wall using color j
        vector<int> dp(costs[0]);

        // Process each wall from 1 to n-1
        for (int i = 1; i < n; i++) {
            // We need the two smallest values from dp:
            // min1 = smallest value
            // min2 = second smallest value
            // idx1 = index of the smallest value (color that achieved min1)
            int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;

            // Find min1, min2, and idx1 in O(k)
            for (int j = 0; j < k; j++) {
                if (dp[j] < min1) {
                    min2 = min1;
                    min1 = dp[j];
                    idx1 = j;
                } else if (dp[j] < min2) {
                    min2 = dp[j];
                }
            }

            // Create new dp array for the current wall
            vector<int> newDP(k);

            for (int j = 0; j < k; j++) {
                // If we choose the same color as the previous wall's minimum,
                // we must use the second smallest cost (min2).
                if (j == idx1)
                    newDP[j] = costs[i][j] + min2;
                else
                    // Otherwise, we are allowed to use the smallest previous cost (min1).
                    newDP[j] = costs[i][j] + min1;
            }

            // Update dp to newDP for next iteration
            dp = newDP;
        }

        // The final answer is the minimum value in dp array
        int ans = *min_element(dp.begin(), dp.end());

        return ans >= INT_MAX ? -1 : ans;
    }
};
