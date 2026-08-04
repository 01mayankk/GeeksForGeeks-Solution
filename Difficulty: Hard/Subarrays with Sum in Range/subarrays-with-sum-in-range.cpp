class Solution {
private:
    // Helper function to count subarrays with sum less than or equal to a given target
    long long countSubarraysWithSumLessOrEqualTo(const vector<int>& arr, long long target) {
        long long count = 0;
        long long current_sum = 0;
        int left = 0;
        
        // Sliding window approach
        for (int right = 0; right < arr.size(); ++right) {
            current_sum += arr[right];
            
            // Shrink the window from the left if the current sum exceeds the target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }
            
            // The number of valid subarrays ending at the current 'right' index
            // is exactly the size of the current window
            count += (right - left + 1);
        }
        
        return count;
    }

public:
    int countSubarray(vector<int>& arr, int l, int r) {
        // The number of subarrays with sum in range [l, r] is equal to
        // (number of subarrays with sum <= r) - (number of subarrays with sum <= l - 1)
        long long max_count = countSubarraysWithSumLessOrEqualTo(arr, r);
        long long min_count = countSubarraysWithSumLessOrEqualTo(arr, l - 1);
        
        return max_count - min_count;
    }
};