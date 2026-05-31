class Solution {
public:
    bool isSumOfConsecutive(int n) {
        
        // Numbers less than 3 cannot be expressed
        // as sum of two or more positive consecutive numbers
        if (n < 3)
            return false;

        // If n is a power of 2, return false.
        // Otherwise, return true.
        return (n & (n - 1)) != 0;
    }
};