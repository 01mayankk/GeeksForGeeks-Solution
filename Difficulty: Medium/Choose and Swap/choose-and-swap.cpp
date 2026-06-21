class Solution {
public:
    string chooseSwap(string &s) {
        int n = s.size();

        // Stores whether a character is still available
        // in the remaining (right side) part of the string.
        vector<char> rightPresent(26, 0);

        // Mark all characters present in the string.
        for (char ch : s) {
            rightPresent[ch - 'a'] = ch;
        }

        // ch1 = character to be replaced
        // ch2 = smaller character to swap with
        char ch1 = 0, ch2 = 0;

        // Traverse the string from left to right
        for (int i = 0; i < n; i++) {

            // Check if there exists any smaller character
            // than s[i] somewhere later in the string.
            for (char c = 'a'; c < s[i]; c++) {

                // If found, this is the best swap because
                // improving the leftmost possible position
                // gives the lexicographically smallest string.
                if (rightPresent[c - 'a']) {
                    ch1 = s[i];
                    ch2 = c;
                    break;
                }
            }

            // Valid swap pair found
            if (ch1) break;

            // Current character is no longer available
            // for future positions (remove from suffix).
            rightPresent[s[i] - 'a'] = 0;
        }

        // No beneficial swap found
        if (!ch1) return s;

        // Swap all occurrences of ch1 and ch2
        for (char &c : s) {
            if (c == ch1)
                c = ch2;
            else if (c == ch2)
                c = ch1;
        }

        return s;
    }
};