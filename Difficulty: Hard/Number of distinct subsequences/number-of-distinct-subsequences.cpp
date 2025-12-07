class Solution {
  public:
    int distinctSubseq(string &s) {
        // code here
        const long long MOD = 1000000007;
        int n = s.size();

        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // empty subsequence

        vector<int> last(26, -1); // last occurrence of each char

        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';

            // double the count
            dp[i] = (2 * dp[i - 1]) % MOD;

            // if seen earlier, subtract duplicate contribution
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }

            // update last seen index
            last[c] = i;
        }

        return dp[n];
    }
};