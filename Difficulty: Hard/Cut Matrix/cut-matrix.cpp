#include <vector>

using namespace std;

class Solution {
public:
    int findWays(vector<vector<int>>& matrix, int k) {
        // Get the dimensions of the input matrix
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Define the modulo constant as required by the problem to prevent integer overflow
        const int MOD = 1e9 + 7;

        // -------------------------------------------------------------------------------------
        // STEP 1: PRECOMPUTE SUFFIX SUM OF ONES
        // -------------------------------------------------------------------------------------
        // suff[r][c] stores the total number of 1s in the submatrix from top-left (r, c) 
        // to bottom-right (n-1, m-1). We size it to (n+1)x(m+1) to handle out-of-bounds cleanly.
        vector<vector<int>> suff(n + 1, vector<int>(m + 1, 0));
        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                // Using 2D Suffix Sum formula: Current element + Right + Bottom - Bottom-Right
                suff[r][c] = matrix[r][c] + suff[r + 1][c] + suff[r][c + 1] - suff[r + 1][c + 1];
            }
        }

        // -------------------------------------------------------------------------------------
        // STEP 2: PRECOMPUTE FIRST VALID CUT BOUNDARIES
        // -------------------------------------------------------------------------------------
        // i_min[r][c] stores the lowest row index (>= r) where a horizontal cut becomes valid.
        // A cut below row 'i' is valid only if the top piece (from r to i) contains at least one 1.
        vector<vector<int>> i_min(n + 1, vector<int>(m + 1, n));
        
        // j_min[r][c] stores the lowest column index (>= c) where a vertical cut becomes valid.
        // A cut to the right of column 'j' is valid only if the left piece (from c to j) contains at least one 1.
        vector<vector<int>> j_min(n + 1, vector<int>(m + 1, m));

        // Populate i_min by checking if there's an increase in the number of 1s moving down a column
        for (int c = 0; c < m; ++c) {
            for (int r = n - 1; r >= 0; --r) {
                // If suff[r][c] > suff[r+1][c], it means row 'r' contains at least one 1 in columns >= c
                if (suff[r][c] > suff[r + 1][c]) {
                    i_min[r][c] = r;
                } else {
                    // Propagate the closest valid row found from below
                    i_min[r][c] = i_min[r + 1][c];
                }
            }
        }

        // Populate j_min by checking if there's an increase in the number of 1s moving right across a row
        for (int r = 0; r < n; ++r) {
            for (int c = m - 1; c >= 0; --c) {
                // If suff[r][c] > suff[r][c+1], it means column 'c' contains at least one 1 in rows >= r
                if (suff[r][c] > suff[r][c + 1]) {
                    j_min[r][c] = c;
                } else {
                    // Propagate the closest valid column found from the right
                    j_min[r][c] = j_min[r][c + 1];
                }
            }
        }

        // -------------------------------------------------------------------------------------
        // STEP 3: DYNAMIC PROGRAMMING SETUP
        // -------------------------------------------------------------------------------------
        // dp[r][c] stores the number of valid ways to split the remaining suffix submatrix 
        // spanning from (r, c) to (n-1, m-1) into the current number of pieces.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // BASE CASE: For exactly 1 piece remaining (p = 1), no cuts are needed. 
        // Any submatrix from (r, c) that contains at least one 1 represents exactly 1 valid way.
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (suff[r][c] > 0) {
                    dp[r][c] = 1;
                }
            }
        }

        // -------------------------------------------------------------------------------------
        // STEP 4: DP ITERATION FOR PIECES 2 TO K
        // -------------------------------------------------------------------------------------
        for (int p = 2; p <= k; ++p) {
            // next_dp will store the calculation results for the current piece count 'p'
            vector<vector<int>> next_dp(n + 1, vector<int>(m + 1, 0));

            // To avoid an extra O(N) loop during state transitions, we precompute suffix 
            // sums of the previous DP array. This optimizes transitions from O(N) to O(1).
            vector<vector<int>> sum_row(n + 1, vector<int>(m + 1, 0)); // Suffix sums along rows
            vector<vector<int>> sum_col(n + 1, vector<int>(m + 1, 0)); // Suffix sums along columns

            // Compute suffix sums along the rows (bottom-to-top) for horizontal cuts
            for (int c = 0; c < m; ++c) {
                for (int r = n - 1; r >= 0; --r) {
                    sum_row[r][c] = (dp[r][c] + sum_row[r + 1][c]) % MOD;
                }
            }

            // Compute suffix sums along the columns (right-to-left) for vertical cuts
            for (int r = 0; r < n; ++r) {
                for (int c = m - 1; c >= 0; --c) {
                    sum_col[r][c] = (dp[r][c] + sum_col[r][c + 1]) % MOD;
                }
            }

            // Calculate transitions for each submatrix starting position (r, c)
            for (int r = 0; r < n; ++r) {
                for (int c = m - 1; c >= 0; --c) {
                    // If the current submatrix doesn't even have a single 1, it cannot be divided
                    if (suff[r][c] == 0) continue;

                    long long ways = 0;

                    // Option A: Make a HORIZONTAL cut below row 'i'
                    // The cut is valid from the first row that guarantees the top piece has a 1 (first_valid_row)
                    // up to the second-to-last row (n-2) because the bottom piece must have at least one row left.
                    int first_valid_row = i_min[r][c];
                    if (first_valid_row < n - 1) {
                        // Accumulate ways from all remaining bottom pieces: from (first_valid_row + 1) down to (n-1)
                        ways = (ways + sum_row[first_valid_row + 1][c]) % MOD;
                    }

                    // Option B: Make a VERTICAL cut to the right of column 'j'
                    // The cut is valid from the first column that guarantees the left piece has a 1 (first_valid_col)
                    // up to the second-to-last column (m-2) because the right piece must have at least one column left.
                    int first_valid_col = j_min[r][c];
                    if (first_valid_col < m - 1) {
                        // Accumulate ways from all remaining right pieces: from (first_valid_col + 1) out to (m-1)
                        ways = (ways + sum_col[r][first_valid_col + 1]) % MOD;
                    }

                    // Store the aggregated results for the submatrix starting at (r, c)
                    next_dp[r][c] = ways;
                }
            }
            // Move the current layer results to the main DP table for the next iteration (p + 1)
            dp = move(next_dp);
        }

        // Return total valid combinations for the full matrix (0, 0) split into k pieces
        return dp[0][0];
    }
};