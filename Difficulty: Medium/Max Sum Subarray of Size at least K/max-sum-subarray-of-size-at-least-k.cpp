class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Store the maximum subarray sum ending at each index using Kadane's algorithm
        vector<int> max_ending_here(n);
        max_ending_here[0] = arr[0];
        for (int i = 1; i < n; i++) {
            max_ending_here[i] = max(arr[i], max_ending_here[i - 1] + arr[i]);
        }
        
        // Calculate the sum of the first k elements (initial window)
        int curr_k_sum = 0;
        for (int i = 0; i < k; i++) {
            curr_k_sum += arr[i];
        }
        
        // Initialize the answer with the sum of the first k elements
        int ans = curr_k_sum;
        
        // Slide the window of size k from index k to the end of the array
        for (int i = k; i < n; i++) {
            // Add the current element and remove the first element of the previous window
            curr_k_sum = curr_k_sum + arr[i] - arr[i - k];
            
            // The max sum of length at least k ending at index i can be either:
            // 1. Just the sum of the current k-length window
            // 2. The current k-length window + the max subarray sum ending just before this window
            ans = max(ans, curr_k_sum);
            
            // If the max subarray sum right before our current window is positive, 
            // adding it will give us a larger sum for a subarray of length >= k
            if (max_ending_here[i - k] > 0) {
                ans = max(ans, curr_k_sum + max_ending_here[i - k]);
            }
        }
        
        return ans;
    }
};