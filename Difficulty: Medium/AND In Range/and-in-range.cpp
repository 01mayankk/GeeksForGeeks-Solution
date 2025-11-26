// class Solution {
//   public:
//     int andInRange(int l, int r) {
        
//         long long result = l;    // Initialize result with starting number 'l'

//         /*
//             We AND every number from l to r:
//             result = l & (l+1) & (l+2) & ... & r

//             This works logically but is EXTREMELY SLOW for large ranges.
//         */
//         for(int i = l + 1; i <= r; i++)   // Loop runs from l+1 to r
//         {
//             result &= i;   // Bitwise AND with each number in the range
//         }

//         /*
//             ❗ Why this gives TLE (Time Limit Exceeded)?

//             Worst case: l = 1, r = 10^9  (1 billion)

//             The loop will run (r - l) times = ~1,000,000,000 iterations

//             No system can perform 1 billion bitwise AND operations
//             within allowed time on competitive programming platforms.

//             Expected time complexity = O(r - l)  → Up to 10^9 operations ❌
//             This exceeds time limit → TLE
//         */
        
//         return result;           // Return the final AND value
//     }
// };

class Solution{
  public:
    int andInRange(int l, int r){
        
        int shift = 0;   
        /* 
           shift = number of times we right shift l and r
           until both numbers become the same.
           This is required because AND over a range removes
           all bits that differ between ANY two numbers in that range.
        */

        // Keep shifting right until l and r become equal
        while(l < r) {
            /*
                Why right shift?
                Because if l and r differ at some bit-position,
                then AND of the whole range will remove all bits
                after this mismatch and make them 0.

                Example:
                l =  1000   (8)
                r =  1101  (13)
                They differ at bit-positions, so we keep shifting:
                
                Step 1 → l=1000(8)→100, r=1101(13)→110 → not equal
                Step 2 → l=100(4)→10 , r=110(6)→11  → not equal
                Step 3 → l=10(2)→1  , r=11(3)→1   → equal!
                
                Now both are equal → common prefix found.
                
                Every shift removed one bit from the right, so
                we count how many times by increasing 'shift'.
            */
            l >>= 1;    // Right shift l by 1 (divide by 2)
            r >>= 1;    // Right shift r by 1 (divide by 2)
            shift++;    // Count how many shifts we do
        }

        /*
            When l == r, we found the COMMON PREFIX bits.

            Now we left shift back to rebuild the number
            while keeping all variable bits as zero.

            l << shift  means we attach 'shift' number of zeros
            at the end of the binary prefix.

            Example continuation:
            Final prefix = 1, shift = 3
            Result = 1 << 3 = 1000 (binary) = 8
        */
        return l << shift;  // Return the AND for range [original_l, original_r]
    }
};
