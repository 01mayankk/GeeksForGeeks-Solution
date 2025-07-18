class Solution {
  public:
    int findSum(int n) {
        // code here
        int sum = 0;
        if(n == 0 )
        {
            return 0;
        }
        else
        {
            sum = n * (n + 1 ) / 2;
        }
        
        return sum;
    }
};
