class Solution {
public:
    static const int MOD = 1e9 + 7;

    // Function to calculate (base^exp) % MOD using Binary Exponentiation
    long long power(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {

            // If current bit of exponent is set,
            // multiply result with current base
            if (exp & 1)
                result = (result * base) % MOD;

            // Square the base for next bit
            base = (base * base) % MOD;

            // Move to next bit of exponent
            exp >>= 1;
        }

        return result;
    }

    int computeValue(int n) {

        // We need to calculate C(2n, n)
        int N = 2 * n;

        // fact[i] stores i! % MOD
        vector<long long> fact(N + 1);
        fact[0] = 1;

        // Precompute factorials
        for (int i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // invFact[i] stores modular inverse of fact[i]
        vector<long long> invFact(N + 1);

        // Compute inverse factorial of N! using Fermat's theorem
        // invFact[N] = (fact[N])^(MOD-2) % MOD
        invFact[N] = power(fact[N], MOD - 2);

        // Compute remaining inverse factorials
        for (int i = N - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }

        /*
            Using identity:

            Sum(C(n,k)^2) for k = 0 to n = C(2n,n)

            Therefore answer = C(2n,n)

            C(2n,n) = (2n)! / (n! * n!)
        */

        long long ans = fact[N];

        // Divide by first n! using modular inverse
        ans = (ans * invFact[n]) % MOD;

        // Divide by second n! using modular inverse
        ans = (ans * invFact[n]) % MOD;

        return (int)ans;
    }
};