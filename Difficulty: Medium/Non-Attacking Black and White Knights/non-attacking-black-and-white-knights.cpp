class Solution {
public:
    long long numOfWays(int n, int m) {

        // Total number of squares on the chessboard
        long long cells = 1LL * n * m;

        // ----------------------------------------------------
        // Total ways to place:
        // 1 Black Knight and 1 White Knight
        //
        // Since the knights are different (black != white),
        // order matters.
        //
        // Choose a square for Black Knight  -> cells choices
        // Choose a different square for White Knight
        //                                  -> (cells - 1) choices
        //
        // Total placements = cells * (cells - 1)
        // ----------------------------------------------------
        long long totalWays = cells * (cells - 1);

        // Stores number of placements where
        // the two knights can attack each other
        long long attackingWays = 0;

        // ----------------------------------------------------
        // A knight attacks only in an L-shape:
        // (2 rows, 1 column) OR (1 row, 2 columns)
        //
        // Such attacks occur inside a 2×3 or 3×2 rectangle.
        //
        // In every 2×3 rectangle:
        // there are exactly 2 attacking knight pairs.
        //
        // Since knights are colored (black and white),
        // each attacking pair can be arranged in 2 ways:
        // (Black, White) and (White, Black)
        //
        // Therefore:
        // Each valid rectangle contributes
        // 2 × 2 = 4 attacking arrangements.
        // ----------------------------------------------------

        // Count all possible 2×3 rectangles
        if (n >= 2 && m >= 3) {
            long long rectangles2x3 = 1LL * (n - 1) * (m - 2);

            // Each rectangle contributes 4 attacking arrangements
            attackingWays += 4LL * rectangles2x3;
        }

        // Count all possible 3×2 rectangles
        if (n >= 3 && m >= 2) {
            long long rectangles3x2 = 1LL * (n - 2) * (m - 1);

            // Each rectangle contributes 4 attacking arrangements
            attackingWays += 4LL * rectangles3x2;
        }

        // ----------------------------------------------------
        // Required answer:
        //
        // Total placements
        //      -
        // Attacking placements
        // ----------------------------------------------------
        return totalWays - attackingWays;
    }
};