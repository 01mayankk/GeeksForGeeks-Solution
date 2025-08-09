class Solution {
  public:
    int getLongestPrefix(string &s) {
        // Length of the string
        int n = s.size();

        // Z-array to store the length of the longest substring starting at position i
        // which is also a prefix of the string
        vector<int> z(n, 0);

        // Compute Z-function for the string
        // z[i] → length of the longest prefix of s that matches substring starting at i
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            // If i is inside the current Z-box (l...r), use previously computed values
            if (i <= r) 
                z[i] = min(r - i + 1, z[i - l]);

            // Try to extend the Z-box by comparing characters
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) 
                z[i]++;

            // Update Z-box boundaries if extended further
            if (i + z[i] - 1 > r) 
                l = i, r = i + z[i] - 1;
        }

        // Now, we try to find the longest prefix length that divides the string
        // Checking from largest possible prefix length (n-1) to smallest (1)
        for (int len = n - 1; len >= 1; len--) {
            bool ok = true;

            // Check if the prefix of length `len` can be repeated to form the entire string
            for (int i = len; i < n; i += len) {
                // If the matching length from z[] is less than required,
                // this length cannot be the answer
                if (z[i] < min(len, n - i)) { 
                    ok = false; 
                    break; 
                }
            }

            // If valid, return the length
            if (ok) return len;
        }

        // If no valid prefix length found
        return -1;
    }
};
