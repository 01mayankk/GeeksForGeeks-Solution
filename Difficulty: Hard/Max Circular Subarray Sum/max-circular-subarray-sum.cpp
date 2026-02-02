class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        
        int n = arr.size();
        
        int maxSum = arr[0];     // Max subarray sum (non-circular)
        int currMax = 0;
        
        int minSum = arr[0];     // Min subarray sum
        int currMin = 0;
        
        int totalSum = 0;
        
        for(int i = 0; i < n; i++)
        {
            // Kadane for maximum subarray sum
            currMax = max(arr[i], currMax + arr[i]);
            maxSum = max(maxSum, currMax);
            
            // Kadane for minimum subarray sum
            currMin = min(arr[i], currMin + arr[i]);
            minSum = min(minSum, currMin);
            
            totalSum += arr[i];
        }
        
        // If all elements are negative, wrapping sum becomes 0 (invalid)
        if (maxSum < 0)
            return maxSum;
        
        // Return maximum of non-wrapping and wrapping case
        return max(maxSum, totalSum - minSum);
    }
};
