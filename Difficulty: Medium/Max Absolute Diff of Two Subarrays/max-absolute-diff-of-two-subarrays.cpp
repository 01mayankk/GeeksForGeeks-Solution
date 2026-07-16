class Solution {
public:
    /**
     * @brief Finds the maximum absolute difference between the sums of two non-overlapping contiguous subarrays.
     * * @param arr The input vector of integers.
     * @return int The maximum absolute difference.
     */
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has fewer than 2 elements, forming two non-overlapping subarrays is impossible.
        if (n < 2) return 0;
        
        // Initialize four vectors to store the maximum and minimum subarray sums.
        // leftMax[i]  : Max subarray sum in arr[0...i]
        // leftMin[i]  : Min subarray sum in arr[0...i]
        // rightMax[i] : Max subarray sum in arr[i...n-1]
        // rightMin[i] : Min subarray sum in arr[i...n-1]
        vector<int> leftMax(n), leftMin(n), rightMax(n), rightMin(n);
        
        // ---------------------------------------------------------
        // Pass 1: Compute leftMax and leftMin using Kadane's Algorithm
        // ---------------------------------------------------------
        int curMax = 0, curMin = 0;
        int maxSoFar = arr[0], minSoFar = arr[0];
        
        for (int i = 0; i < n; ++i) {
            // Calculate current max and min contiguous sum ending at index i
            curMax = max(arr[i], curMax + arr[i]);
            curMin = min(arr[i], curMin + arr[i]);
            
            // Keep track of the overall max and min sum found from index 0 to i
            maxSoFar = max(maxSoFar, curMax);
            minSoFar = min(minSoFar, curMin);
            
            // Store the best results seen up to index i
            leftMax[i] = maxSoFar;
            leftMin[i] = minSoFar;
        }
        
        // ---------------------------------------------------------
        // Pass 2: Compute rightMax and rightMin using Kadane's Algorithm
        // ---------------------------------------------------------
        // Reset running variables for the reverse traversal
        curMax = 0; curMin = 0;
        maxSoFar = arr[n - 1]; minSoFar = arr[n - 1];
        
        for (int i = n - 1; i >= 0; --i) {
            // Calculate current max and min contiguous sum starting at index i
            curMax = max(arr[i], curMax + arr[i]);
            curMin = min(arr[i], curMin + arr[i]);
            
            // Keep track of the overall max and min sum found from index i to n-1
            maxSoFar = max(maxSoFar, curMax);
            minSoFar = min(minSoFar, curMin);
            
            // Store the best results seen from index i to the end of the array
            rightMax[i] = maxSoFar;
            rightMin[i] = minSoFar;
        }
        
        // ---------------------------------------------------------
        // Pass 3: Find the Maximum Absolute Difference across all split points
        // ---------------------------------------------------------
        int maxDiff = 0;
        
        // Iterate through every valid split point 'i'. 
        // The array is conceptually divided into: Left -> arr[0...i], Right -> arr[i+1...n-1]
        for (int i = 0; i < n - 1; ++i) {
            // Scenario 1: Largest sum on the left minus the smallest sum on the right
            int diff1 = abs(leftMax[i] - rightMin[i + 1]);
            
            // Scenario 2: Smallest sum on the left minus the largest sum on the right
            int diff2 = abs(leftMin[i] - rightMax[i + 1]);
            
            // Update the global maximum difference found so far
            maxDiff = max({maxDiff, diff1, diff2});
        }
        
        return maxDiff;
    }
};