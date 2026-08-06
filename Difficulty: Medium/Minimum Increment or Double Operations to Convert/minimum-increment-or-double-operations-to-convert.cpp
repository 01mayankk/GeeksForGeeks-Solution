class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int max_doubles = 0;
        int total_increments = 0;
        
        for (int num : arr) {
            int current_doubles = 0;
            
            // Process each number to count required increments and doublings
            while (num > 0) {
                // If the number is odd, it requires an increment operation
                if (num % 2 == 1) {
                    total_increments++;
                }
                
                num /= 2; // Simulate the doubling operation in reverse (halving)
                
                // If the number is still greater than 0, it needed a doubling operation
                if (num > 0) {
                    current_doubles++;
                }
            }
            
            // Track the maximum number of doubling operations needed by any single element
            // because doubling affects the entire array simultaneously
            max_doubles = max(max_doubles, current_doubles);
        }
        
        // Total operations is the sum of all individual increments plus the maximum doublings
        return total_increments + max_doubles;
    }
};