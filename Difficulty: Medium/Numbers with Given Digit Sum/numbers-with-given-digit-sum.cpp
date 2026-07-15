class Solution {
private:
    // Helper function for dynamic programming
    int solve(int digits_left, int current_sum, vector<vector<int>>& dp) {
        // Base case: if no digits left, 1 way if sum is 0, else 0 ways
        if (digits_left == 0) {
            return current_sum == 0 ? 1 : 0;
        }
        
        // Base case: if sum becomes negative, no valid way
        if (current_sum < 0) {
            return 0;
        }
        
        // Return precalculated result if available
        if (dp[digits_left][current_sum] != -1) {
            return dp[digits_left][current_sum];
        }
        
        int ways = 0;
        
        // Remaining digits can be any number from 0 to 9
        for (int i = 0; i <= 9; i++) {
            ways += solve(digits_left - 1, current_sum - i, dp);
        }
        
        // Store and return the computed result
        return dp[digits_left][current_sum] = ways;
    }

public:
    int countWays(int n, int sum) {
        // The maximum possible sum for 'n' digits is 9 * n
        // If the target sum is out of bounds, return -1
        if (sum < 1 || sum > 9 * n) {
            return -1;
        }
        
        // Initialize DP table with -1
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        int total_ways = 0;
        
        // First digit must be between 1 and 9 to avoid leading zeros
        for (int i = 1; i <= 9; i++) {
            if (sum - i >= 0) {
                total_ways += solve(n - 1, sum - i, dp);
            }
        }
        
        // If no such number exists, return -1 as specified
        return total_ways == 0 ? -1 : total_ways;
    }
};