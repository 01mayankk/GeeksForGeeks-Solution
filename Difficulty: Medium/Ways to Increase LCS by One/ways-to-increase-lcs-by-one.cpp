#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {

        int n1 = s1.size();
        int n2 = s2.size();

        // ==========================================================
        // PREFIX LCS DP
        //
        // pref[i][j] stores the LCS length between:
        // s1[0 ... i-1] and s2[0 ... j-1]
        // ==========================================================
        vector<vector<int>> pref(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {

                // Characters match
                if (s1[i - 1] == s2[j - 1])
                    pref[i][j] = 1 + pref[i - 1][j - 1];

                // Characters don't match
                else
                    pref[i][j] = max(pref[i - 1][j], pref[i][j - 1]);
            }
        }

        // Original LCS before inserting any character.
        int originalLCS = pref[n1][n2];

        // ==========================================================
        // SUFFIX LCS DP
        //
        // suf[i][j] stores the LCS length between:
        // s1[i ... n1-1] and s2[j ... n2-1]
        //
        // We compute it from bottom-right to top-left.
        // ==========================================================
        vector<vector<int>> suf(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {

                // Characters match
                if (s1[i] == s2[j])
                    suf[i][j] = 1 + suf[i + 1][j + 1];

                // Characters don't match
                else
                    suf[i][j] = max(suf[i + 1][j], suf[i][j + 1]);
            }
        }

        int answer = 0;

        // ==========================================================
        // Try every possible insertion position.
        //
        // gap = 0  -> insert before first character
        // gap = n1 -> insert after last character
        // ==========================================================
        for (int gap = 0; gap <= n1; gap++) {

            // Try inserting every lowercase letter.
            for (char ch = 'a'; ch <= 'z'; ch++) {

                bool possible = false;

                // Match the inserted character with every occurrence
                // of the same character in s2.
                for (int j = 0; j < n2; j++) {

                    // Skip if characters don't match.
                    if (s2[j] != ch)
                        continue;

                    // LCS contributed by the part before insertion.
                    int left = pref[gap][j];

                    // LCS contributed by the remaining suffix after
                    // matching the inserted character with s2[j].
                    int right = suf[gap][j + 1];

                    // Total LCS after inserting this character:
                    //
                    // left part
                    // + inserted character
                    // + right part
                    //
                    // We only count it if the LCS increases by exactly 1.
                    if (left + 1 + right == originalLCS + 1) {
                        possible = true;
                        break; // Count each (gap, character) only once.
                    }
                }

                // This insertion (gap, character) is valid.
                if (possible)
                    answer++;
            }
        }

        return answer;
    }
};