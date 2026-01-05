class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {

        int windowSum = 0;   // Stores sum of the current window of size k

        // Step 1: Calculate sum of the first window (first k elements)
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        // Initialize maxSum with the first window sum
        int maxSum = windowSum;

        // Step 2: Slide the window from index k to the end of array
        for (int i = k; i < arr.size(); i++) {

            // Add the incoming element and remove the outgoing element
            windowSum += arr[i] - arr[i - k];

            // Update the maximum sum found so far
            maxSum = max(maxSum, windowSum);
        }

        // Return the maximum sum of any subarray of size k
        return maxSum;
    }
};
