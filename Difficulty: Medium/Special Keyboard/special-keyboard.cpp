class Solution {
  public:
    
    int optimalKeys(int n) {
        
        // For small values of n,
        // best option is pressing 'A' every time
        if(n <= 6) {
            return n;
        }
        
        // dp[i] = maximum number of A's possible
        // using exactly i key presses
        vector<int> dp(n + 1, 0);
        
        // Base cases
        for(int i = 1; i <= 6; i++) {
            dp[i] = i;
        }
        
        // Compute answer for all values from 7 to n
        for(int i = 7; i <= n; i++) {
            
            // Initially assume pressing 'A'
            dp[i] = i;
            
            // Try every possible breakpoint
            // where we perform:
            // Ctrl+A, Ctrl+C, then multiple Ctrl+V
            
            for(int j = i - 3; j >= 1; j--) {
                
                // After j operations:
                // 2 operations used for Ctrl+A and Ctrl+C
                // Remaining operations used for Ctrl+V
                
                int pasteCount = i - j - 2;
                
                // Total characters after pasting
                int current = dp[j] * (pasteCount + 1);
                
                // Update maximum
                dp[i] = max(dp[i], current);
            }
        }
        
        // Final answer
        return dp[n];
    }
};