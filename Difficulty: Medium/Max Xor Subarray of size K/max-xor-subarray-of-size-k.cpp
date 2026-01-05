class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {

        int n = arr.size();

        // Stores XOR of current window of size k
        int xorValue = 0;

        // Step 1: Compute XOR of the first window [0 ... k-1]
        for (int i = 0; i < k; i++) {
            xorValue ^= arr[i];   // XOR accumulates elements
        }

        // Initialize maximum XOR with first window's XOR
        int maxXor = xorValue;

        // Step 2: Slide the window from index k to n-1
        for (int i = k; i < n; i++) {

            // Remove the element that goes out of the window
            // XORing again cancels its effect
            xorValue ^= arr[i - k];

            // Add the new element entering the window
            xorValue ^= arr[i];

            // Update the maximum XOR found so far
            maxXor = max(maxXor, xorValue);
        }

        // Return maximum XOR of any subarray of size k
        return maxXor;
    }
};
