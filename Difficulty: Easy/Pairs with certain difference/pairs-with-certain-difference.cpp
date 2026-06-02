class Solution {
public:
    int sumDiffPairs(vector<int>& arr, int k) {
        
        int n = arr.size();

        // Sort array so close elements come together
        sort(arr.begin(), arr.end());

        // dp[i] = maximum pair sum using elements from 0...i
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {

            // Option 1: Ignore current element
            dp[i] = dp[i - 1];

            // Option 2: Form pair (arr[i-1], arr[i])
            if (arr[i] - arr[i - 1] < k) {

                int currentPairSum = arr[i] + arr[i - 1];

                if (i >= 2)
                    currentPairSum += dp[i - 2];

                dp[i] = max(dp[i], currentPairSum);
            }
        }

        // Maximum sum of all valid disjoint pairs
        return dp[n - 1];
    }
};