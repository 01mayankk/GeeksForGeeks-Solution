class Solution {
public:
    int minimumCost(vector<int> &cost, int w) {
        
        // Number of available packet types
        int n = cost.size();

        // A large value to represent an impossible state
        const int INF = 1e9;

        // dp[i] = minimum cost required to buy exactly i kg oranges
        vector<int> dp(w + 1, INF);

        // Base case:
        // Cost to buy 0 kg oranges is 0
        dp[0] = 0;

        // Traverse all packet types
        for (int i = 0; i < n; i++) {

            // If packet is unavailable, skip it
            if (cost[i] == -1)
                continue;

            // Current packet weight (index i represents weight i+1)
            int weight = i + 1;

            // Cost of current packet
            int packetCost = cost[i];

            // Unbounded Knapsack:
            // Since we can take the same packet multiple times,
            // iterate from weight to w in increasing order
            for (int j = weight; j <= w; j++) {

                // If (j - weight) kg can be formed
                if (dp[j - weight] != INF) {

                    // Either:
                    // 1. Keep existing minimum cost for j kg
                    // 2. Use current packet once more
                    dp[j] = min(dp[j],
                                dp[j - weight] + packetCost);
                }
            }
        }

        // If dp[w] is still INF,
        // it means exact weight w cannot be formed
        if (dp[w] == INF)
            return -1;

        return dp[w];
    }
};