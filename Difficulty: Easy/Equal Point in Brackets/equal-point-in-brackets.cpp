class Solution {
public:
    int findIndex(string &s) {
        int n = s.size();

        // Count total closing brackets in the string
        int closeCount = 0;
        for (char ch : s) {
            if (ch == ')')
                closeCount++;
        }

        int openCount = 0;

        // Check every possible split position
        for (int i = 0; i < n; i++) {

            // If number of '(' on left equals
            // number of ')' on right, return this position
            if (openCount == closeCount)
                return i;

            // Update counts after crossing current character
            if (s[i] == '(')
                openCount++;
            else
                closeCount--;
        }

        // Check split position at the end of the string
        if (openCount == closeCount)
            return n;

        return -1; // This case generally won't occur
    }
};