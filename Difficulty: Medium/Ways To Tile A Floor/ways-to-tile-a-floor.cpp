class Solution {
  public:
    int numberOfWays(int n) {
        // Base cases:
        // If the floor width is 1, we can only place one vertical tile (1 way)
        // If the floor width is 2, we can either place two vertical tiles
        // or two horizontal tiles (2 ways)
        if (n <= 2) return n;

        // prev2 = f(1), number of ways to tile 2 x 1 floor
        int prev2 = 1;

        // prev1 = f(2), number of ways to tile 2 x 2 floor
        int prev1 = 2;

        int curr;  // To store current number of ways (f(i))

        // Using bottom-up dynamic programming (iterative Fibonacci)
        for (int i = 3; i <= n; i++) {
            // Recurrence relation:
            // f(n) = f(n - 1) + f(n - 2)
            // (either place one vertical tile or two horizontal tiles)
            curr = prev1 + prev2;

            // Move the window forward for next iteration
            prev2 = prev1;
            prev1 = curr;
        }

        // Return the final computed number of ways for 2 x n floor
        return curr;
    }
};
