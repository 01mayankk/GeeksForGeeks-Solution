class Solution {
  public:
//   int countSetBits(int n) { // (failed at 10th case TLE as TC : o(n log n ))
//         int sum = 0;
//         for (int i = 1; i <= n; i++) {
//             sum += __builtin_popcount(i); // counts set bits in i
//         }
        
//         return sum; 
//     }
    
//     int countSetBits(int n) { //(failed at 10th case TLE as TC : o(log (n!) ≈ O(n log n)))
//     int sum = 0;           // Initialize sum of set bits to 0

//     // Loop through all numbers from 1 to n
//     for (int i = 1; i <= n; i++) {
//         int x = i;         // Copy the current number i into x

//         // Count set bits in x
//         while (x) {        // Continue until x becomes 0
//             sum += x & 1;  // Add 1 to sum if the last bit of x is set (1)
//                             // x & 1 → gives the last bit of x
//             x >>= 1;       // Right shift x by 1 to process the next bit
//                             // Effectively divides x by 2
//         }
//     }

//     return sum;            // Return the total count of set bits from 1 to n
// }






    // int countSetBits(int n) { //  (failed at 10th case TLE as TC : o(n )) fast for small input value
    //     int sum = 0;
    //     for (int i = 1; i <= n; i++) {
    //         bitset<32> b(i);  // convert i to bitset
    //         sum += b.count();      // count set bits
    //     }
    //     return sum;
    // }
    
    
    int countSetBits(int n) {
    int count = 0;

    // Iterate over each bit position
    for (int i = 0; (1 << i) <= n; i++) {
        int cycleLength = 1 << (i + 1);            // Length of one full cycle at this bit
        int fullCycles = (n + 1) / cycleLength;    // Number of complete cycles
        count += fullCycles * (1 << i);            // Set bits from full cycles

        int remainder = (n + 1) % cycleLength;     // Remaining numbers after full cycles
        count += max(0, remainder - (1 << i));     // Extra set bits in remainder
    }

    return count;
}



};
