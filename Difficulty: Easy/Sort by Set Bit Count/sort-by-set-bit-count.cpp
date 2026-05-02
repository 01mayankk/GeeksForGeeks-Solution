class Solution {
public:
    // Function to sort the array based on set bit count
    vector<int> sortBySetBitCount(vector<int>& arr) {
        
        // We use stable_sort instead of sort because:
        // If two elements have the same number of set bits,
        // their relative order from the original array must be preserved.
        stable_sort(arr.begin(), arr.end(), [](int a, int b) {
            
            // Count number of set bits (1s) in binary representation
            // __builtin_popcount is a GCC built-in function (very fast)
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            // Comparator logic:
            // Return true if 'a' should come before 'b'
            // We want descending order of set bits
            // So element with MORE set bits should come first
            return countA > countB;
        });
        
        // Return the sorted array
        return arr;
    }
};