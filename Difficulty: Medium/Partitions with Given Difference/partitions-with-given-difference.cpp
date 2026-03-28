class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        
        int n = arr.size();
        
        // -------------------------------
        // Step 1: Calculate total sum
        // -------------------------------
        // We need totalSum to derive target subset sum
        int totalSum = 0;
        for(int x : arr) totalSum += x;
        
        
        // -------------------------------
        // Step 2: Check invalid cases
        // -------------------------------
        
        // Case 1: If total sum is smaller than diff,
        // it's impossible to form such partitions
        if(totalSum < diff) return 0;
        
        // Case 2: (totalSum + diff) must be even
        // Because S1 = (totalSum + diff) / 2 must be integer
        if((totalSum + diff) % 2 != 0) return 0;
        
        
        // -------------------------------
        // Step 3: Convert problem
        // -------------------------------
        // Instead of finding two subsets,
        // we now find number of subsets with sum = target
        int target = (totalSum + diff) / 2;
        
        
        // -------------------------------
        // Step 4: DP array
        // -------------------------------
        // dp[j] = number of ways to get sum j
        vector<int> dp(target + 1, 0);
        
        // Base case:
        // There is exactly 1 way to make sum = 0
        // (i.e., choose no elements)
        dp[0] = 1;
        
        
        // -------------------------------
        // Step 5: Fill DP (0/1 Knapsack)
        // -------------------------------
        for(int i = 0; i < n; i++) {
            
            // Traverse backwards to avoid overwriting values
            // (ensures each element is used only once)
            for(int j = target; j >= arr[i]; j--) {
                
                // Include current element arr[i]
                // Add ways of forming (j - arr[i])
                dp[j] += dp[j - arr[i]];
            }
        }
        
        
        // -------------------------------
        // Final Answer
        // -------------------------------
        // Number of subsets with sum = target
        return dp[target];
    }
};