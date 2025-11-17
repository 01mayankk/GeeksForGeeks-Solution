class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        
        // dp[i] = maximum sum of an increasing subsequence ending at index i
        vector<int> dp(n);
        
        // Every element by itself forms an increasing subsequence
        // so initialize dp[i] = arr[i]
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }
        
        // Keep track of the maximum sum found so far
        int maxSum = arr[0];
        
        // Build DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                
                // If arr[i] can be appended to the subsequence ending at arr[j]
                if (arr[i] > arr[j]) {
                    
                    // Update dp[i] with the best possible sum
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            
            // Update the global maximum sum
            maxSum = max(maxSum, dp[i]);
        }
        
        // The maximum value in dp[] is the answer
        return maxSum;
    }
};
