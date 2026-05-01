class Solution {
  public:
    int findPosition(int n) {
        // Step 1: If n is 0, no set bits
        if (n == 0) return -1;
        
        // Step 2: Check if n has exactly one set bit
        // If not, return -1
        if ((n & (n - 1)) != 0) return -1;
        
        // Step 3: Find position of the set bit
        int position = 1; // position starts from 1 (LSB)
        
        while (n > 0) {
            // If LSB is 1, return position
            if (n & 1) {
                return position;
            }
            
            // Right shift to check next bit
            n = n >> 1;
            position++;
        }
        
        return -1; // safety (though not needed)
    }
};