class Solution {
public:
    int totalWays(vector<int>& arr, int target) {
        
        int n = arr.size();

        // Step 1: Calculate total sum of array
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }

        // Step 2: Check if valid transformation is possible
        // (S + target) must be even and non-negative
        if ((sum + target) % 2 != 0 || abs(target) > sum) {
            return 0;
        }

        // Required subset sum
        int subsetSum = (sum + target) / 2;

        // Step 3: DP array
        // dp[i] = number of ways to get sum = i
        vector<int> dp(subsetSum + 1, 0);

        // Base case: 1 way to make sum 0 (choose nothing)
        dp[0] = 1;

        // Step 4: Fill DP (0/1 Knapsack style)
        for (int num : arr) {
            // Traverse backwards to avoid reuse of same element
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        // Final answer
        return dp[subsetSum];
    }
};