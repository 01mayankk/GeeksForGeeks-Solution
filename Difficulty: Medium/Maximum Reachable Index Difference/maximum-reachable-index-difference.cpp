class Solution {
public:
    int maxIndexDifference(string &s) {
        int n = s.size();

        // dp[i] = farthest index reachable starting from index i
        vector<int> dp(n);

        // bestReach[c] = maximum reachable ending index among all
        // processed occurrences of character ('a' + c)
        vector<int> bestReach(26, -1);

        int ans = -1;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            int ch = s[i] - 'a';

            // If current character is 'z', no next alphabet exists
            if (ch == 25) {
                dp[i] = i;
            }
            // If there is a reachable occurrence of the next character
            else if (bestReach[ch + 1] != -1) {
                dp[i] = bestReach[ch + 1];
            }
            // Otherwise, jump cannot continue
            else {
                dp[i] = i;
            }

            // Update the best reachable index for this character
            bestReach[ch] = max(bestReach[ch], dp[i]);

            // Every 'a' can be a starting position
            if (ch == 0) {
                ans = max(ans, dp[i] - i);
            }
        }

        return ans;
    }
};