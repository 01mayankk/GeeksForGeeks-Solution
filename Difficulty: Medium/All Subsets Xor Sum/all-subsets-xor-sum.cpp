class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        
        // Step 1: Compute bitwise OR of all elements
        // Explanation:
        // In XOR subsets, each bit contributes independently.
        // A bit contributes to final sum only if it's present in at least one element.
        // OR stores all bits that appear in the array.
        int OR = 0;
        for(int x : arr)
            OR |= x;   // OR accumulates all set bits from array
        
        
        // Step 2: Total subsets = 2^n
        // Each element appears in exactly half of the subsets = 2^(n-1)
        // Every set bit contributes that many times.
        // Final result = OR * 2^(n-1)
        int n = arr.size();
        
        return OR * (1 << (n - 1));   // (1 << (n-1)) = 2^(n-1)
    }
};
