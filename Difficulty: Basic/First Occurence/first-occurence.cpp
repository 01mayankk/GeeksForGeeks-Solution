class Solution {
public:
    int firstOccurence(string& txt, string& pat) {
        int n = txt.size();
        int m = pat.size();

        // Loop over txt and check substring match
        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Try to match pattern starting at index i
            while (j < m && txt[i + j] == pat[j]) {
                j++;
            }

            // If we matched entire pattern
            if (j == m) return i;
        }

        // Pattern not found
        return -1;
    }
};
