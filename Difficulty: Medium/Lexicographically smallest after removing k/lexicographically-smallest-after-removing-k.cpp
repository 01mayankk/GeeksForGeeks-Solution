class Solution {
public:

    // Function to check whether a number is a power of 2
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();

        // Correct the value of k according to the problem statement
        // If length is a power of 2 -> k = k / 2
        // Otherwise -> k = k * 2
        if (isPowerOfTwo(n))
            k /= 2;
        else
            k *= 2;

        // If we need to remove all characters or more,
        // resulting string would be empty
        if (k >= n)
            return "-1";

        // Acts as a monotonic increasing stack
        string ans;
        ans.reserve(n);

        // Traverse every character of the string
        for (char ch : s) {

            /*
             * If the current character is smaller than the
             * last character in the answer, removing the
             * larger character will give a lexicographically
             * smaller result.
             *
             * Keep removing while:
             * 1. Answer is not empty
             * 2. Deletions are still available
             * 3. Last character is greater than current character
             */
            while (!ans.empty() &&
                   k > 0 &&
                   ans.back() > ch) {
                ans.pop_back();
                k--;
            }

            // Add current character to the answer
            ans.push_back(ch);
        }

        /*
         * If some deletions are still left,
         * remove characters from the end.
         * Removing from the end gives the
         * smallest possible lexicographical string.
         */
        if (k > 0)
            ans.resize(ans.size() - k);

        // Safety check (though handled earlier)
        return ans.empty() ? "-1" : ans;
    }
};