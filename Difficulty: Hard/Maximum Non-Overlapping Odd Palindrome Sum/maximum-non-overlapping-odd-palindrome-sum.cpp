class Solution {
  public:
    int maxSum(string &s) {
        // Get length of the string
        int n = (int)s.size();
        // If string has fewer than 2 characters, no split is possible → return 0
        if (n < 2) return 0;

        // Step 1: Manacher’s Algorithm to find longest odd-length palindromes centered at each index
        vector<int> rad(n);  // rad[i] = radius of palindrome centered at i (including center itself)
        
        // L, R = current palindrome's left and right boundary
        for (int i = 0, L = 0, R = -1; i < n; ++i) {
            // k = initial radius guess
            // If i > R, we are outside known palindrome → start with radius 1
            // Else, mirror position = L + R - i, take minimum of mirror's radius and right boundary limit
            int k = (i > R) ? 1 : min(rad[L + R - i], R - i + 1);

            // Expand palindrome centered at i as much as possible
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) 
                ++k;

            // Store radius
            rad[i] = k;

            // If this palindrome extends beyond the current right boundary, update L and R
            if (i + k - 1 > R) { 
                L = i - k + 1;
                R = i + k - 1;
            }
        }

        // Step 2: Arrays to store the best palindrome length ending at or starting from a given index
        vector<int> bestEnd(n, 0), bestStart(n, 0);

        // Fill bestEnd and bestStart based on palindrome lengths
        for (int c = 0; c < n; ++c) {
            int len = 2 * rad[c] - 1;  // Actual palindrome length
            int l = c - rad[c] + 1;    // Left boundary of palindrome
            int r = c + rad[c] - 1;    // Right boundary of palindrome
            
            // Store the best palindrome ending exactly at 'r'
            bestEnd[r] = max(bestEnd[r], len);
            // Store the best palindrome starting exactly at 'l'
            bestStart[l] = max(bestStart[l], len);
        }

        // Step 3: Propagate best palindrome lengths to the left for bestEnd[]
        // If best palindrome ends at i+1 with length L, then at i, we can have length L-2
        for (int i = n - 2; i >= 0; --i)
            bestEnd[i] = max(bestEnd[i], bestEnd[i + 1] - 2);
        
        // Step 4: Propagate best palindrome lengths to the right for bestStart[]
        for (int i = 1; i < n; ++i)
            bestStart[i] = max(bestStart[i], bestStart[i - 1] - 2);

        // Step 5: Find maximum sum of lengths of two non-overlapping palindromes
        int bestLeft = 0; // Best palindrome length seen so far on the left
        int ans = 0;      // Final answer
        for (int i = 0; i + 1 < n; ++i) {
            // Update bestLeft with best palindrome ending at index i
            bestLeft = max(bestLeft, bestEnd[i]);
            // Maximize answer by combining bestLeft with best palindrome starting at i+1
            ans = max(ans, bestLeft + bestStart[i + 1]);
        }
        
        return ans; 
    }
};
