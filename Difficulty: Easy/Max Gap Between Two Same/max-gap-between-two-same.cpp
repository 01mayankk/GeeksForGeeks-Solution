class Solution {
public:
    int maxCharGap(string &s) {

        // Stores the first occurrence index of each character.
        // Initialize with -1, meaning character not seen yet.
        vector<int> firstIndex(26, -1);

        int maxGap = -1;

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {

            int idx = s[i] - 'a';

            // First time seeing this character
            if (firstIndex[idx] == -1) {
                firstIndex[idx] = i;
            }
            else {
                // Character already seen
                // Number of characters between two same characters
                int gap = i - firstIndex[idx] - 1;

                // Update maximum gap
                maxGap = max(maxGap, gap);
            }
        }

        return maxGap;
    }
};