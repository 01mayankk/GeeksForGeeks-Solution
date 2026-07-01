class Solution {
public:
    bool divisibleByK(vector<int>& arr, int k) {

        // dp[r] = true if there exists a non-empty subset
        // whose sum % k == r.
        vector<bool> dp(k, false);

        for (int num : arr) {

            // Create a copy because updates made in this iteration
            // should not be reused immediately.
            vector<bool> next = dp;

            // Case 1:
            // Start a new subset containing only the current element.
            next[num % k] = true;

            // Case 2:
            // Add current element to every previously possible subset.
            for (int rem = 0; rem < k; rem++) {

                if (dp[rem]) {

                    // New remainder after adding current number.
                    int newRem = (rem + num) % k;

                    next[newRem] = true;
                }
            }

            // Move updated states back.
            dp = next;

            // If remainder 0 is possible,
            // some non-empty subset is divisible by k.
            if (dp[0])
                return true;
        }

        return false;
    }
};