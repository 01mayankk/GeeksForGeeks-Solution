class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        
        // Hash set to store visited numbers
        unordered_set<long long> seen;
        
        for (long long num : arr) {
            
            // Special handling when target is 0
            if (target == 0) {
                
                // If current number is 0,
                // then any previous element can form product 0
                if (num == 0) {
                    return true;
                }
            }
            else {
                
                // For non-zero target:
                // target must be divisible by current number
                if (num != 0 && target % num == 0) {
                    
                    long long needed = target / num;
                    
                    // Check if required pair already exists
                    if (seen.count(needed)) {
                        return true;
                    }
                }
            }
            
            // Store current number
            seen.insert(num);
        }
        
        // No valid pair found
        return false;
    }
};