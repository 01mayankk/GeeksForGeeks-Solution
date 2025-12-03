class Solution {
public:
    // Recursive function: mask = visited cities, pos = current city
    int solve(vector<vector<int>>& cost, int mask, int pos, vector<vector<int>>& dp) {
        int n = cost.size();

        // If all cities are visited, return cost to return to city 0
        if (mask == (1 << n) - 1)
            return cost[pos][0];

        // Return memoized result
        if (dp[mask][pos] != -1)
            return dp[mask][pos];

        int ans = INT_MAX;

        // Try visiting all unvisited cities
        for (int city = 0; city < n; city++) {

            if ((mask & (1 << city)) == 0) { // if unvisited
                int newMask = mask | (1 << city);
                ans = min(ans, cost[pos][city] + solve(cost, newMask, city, dp));
            }
        }

        return dp[mask][pos] = ans;
    }

    // GFG-required function name
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();

        // dp[mask][pos]
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));

        // Start at city 0 → mask = 1 means only city 0 is visited
        return solve(cost, 1, 0, dp);
    }
};
