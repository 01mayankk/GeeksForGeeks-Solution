class Solution {
  public:
    int countStrings(int n) {
        
        // Base cases
        if(n == 1) return 2;
        if(n == 2) return 3;
        
        // prev2 = dp[n-2], prev1 = dp[n-1]
        int prev2 = 2; // dp[1]
        int prev1 = 3; // dp[2]
        
        int curr;
        
        // Build DP using Fibonacci relation
        for(int i = 3; i <= n; i++) {
            curr = prev1 + prev2;  // dp[i] = dp[i-1] + dp[i-2]
            
            // Update for next iteration
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1; // dp[n]
    }
};