class Solution {
public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        
        // Base case: An array of size 0, 1, or 2 is always bitonic by default
        if (n <= 2) return n;

        // inc[i] will store the length of the longest strictly/non-strictly 
        // increasing subarray ending at index i
        vector<int> inc(n, 1);
        
        // Populate the inc array from left to right
        for (int i = 1; i < n; i++) {
            // If current element is greater than or equal to the previous one,
            // it extends the length of the increasing subarray
            if (arr[i] >= arr[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }

        // dec[i] will store the length of the longest strictly/non-strictly 
        // decreasing subarray starting at index i
        vector<int> dec(n, 1);
        
        // Populate the dec array from right to left
        for (int i = n - 2; i >= 0; i--) {
            // If current element is greater than or equal to the next one,
            // it extends the length of the decreasing subarray
            if (arr[i] >= arr[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }

        int max_len = 0;
        
        // Iterate through all possible transition/peak points 'i'
        for (int i = 0; i < n; i++) {
            // The peak element arr[i] is shared and counted twice 
            // (once in inc[i] and once in dec[i]), so we subtract 1
            max_len = max(max_len, inc[i] + dec[i] - 1);
        }

        // Return the length of the longest bitonic subarray found
        return max_len;
    }
};