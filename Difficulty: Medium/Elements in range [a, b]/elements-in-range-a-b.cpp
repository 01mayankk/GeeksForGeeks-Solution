class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {

        // Step 1: Sort the array to enable binary search
        sort(arr.begin(), arr.end());

        vector<int> result;

        // Step 2: Process each query independently
        for (auto &q : queries) {

            int a = q[0];
            int b = q[1];

            // Find first index where element >= a
            int left = lower_bound(arr.begin(), arr.end(), a) - arr.begin();

            // Find first index where element > b
            int right = upper_bound(arr.begin(), arr.end(), b) - arr.begin();

            // Elements in range [a, b] = right - left
            result.push_back(right - left);
        }

        // Step 3: Return results for all queries
        return result;
    }
};
