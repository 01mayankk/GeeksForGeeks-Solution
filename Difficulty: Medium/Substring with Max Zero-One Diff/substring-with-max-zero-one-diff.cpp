class Solution {
public:
    int maxSubstring(string &s) {

        // Maximum sum found so far
        int maxSum = -1;

        // Current subarray sum for Kadane's algorithm
        int currSum = 0;

        for(char ch : s) {

            // Convert:
            // '0' -> +1
            // '1' -> -1
            int val = (ch == '0') ? 1 : -1;

            // Either extend current subarray
            // or start a new subarray from current position
            currSum = max(val, currSum + val);

            // Update global maximum
            maxSum = max(maxSum, currSum);
        }

        /*
            If maxSum <= 0, then no substring has
            more 0s than 1s.

            This happens when string contains all 1s.
        */
        return (maxSum <= 0) ? -1 : maxSum;
    }
};