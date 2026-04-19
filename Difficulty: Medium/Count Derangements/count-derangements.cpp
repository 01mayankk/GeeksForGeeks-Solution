class Solution {
  public:
    int derangeCount(int n) {
        // Base case:
        // For 1 element, no derangement possible
        if (n == 1) return 0;

        // For 2 elements, only one derangement: [2, 1]
        if (n == 2) return 1;

        // prev2 represents D(1) = 0
        int prev2 = 0;

        // prev1 represents D(2) = 1
        int prev1 = 1;

        // Loop from 3 to n to compute derangements iteratively
        for (int i = 3; i <= n; i++) {
            
            // Using recurrence relation:
            // D(n) = (n - 1) * (D(n-1) + D(n-2))
            int curr = (i - 1) * (prev1 + prev2);

            // Update values for next iteration:
            // prev2 becomes old prev1 (D(n-1))
            prev2 = prev1;

            // prev1 becomes current result (D(n))
            prev1 = curr;
        }

        // Final answer stored in prev1 (i.e., D(n))
        return prev1;
    }
};