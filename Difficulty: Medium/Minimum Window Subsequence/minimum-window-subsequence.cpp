class Solution {
public:
    string minWindow(string& s1, string& s2) {

        int n = s1.size();
        int m = s2.size();

        int minLen = INT_MAX;     // Stores minimum window length
        int startIndex = -1;      // Starting index of best window

        int i = 0;  // Pointer for s1

        while (i < n) {

            // Step 1: Try to match s2 as subsequence
            int j = 0;
            while (i < n) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == m) break;  // Full subsequence found
                }
                i++;
            }

            // If subsequence not found, break
            if (i == n) break;

            // Step 2: Backward shrinking
            int end = i;        // End of current window
            j = m - 1;

            while (j >= 0) {
                if (s1[i] == s2[j]) {
                    j--;
                }
                i--;
            }
            i++;  // Move back to valid position

            // Step 3: Update answer
            if (end - i + 1 < minLen) {
                minLen = end - i + 1;
                startIndex = i;
            }

            // Step 4: Move forward to find next possible window
            i++;
        }

        // If no window found
        if (startIndex == -1) return "";

        return s1.substr(startIndex, minLen);
    }
};
