class Solution {
public:
    static const int MOD = 1000000007;

    int countStrings(int n, int k) {

        // prev0[j] = Number of binary strings of current length
        //            ending with '0' and having exactly j adjacent "11" pairs.
        //
        // prev1[j] = Number of binary strings of current length
        //            ending with '1' and having exactly j adjacent "11" pairs.
        vector<int> prev0(k + 1, 0), prev1(k + 1, 0);

        // Base case for strings of length 1:
        // "0" and "1", both have 0 adjacent "11" pairs.
        prev0[0] = 1;
        prev1[0] = 1;

        // Build DP for lengths from 2 to n.
        for (int len = 2; len <= n; len++) {

            // DP arrays for current length.
            vector<int> cur0(k + 1, 0), cur1(k + 1, 0);

            for (int adj = 0; adj <= k; adj++) {

                // Case 1: Append '0'
                // A trailing 0 never creates a new "11" pair.
                // We can append it to strings ending with either 0 or 1.
                cur0[adj] = (prev0[adj] + prev1[adj]) % MOD;

                // Case 2: Append '1' after a string ending with '0'
                // Pattern becomes "...01", so no new adjacent "11" pair.
                cur1[adj] = (cur1[adj] + prev0[adj]) % MOD;

                // Case 3: Append '1' after a string ending with '1'
                // Pattern becomes "...11", creating one additional adjacent pair.
                // Therefore, previous state must have (adj - 1) pairs.
                if (adj > 0) {
                    cur1[adj] = (cur1[adj] + prev1[adj - 1]) % MOD;
                }
            }

            // Move current results to previous for the next iteration.
            prev0 = move(cur0);
            prev1 = move(cur1);
        }

        // Total strings ending with either 0 or 1.
        return (prev0[k] + prev1[k]) % MOD;
    }
};