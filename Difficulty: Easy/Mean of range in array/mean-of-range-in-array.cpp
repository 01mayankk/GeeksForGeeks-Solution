class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        
        // Size of the input array
        int n = arr.size();

        // Step 1: Create prefix sum array
        // prefix[i] will store sum of elements from index 0 to i-1
        // (i.e., prefix[0] = 0, prefix[1] = arr[0], etc.)
        vector<long long> prefix(n + 1, 0);

        // Build prefix sum array
        for (int i = 0; i < n; i++) {
            // Current prefix = previous prefix + current element
            prefix[i + 1] = prefix[i] + arr[i];
        }

        // Result array to store answers for each query
        vector<int> result;

        // Step 2: Process each query
        for (auto &q : queries) {

            // Extract left and right indices
            int l = q[0];
            int r = q[1];

            // Compute sum of subarray [l, r]
            // Using prefix sum formula:
            // sum = prefix[r+1] - prefix[l]
            long long sum = prefix[r + 1] - prefix[l];

            // Number of elements in subarray
            int length = r - l + 1;

            // Compute mean (integer division automatically gives floor value)
            int mean = sum / length;

            // Store result
            result.push_back(mean);
        }

        // Return final result
        return result;
    }
};