class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Count total number of 1s in the array
        int totalOnes = 0;
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }
        
        // If there are no 1s, grouping is impossible
        if (totalOnes == 0) return -1;
        
        // Step 2: Use sliding window of size = total number of 1s
        int currOnes = 0;
        
        // Count number of 1s in the first window
        for (int i = 0; i < totalOnes; i++) {
            if (arr[i] == 1) currOnes++;
        }
        
        // Store maximum 1s found in any valid window
        int maxOnes = currOnes;
        
        // Step 3: Slide the window across the array
        for (int i = totalOnes; i < n; i++) {
            
            // Include next element in the window
            if (arr[i] == 1) currOnes++;
            
            // Exclude the element that is leaving the window
            if (arr[i - totalOnes] == 1) currOnes--;
            
            // Update maximum count of 1s in any window
            maxOnes = max(maxOnes, currOnes);
        }
        
        // Step 4: Minimum swaps required
        // We need to convert remaining 0s in best window into 1s
        // So swaps = total 1s - max 1s found in a window
        return totalOnes - maxOnes;
    }
};