class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {

        int n = arr.size();

        // Maximum subarray sum ending at the current index
        // without deleting any element.
        int keep = arr[0];

        // Maximum subarray sum ending at the current index
        // after deleting exactly one element.
        // Initially impossible, so mark it with INT_MIN.
        int remove = INT_MIN;

        // Stores the overall maximum subarray sum.
        int ans = arr[0];

        for (int i = 1; i < n; i++) {

            // Store the previous value of 'keep' because it is
            // needed while updating 'remove'.
            int prevKeep = keep;

            // Standard Kadane's Algorithm:
            // Either start a new subarray from arr[i]
            // or extend the previous subarray.
            keep = max(arr[i], prevKeep + arr[i]);

            // Update the state where one deletion is allowed.
            //
            // Case 1:
            // Delete the current element.
            // The sum becomes the previous 'keep'.
            //
            // Case 2:
            // We have already deleted an element earlier,
            // so simply include the current element.
            if (remove == INT_MIN)
                remove = prevKeep;
            else
                remove = max(prevKeep, remove + arr[i]);

            // Update the overall maximum answer.
            ans = max(ans, max(keep, remove));
        }

        return ans;
    }
};