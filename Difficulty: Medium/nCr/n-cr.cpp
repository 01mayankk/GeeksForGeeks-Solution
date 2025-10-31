// class Solution {
//   public:
//     int nCr(int n, int r) { // This will give TLE as immediate calcultion will led 
//     //to overflow for larger value as the value will grow exponentially
//         // Variables to store the numerator and denominator parts of the formula
//         // Formula: nCr = n! / (r! * (n - r)!)
//         int numerator = 1, denominator = 1;

//         // If r > n, it is not possible to choose r items from n items
//         if (r > n) {
//             return 0;
//         }
//         // If r == n, then nCr = 1 (since nC n = 1)
//         else if (r == n) {
//             return 1;
//         }
//         else {
//             // Make a copy of r so that we can use it for counting loops
//             int copy = r;
            
//             // 🔹 Compute the numerator part: n * (n - 1) * (n - 2) * ... up to r terms
//             // This effectively calculates n * (n-1) * ... * (n - r + 1)
//             while (copy > 0) {
//                 numerator *= n;  // multiply with current n
//                 n--;              // decrement n
//                 copy--;           // decrease loop counter
//             }
            
//             // Reset copy to r to reuse in denominator calculation
//             copy = r;
            
//             // 🔹 Compute the denominator part: r!
//             // This multiplies all numbers from r down to 1
//             while (copy > 0) {
//                 denominator *= r;  // multiply with current r
//                 r--;                // decrement r
//                 copy--;             // decrease loop counter
//             }
//         }
        
//         // 🔹 Finally, divide numerator by denominator to get nCr
//         // NOTE: This approach can cause overflow for large n or r values.
//         return numerator / denominator;
//     }
// };



class Solution { // Optimal and will be safer, don't overflow
  public:
    int nCr(int n, int r) {
        // If r is greater than n, choosing r items from n is not possible.
        if (r > n) 
            return 0;

        // Base cases:
        // 1. nC0 = 1 → There’s only one way to choose 0 elements.
        // 2. nCn = 1 → There’s only one way to choose all elements.
        if (r == 0 || r == n) 
            return 1;

        // Property of combinations:
        // C(n, r) = C(n, n - r)
        // Because choosing r items out of n is same as leaving out (n - r) items.
        // This optimization reduces the number of loop iterations for efficiency.
        if (r > n - r)
            r = n - r;

        // Use long long to safely store intermediate values
        long long result = 1;

        // Step-by-step computation of the formula:
        // C(n, r) = n! / (r! * (n - r)!)
        //
        // Instead of calculating factorials (which are large),
        // we compute it iteratively as:
        //
        // result = 1
        // For i from 0 to r-1:
        //     result = result * (n - i) / (i + 1)
        //
        // This form ensures that we divide at each step,
        // keeping intermediate results small and preventing overflow.
        for (int i = 0; i < r; i++) {
            result = result * (n - i);   // Multiply by current numerator term
            result = result / (i + 1);   // Divide by current denominator term
        }

        // The problem guarantees that final result fits in 32-bit integer range.
        return (int)result;
    }
};
