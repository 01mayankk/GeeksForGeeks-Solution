// class Solution { //This will also work but the TC is O(n log n) and it will be slow 
    //for value like 10^9 so switch to next approach of bit manupulation and maths logic 
    //which will do the same problem in O(log n)
// public:
//     int countSetBits(int n) {

//         long sum = 0, bit;

//         // Loop from 1 to n (inclusive)
//         // For every number, count how many bits are set (1s)
//         for(int i = 1; i <= n; i++) 
//         {
//             bit = i;                             // take current number
            
//             bitset<64> bits(bit);                // convert number to 64-bit binary representation
            
//             sum += bits.count();                 // count() returns number of 1-bits and add to answer
//         }
        
//         return sum;   // return total number of set bits from 1 to n
//     }
// };


class Solution {
public:
    int countSetBits(int n) { // This logic will run in O(log n)
        // 'count' will store the total number of set bits (1s)
        // in binary representations of all numbers from 1 to n.
        long long count = 0;

        // 'powerOf2' represents the current bit position as a value: 1, 2, 4, 8, ...
        // i.e., 2^0, 2^1, 2^2, ...
        long long powerOf2 = 1;

        // We will consider each bit position one-by-one
        // while 2^i <= n. Beyond that, higher bits are always 0 for all numbers ≤ n.
        while (powerOf2 <= n) {

            // For a given bit position 'powerOf2', the pattern of bits (0s and 1s)
            // repeats every 'cycleLength = 2 * powerOf2'.
            //
            // Example for powerOf2 = 2 (i.e., bit 1, value = 2):
            // Numbers:  0 1 2 3 4 5 6 7 ...
            // Bit(1):   0 0 1 1 0 0 1 1 ...
            // Pattern length = 4 (2 * 2)
            //
            // In each such pattern:
            //   - first 'powerOf2' numbers → bit is 0
            //   - next  'powerOf2' numbers → bit is 1

            long long cycleLength = powerOf2 * 2;

            // 'n + 1' because we are counting from 0 to n (inclusive),
            // total of (n + 1) numbers.
            //
            // 'totalPairs' = how many full cycles (each of size 'cycleLength')
            // completely fit in range [0, n].
            //
            // Every full cycle contributes exactly 'powerOf2' times where
            // this bit is set to 1.
            long long totalPairs = (n + 1) / cycleLength;

            // Each full cycle has 'powerOf2' ones for this bit position.
            // So contribution from all full cycles is:
            //   totalPairs * powerOf2
            count += totalPairs * powerOf2;

            // Now handle the leftover part after all complete cycles.
            //
            // 'remainder' = how many extra numbers are there after these full cycles.
            // These are the numbers in the partial (incomplete) cycle.
            long long remainder = (n + 1) % cycleLength;

            // In each cycle, the bit is set to 1 only in the second half:
            //   - first  'powerOf2' numbers  → bit = 0
            //   - next   'powerOf2' numbers  → bit = 1
            //
            // So in the leftover part, if 'remainder' is larger than 'powerOf2',
            // then the amount above 'powerOf2' in this remainder corresponds
            // to how many numbers have this bit = 1 in the partial cycle.
            //
            // Example:
            //   powerOf2 = 2, cycleLength = 4
            //   pattern of bit: [0,0,1,1]
            //
            //   If remainder = 1 → [0]              → 0 ones
            //   If remainder = 2 → [0,0]            → 0 ones
            //   If remainder = 3 → [0,0,1]          → 1 one
            //   If remainder = 4 → [0,0,1,1]        → 2 ones
            //
            //   Formula: max(0, remainder - powerOf2)
            //   - when remainder <= powerOf2 → no ones in this bit
            //   - when remainder >  powerOf2 → (remainder - powerOf2) ones
            long long extraOnes = remainder - powerOf2;

            // Only add if positive; otherwise, this bit didn't have any 1s
            // in the leftover part.
            if (extraOnes > 0) {
                count += extraOnes;
            }

            // Move to the next bit position:
            // powerOf2 = 1, 2, 4, 8, 16, ...
            powerOf2 <<= 1;  // same as powerOf2 *= 2
        }

        // 'count' now contains the total number of set bits in all numbers from 1 to n.
        return (int)count;
    }
};
