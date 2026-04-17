class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        
        int totalOnes = 0;  // Count original number of 1s
        
        // Step 1: Count total 1s
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) totalOnes++;
        }
        
        // Step 2: Apply Kadane's Algorithm
        int maxGain = 0;   // Maximum gain after flip
        int currGain = 0;  // Current subarray gain
        
        for (int i = 0; i < n; i++) {
            // Convert values:
            // 0 -> +1 (gain)
            // 1 -> -1 (loss)
            int val = (arr[i] == 0) ? 1 : -1;
            
            currGain = max(val, currGain + val);  // Kadane step
            maxGain = max(maxGain, currGain);
        }
        
        // Step 3: Final result
        return totalOnes + maxGain;
    }
};