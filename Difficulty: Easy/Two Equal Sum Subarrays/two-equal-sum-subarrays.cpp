class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Calculate total sum
        long long totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }
        
        // Step 2: If total sum is odd, cannot split equally
        if (totalSum % 2 != 0) {
            return false;
        }
        
        // Target sum for one subarray
        long long target = totalSum / 2;
        
        // Step 3: Traverse and keep prefix sum
        long long prefixSum = 0;
        
        for (int i = 0; i < n - 1; i++) {  
            // (n-1 because both subarrays must be non-empty)
            
            prefixSum += arr[i];
            
            // Step 4: Check if prefix equals target
            if (prefixSum == target) {
                return true;
            }
        }
        
        // If no valid split found
        return false;
    }
};