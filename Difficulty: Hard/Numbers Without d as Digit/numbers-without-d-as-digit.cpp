class Solution {
      int memo[12][2][2];
      string s;
      int forbidden;

      int solve(int pos, int tight, int leading_zero) {
          if (pos == s.length()) {
              return leading_zero ? 0 : 1; 
          }

          if (memo[pos][tight][leading_zero] != -1) {
              return memo[pos][tight][leading_zero];
          }

          int limit = tight ? (s[pos] - '0') : 9;
          int ans = 0;

          for (int digit = 0; digit <= limit; digit++) {
              if (digit == forbidden) {
                  if (digit == 0 && leading_zero) {
                      // Valid leading zero, proceed
                  } else {
                      continue; 
                  }
              }

              int next_tight = tight && (digit == limit);
              int next_leading_zero = leading_zero && (digit == 0);

              ans += solve(pos + 1, next_tight, next_leading_zero);
          }

          return memo[pos][tight][leading_zero] = ans;
      }

  public:
      int countWithout(int n, int d) {
          s = to_string(n);
          forbidden = d;

          for (int i = 0; i < 12; i++) {
              for (int j = 0; j < 2; j++) {
                  for (int k = 0; k < 2; k++) {
                      memo[i][j][k] = -1;
                  }
              }
          }

          return solve(0, 1, 1);
      }
  };