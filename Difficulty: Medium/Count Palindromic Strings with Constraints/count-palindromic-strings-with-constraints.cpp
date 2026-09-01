class Solution {
  public:
      int palindromicStrings(int n, int k) {
          long long total_ways = 0;
          long long MOD = 1e9 + 7;

          // Iterate over all possible lengths from 1 to n
          for (int L = 1; L <= n; ++L) {
              int m = L / 2; // Number of characters in the first half
              long long current_ways = 1;

              // If length is even (2m), we need m distinct characters.
              // If length is odd (2m+1), we need m+1 distinct characters (m for half, 1 for center).
              int distinct_chars_needed = (L % 2 == 0) ? m : (m + 1);

              // If we need more distinct characters than k, no such string can be formed
              if (distinct_chars_needed > k) {
                  continue; 
              }

              // Calculate Permutations P(k, distinct_chars_needed)
              for (int i = 0; i < distinct_chars_needed; ++i) {
                  current_ways = (current_ways * (k - i)) % MOD;
              }

              // Add valid strings for this length to the total
              total_ways = (total_ways + current_ways) % MOD;
          }

          return total_ways;
      }
  };