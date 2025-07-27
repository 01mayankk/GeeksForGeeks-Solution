// class Solution {
// public:
//     int minJumps(vector<int>& arr) {
//         int n = arr.size();  // Get the length of the array

//         // If there's only one element, we're already at the end — no jump needed
//         if (n == 1) return 0;

//         // If the first element is 0, we can't move anywhere — not reachable
//         if (arr[0] == 0) return -1;

//         // Create a dp array where dp[i] stores the minimum number of jumps to reach index i
//         vector<int> dp(n, INT_MAX);  // Initialize all values to INT_MAX meaning initially unreachable

//         dp[0] = 0;  // Starting point — 0 jumps needed to be at index 0

//         // Loop through each position i from 1 to n-1
//         for (int i = 1; i < n; i++) {
//             // For every position i, check all previous positions j (from 0 to i-1)
//             for (int j = 0; j < i; j++) {
//                 // Check if index i is reachable from index j
//                 // That is, can we jump from j to i?
//                 // Condition: j + arr[j] >= i → i lies within jump range from j
//                 // Also check if dp[j] is not INT_MAX → means j is reachable
//                 if (j + arr[j] >= i && dp[j] != INT_MAX) {
//                     // Update dp[i] with the minimum jumps required to reach i
//                     dp[i] = min(dp[i], dp[j] + 1);
//                     // No need to continue checking other j's if one valid jump is found
//                     // But this can be skipped if you want to consider all options
//                 }
//             }
//         }

//         // If dp[n - 1] is still INT_MAX, it means last index is not reachable
//         return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
//     }
// };


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        // If the array has only one element, we're already at the destination.
        if (n <= 1) return 0;

        // If the first element is 0, we can't make any move, so return -1
        if (arr[0] == 0) return -1;

        // Initialize the number of jumps needed to reach the end
        int jumps = 1;

        // 'farthest' is the farthest index we can reach from the current range
        int farthest = arr[0];

        // 'currentEnd' is the end of the current jump's range
        int currentEnd = arr[0];

        // Start traversing the array from index 1
        for (int i = 1; i < n - 1; i++) {
            // Update the farthest reachable index from this position
            farthest = max(farthest, i + arr[i]);

            // If we've reached the end of the current jump range
            if (i == currentEnd) {
                jumps++;  // We need to make another jump
                currentEnd = farthest;  // Update the end of the new jump range

                // If currentEnd has already reached or gone beyond the last index
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }

        // After the loop, check if we are able to reach the last index
        return currentEnd >= n - 1 ? jumps : -1;
    }
};

