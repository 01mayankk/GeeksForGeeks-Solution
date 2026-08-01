class Solution {
public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // Create a difference array of size n + 1 initialized to 0.
        // The +1 prevents out-of-bounds access when doing b[i] + 1.
        vector<long long> diff(n + 1, 0);
        
        // Apply the difference array technique for each range operation.
        for (size_t i = 0; i < a.size(); ++i) {
            diff[a[i]] += k[i];         // Add k[i] at the start index a[i]
            diff[b[i] + 1] -= k[i];     // Subtract k[i] at the index right after the end b[i] + 1
        }
        
        long long max_val = 0;
        long long current_val = 0;
        
        // Compute the prefix sum to get the actual array values after all operations.
        // Keep track of the maximum value encountered.
        for (int i = 0; i < n; ++i) {
            current_val += diff[i];
            if (current_val > max_val) {
                max_val = current_val;
            }
        }
        
        // Return the maximum value, casted to int to match the function signature.
        return static_cast<int>(max_val);
    }
};