class Solution {
  public:
    int reverseExponentiation(int n) {
        // code here
        
        int rev = 0;
        
        int copy = n;
        
        while(copy > 0)
        {
            int digit = copy % 10;
            rev = rev * 10 + digit;
            copy /= 10;
        }
        
        return pow(n, rev);
    }
};