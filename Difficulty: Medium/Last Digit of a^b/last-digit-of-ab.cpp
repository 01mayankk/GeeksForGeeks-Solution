class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        
        // Special case:
        // Any number raised to power 0 is 1
        if (b == "0")
            return 1;
        
        // We only need the last digit of a
        int lastDigit = a.back() - '0';
        
        // Find b % 4 because last digits repeat in cycles of at most 4
        int exponentMod4 = 0;
        for (char ch : b) {
            exponentMod4 = (exponentMod4 * 10 + (ch - '0')) % 4;
        }
        
        // If remainder is 0, use 4 instead
        // because cycle length is 4
        if (exponentMod4 == 0)
            exponentMod4 = 4;
        
        // Compute (lastDigit ^ exponentMod4) % 10
        int result = 1;
        for (int i = 0; i < exponentMod4; i++) {
            result = (result * lastDigit) % 10;
        }
        
        return result;
    }
};