class Solution {
  public:
    // Function to check if a number is a power of two
    bool isPowerofTwo(int n) {
        // Step 1: Ensure n is positive
        // Powers of 2 must be > 0 (0 or negative numbers are not powers of 2)
        if (n <= 0) return false;

        // Step 2: Bitwise check - A number n is a power of two if it has exactly one set bit in binary.
        // Example: 
        // 2  => 10
        // 4  => 100
        // 8  => 1000
        // All have only one bit set

        // (n & (n - 1)) will be 0 only for powers of 2
        // Why? Let's see an example:
        // n = 8 (1000 in binary)
        // n - 1 = 7 (0111 in binary)
        // n & (n - 1) = 1000 & 0111 = 0000 → So, 8 is a power of 2

        // For a number that is not a power of 2:
        // n = 10 (1010), n - 1 = 9 (1001)
        // n & (n - 1) = 1010 & 1001 = 1000 ≠ 0 → So, 10 is not a power of 2

        return (n & (n - 1)) == 0;
    }
};
