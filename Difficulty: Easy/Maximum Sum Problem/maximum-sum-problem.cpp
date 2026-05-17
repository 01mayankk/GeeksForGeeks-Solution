class Solution {
  public:
    
    // Function to find maximum sum after recursive breaks
    int maxSum(int n) {
        
        // Base case:
        // If n is 0, maximum sum is also 0
        if(n == 0)
            return 0;
        
        // Recursively calculate maximum value obtained
        // by breaking n into n/2, n/3, and n/4
        int brokenSum = maxSum(n / 2) + 
                        maxSum(n / 3) + 
                        maxSum(n / 4);
        
        // Return the maximum between:
        // 1. Keeping n as it is
        // 2. Breaking it recursively
        return max(n, brokenSum);
    }
};