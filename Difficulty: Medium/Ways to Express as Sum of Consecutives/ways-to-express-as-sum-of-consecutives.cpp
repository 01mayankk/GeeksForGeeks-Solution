class Solution {
public:
    int getCount(int n) {
        int count = 0;
        
        // Loop for the number of consecutive terms 'k' starting from 2
        // because we need 2 or more consecutive natural numbers.
        // The minimum sum of k consecutive natural numbers is k*(k+1)/2,
        // so we continue while the structural offset k*(k-1)/2 is strictly less than n.
        for (long long k = 2; (k * (k - 1)) / 2 < n; ++k) {
            // Remaining sum after subtracting the arithmetic progression offset
            long long remaining_sum = n - (k * (k - 1)) / 2;
            
            // If the remaining sum is perfectly divisible by k,
            // it means a valid starting natural number 'a' exists.
            if (remaining_sum % k == 0) {
                count++;
            }
        }
        
        return count;
    }
};