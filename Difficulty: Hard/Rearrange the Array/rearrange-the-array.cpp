class Solution {
public:
    int minOperations(vector<int>& b) {
        int n = b.size();
        vector<bool> visited(n + 1, false);
        vector<int> max_pow(n + 1, 0);
        long long MOD = 1e9 + 7;

        // Find the length of each independent cycle in the permutation
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                int len = 0;
                int curr = i;
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = b[curr - 1]; // Convert 1-based indexing to 0-based
                    len++;
                }
                
                // Find prime factorization of the cycle length to calculate LCM later
                int temp = len;
                for (int p = 2; p * p <= temp; ++p) {
                    if (temp % p == 0) {
                        int count = 0;
                        while (temp % p == 0) {
                            count++;
                            temp /= p;
                        }
                        // Track the maximum power of prime p required
                        max_pow[p] = max(max_pow[p], count);
                    }
                }
                if (temp > 1) {
                    max_pow[temp] = max(max_pow[temp], 1);
                }
            }
        }

        // Compute the LCM modulo 10^9 + 7 using the accumulated highest powers of primes
        long long ans = 1;
        for (int p = 2; p <= n; ++p) {
            for (int i = 0; i < max_pow[p]; ++i) {
                ans = (ans * p) % MOD;
            }
        }

        return ans;
    }
};