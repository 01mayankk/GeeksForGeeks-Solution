class Solution {
public:
    int countSubsets(vector<int>& arr) {
        int MOD = 1e9 + 7;
        // The 10 prime numbers up to 30
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        // mask_of[i] will store the bitmask of prime factors for number i.
        // It will be -1 if the number contains repeated prime factors.
        vector<int> mask_of(31, -1);
        
        // Precompute prime factorization masks for all numbers from 2 to 30
        for (int i = 2; i <= 30; ++i) {
            int temp = i;
            int mask = 0;
            bool is_valid = true;
            for (int j = 0; j < 10; ++j) {
                // If primes[j] divides temp, include it in the mask
                if (temp % primes[j] == 0) {
                    mask |= (1 << j);
                    temp /= primes[j];
                    // If it divides again, the number is not valid (repeated prime)
                    if (temp % primes[j] == 0) {
                        is_valid = false;
                        break;
                    }
                }
            }
            if (is_valid) {
                mask_of[i] = mask;
            }
        }
        
        long long ones_count = 0;
        vector<long long> freq(31, 0);
        
        // Count frequencies of 1s and other valid square-free numbers
        for (int num : arr) {
            if (num == 1) {
                ones_count++;
            } else if (mask_of[num] != -1) {
                freq[num]++;
            }
        }
        
        // dp[mask] stores the number of valid subsets whose product's 
        // prime factors are represented by the bitmask 'mask'.
        vector<long long> dp(1024, 0);
        dp[0] = 1; // The base case: empty subset product evaluates to mask 0
        
        // Iterate over all possible valid numbers from 2 to 30
        for (int i = 2; i <= 30; ++i) {
            if (freq[i] > 0 && mask_of[i] != -1) {
                int m = mask_of[i];
                // Traverse DP table backwards for 0-1 knapsack transition
                for (int mask = 1023; mask >= 0; --mask) {
                    // Check if there are no intersecting prime factors
                    if ((mask & m) == 0) {
                        dp[mask | m] = (dp[mask | m] + dp[mask] * freq[i]) % MOD;
                    }
                }
            }
        }
        
        long long total_subsets = 0;
        // Sum up all subsets that have at least one prime factor (mask > 0)
        for (int mask = 1; mask < 1024; ++mask) {
            total_subsets = (total_subsets + dp[mask]) % MOD;
        }
        
        // Any valid configuration can be combined with any subset of 1s
        long long power_of_2 = 1;
        for (int i = 0; i < ones_count; ++i) {
            power_of_2 = (power_of_2 * 2) % MOD;
        }
        
        return (total_subsets * power_of_2) % MOD;
    }
};