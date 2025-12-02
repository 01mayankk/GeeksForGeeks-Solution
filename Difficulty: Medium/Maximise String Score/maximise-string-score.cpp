class Solution {
public:
    long long maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();

        /*******************************************************
         * STEP 1: Build "can" matrix for allowed jumps.
         * can[x][y] = true means we can jump from char x → y.
         *******************************************************/
        bool can[26][26] = {0};
        for (auto &v : jumps) {
            can[v[0] - 'a'][v[1] - 'a'] = true;
        }

        /*******************************************************
         * STEP 2: Pre-store all positions of each character.
         * pos[c] = sorted list of indices where character c appears.
         * This allows fast "next occurrence" lookups.
         *******************************************************/
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++)
            pos[s[i] - 'a'].push_back(i);

        /*******************************************************
         * STEP 3: Prefix sum of ASCII values.
         * pref[i] = sum of ASCII values from s[0..i-1].
         * Used to compute range sum in O(1).
         *******************************************************/
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (int)s[i];

        /*******************************************************
         * STEP 4: DP array.
         * dp[i] = maximum score achievable when landing at index i.
         * Initialize everything to negative-infinity except start index.
         *******************************************************/
        vector<long long> dp(n, LLONG_MIN);
        dp[0] = 0; // Starting at index 0 gives score = 0.

        /*******************************************************
         * STEP 5: nextPtr[c] tracks the NEXT unvisited occurrence
         *          for character c. This pointer only moves forward.
         *
         * This avoids repeated binary searches and ensures O(n) time.
         *******************************************************/
        vector<int> nextPtr(26, 0);

        /*******************************************************
         * STEP 6: Iterate linearly from left to right.
         * For each index i, try all valid forward jumps.
         *******************************************************/
        for (int i = 0; i < n; i++) {

            // If index i is unreachable, skip.
            if (dp[i] == LLONG_MIN) continue;

            int c1 = s[i] - 'a'; // Current character.

            /**********************
             * JUMP TYPE 1:
             * Jump to the next occurrence of the SAME character.
             **********************/
            {
                auto &v1 = pos[c1];       // All indices where s[i] appears.
                int idx = nextPtr[c1];    // Pointer to next unvisited position.

                // Move pointer until we find j > i.
                while (idx < v1.size() && v1[idx] <= i) idx++;
                nextPtr[c1] = idx;

                if (idx < v1.size()) {
                    int j = v1[idx]; // The next same-character index.

                    long long sc = calcScore(i, j, s, pos, pref); // Score gained.
                    dp[j] = max(dp[j], dp[i] + sc);               // DP transition.
                }
            }

            /**********************
             * JUMP TYPE 2:
             * Jump using allowed transitions from c1 → c2.
             * Only consider the NEXT occurrence of each c2.
             **********************/
            for (int c2 = 0; c2 < 26; c2++) {

                // Skip if this char pair cannot jump.
                if (!can[c1][c2]) continue;

                auto &v2 = pos[c2];
                int &p = nextPtr[c2]; // pointer for character c2

                // Move pointer until we find j > i.
                while (p < v2.size() && v2[p] <= i) p++;

                if (p < v2.size()) {
                    int j = v2[p]; // Next valid index with char c2

                    long long sc = calcScore(i, j, s, pos, pref);
                    dp[j] = max(dp[j], dp[i] + sc);
                }
            }
        }

        /*******************************************************
         * STEP 7: Final answer is the maximum dp value.
         *******************************************************/
        long long ans = 0;
        for (long long x : dp)
            ans = max(ans, x);

        return ans;
    }

private:
    /**************************************************************
     * Calculate score(i, j):
     *
     * score(i,j) = sum of ASCII(s[k]) for i ≤ k < j
     *              EXCLUDING all characters equal to s[j].
     *
     * We compute:
     *   total = pref[j] - pref[i]
     *   subtract (#occurrences of s[j] in [i..j-1]) * ASCII(s[j])
     **************************************************************/
    long long calcScore(int i, int j, string &s,
                        vector<vector<int>> &pos,
                        vector<long long> &pref) {

        // Sum of ascii(s[i..j-1])
        long long total = pref[j] - pref[i];

        int c = s[j] - 'a';
        long long asciiVal = s[j];

        // Count how many s[j] appear inside [i, j-1].
        auto &v = pos[c];

        // First index >= i
        int L = lower_bound(v.begin(), v.end(), i) - v.begin();
        // First index > j-1
        int R = upper_bound(v.begin(), v.end(), j - 1) - v.begin();

        int cnt = R - L; // occurrences of s[j] inside [i, j-1]

        // Remove contribution of repeated s[j]
        return total - cnt * asciiVal;
    }
};
