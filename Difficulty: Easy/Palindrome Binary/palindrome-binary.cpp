class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        
        // Step 1: Store binary representation (without leading zeros)
        vector<int> bits;
        
        while (n > 0) {
            bits.push_back(n % 2); // extract last bit
            n = n / 2;            // shift right
        }
        
        // Step 2: Check palindrome using two pointers
        int left = 0;
        int right = bits.size() - 1;
        
        while (left < right) {
            if (bits[left] != bits[right]) {
                return false; // mismatch found
            }
            left++;
            right--;
        }
        
        return true; // all matched
    }
};