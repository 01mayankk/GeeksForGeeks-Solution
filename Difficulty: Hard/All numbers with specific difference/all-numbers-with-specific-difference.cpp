class Solution {
  public:
    
    // Function to calculate the sum of digits of a number
    long long digitSum(long long x) {
        long long sum = 0;
        
        // Extract digits one by one
        while(x > 0) {
            sum += x % 10;   // Add last digit
            x /= 10;         // Remove last digit
        }
        
        return sum;  // Return total digit sum
    }
    
    int getCount(int n, int d) {
        
        long long count = 0;   // To store final answer
        
        /*
        IMPORTANT OBSERVATION:
        
        For any number <= 10^9,
        maximum possible digit sum = 9 * 9 = 81
        
        So if x >= d + 81,
        then x - digitSum(x) will ALWAYS be >= d
        
        That means:
        We only need to check manually till (d + 81)
        After that we can directly count.
        */
        
        // We only check upto min(n, d+81)
        long long limit = min((long long)n, (long long)d + 81);
        
        // Check each number from d to limit
        for(long long i = d; i <= limit; i++) {
            
            // If condition satisfies
            if(i - digitSum(i) >= d)
                count++;   // Increase answer
        }
        
        /*
        Now for numbers greater than (d + 81),
        all will satisfy condition.
        
        So we just add them directly.
        */
        if(n > d + 81)
            count += (n - (d + 81));
        
        return count;   // Return total count
    }
};
