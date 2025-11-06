// class Solution { // it will work but may fail for large value due to precision
//   public:
//     int nthRoot(int n, int m) {
//         // Handle edge case: when m is 0, the nth root of 0 is always 0
//         if (m == 0) {
//             return 0;
//         }

//         // Handle edge case: any number's 1st root is the number itself
//         if (n == 1) {
//             return m;
//         }

//         // Use logarithmic formula to compute nth root:
//         // nth root of m = e^( (log(m)) / n )
//         // log(m) gives natural log (base e), exp(x) gives e^x
//         double x = exp(log(m) / n);

//         // Round the floating-point result to the nearest integer
//         int root = round(x);

//         // Verify if the rounded integer root actually satisfies root^n = m
//         // (This check ensures we only return exact integer roots)
//         if (pow(root, n) == m) {
//             return root;
//         }

//         // If no integer root found, return -1 as per problem statement
//         return -1;
//     }
// };


class Solution {
  public:
    // Helper function to calculate mid^n safely (to avoid overflow)
    long long power(long long mid, int n) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= mid; // multiply 'mid' by itself n times
            
            // If at any point ans exceeds 1e9 (i.e., 10^9), 
            // we can stop early since m ≤ 10^9 (given in constraints)
            // Returning 1e10 ensures it’s always greater than m
            if (ans > 1e9) return 1e10; 
        }
        return ans; // return the computed mid^n value
    }

    int nthRoot(int n, int m) {
        // Edge case: nth root of 0 is always 0
        if (m == 0) return 0;

        // Edge case: 1st root of any number is the number itself
        if (n == 1) return m;

        // Initialize binary search range
        int low = 1, high = m;

        while (low <= high) {
            int mid = (low + high) / 2;   // middle value of current range
            long long val = power(mid, n); // compute mid^n

            if (val == m) 
                return mid;                // ✅ Found exact nth root

            else if (val < m) 
                low = mid + 1;             // mid^n is too small → go higher

            else 
                high = mid - 1;            // mid^n is too large → go lower
        }

        // If loop finishes, no integer root satisfies mid^n = m
        return -1;
    }
};
