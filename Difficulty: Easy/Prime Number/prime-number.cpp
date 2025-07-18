class Solution {
  public:
    bool isPrime(int n) {
        // code here
        
        for(int i = 2; i * i <= n ; i++) // here i * i means we are squaring th no i 
                                        //to check whether it is factor of n or not
        {
            if(n % i == 0)
            {
                return false;
            }
        }
        if(n == 1)
        {
            return false;
        }
        
        return true;
    }
};
