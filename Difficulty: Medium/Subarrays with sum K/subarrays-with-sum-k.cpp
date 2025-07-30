class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // HashMap to store frequency of prefix sums
        unordered_map<int, int> prefixSumFreq;

        // Initialize with 0 sum having frequency 1
        // This handles the case where a subarray from index 0 to i has sum exactly equal to k
        prefixSumFreq[0] = 1;

        int count = 0; // To store the final count of subarrays with sum = k
        int sum = 0;   // To store the current prefix sum

        // Iterate through the array
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i]; // Update the running sum

            // Check if there exists a prefix sum such that:
            // current_sum - k = previous_prefix_sum
            // If yes, it means the subarray between that prefix and current index has sum = k
            if(prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k]; // Add the frequency of that prefix sum to count
            }

            // Record the current prefix sum in the map
            // (or increment its frequency if already seen)
            prefixSumFreq[sum]++;
        }

        // Return total number of subarrays with sum = k
        return count;
    }
};
