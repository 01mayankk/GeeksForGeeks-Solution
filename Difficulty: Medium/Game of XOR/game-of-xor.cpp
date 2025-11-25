class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        
        // Key Insight:
        // -------------
        // Each element arr[i] appears in (i+1) * (n-i) subarrays.
        // If that count is odd, arr[i] contributes to the final XOR.
        //
        // The product (i+1) * (n-i) is odd only when BOTH numbers are odd.
        //
        // That happens exactly when:
        //    -> i is even
        //    -> n is odd
        //
        // Therefore:
        //    - If n is even    -> every element contributes an even number of times -> final XOR = 0
        //    - If n is odd     -> only elements at even indices contribute
        
        
        // Case 1: If size of array is even → final XOR is always zero
        if (n % 2 == 0) 
            return 0;
        
        // Case 2: n is odd → XOR all elements at even indices (0, 2, 4, ...)
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans ^= arr[i];   // each appears odd number of times
        }
        
        return ans;
    }
};
