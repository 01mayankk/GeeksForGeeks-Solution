class Solution {
  public:
    bool isPower(int x, int y) {
        
        // Edge case: if x == 1
        // Only possible power is 1^k = 1
        if (x == 1) {
            return (y == 1);
        }
        
        // Keep dividing y by x while divisible
        while (y % x == 0) {
            y = y / x;
        }
        
        // If after division y becomes 1, it is a power
        return (y == 1);
    }
};