class Solution {
  public:
    bool isBitSet(int n) {
        // If number is 0, return false
        // because no bits are set
        if(n == 0)
            return false;

        // A number has all bits set if it is of form:
        // 1, 3, 7, 15, 31 ...
        // i.e. n & (n + 1) should be 0
        
        return (n & (n + 1)) == 0;
    }
};