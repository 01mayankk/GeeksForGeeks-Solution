class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        
        // If size < 3, impossible
        if (n < 3) return {};
        
        // Step 1: smaller[i] will store index of a smaller element on left of i
        vector<int> smaller(n, -1);
        
        int minIndex = 0;  // index of smallest element so far
        
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[minIndex]) {
                // Update minimum index
                minIndex = i;
            } else {
                // Found a smaller element on left
                smaller[i] = minIndex;
            }
        }
        
        // Step 2: greater[i] will store index of a greater element on right of i
        vector<int> greater(n, -1);
        
        int maxIndex = n - 1;  // index of largest element from right
        
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[maxIndex]) {
                // Update maximum index
                maxIndex = i;
            } else {
                // Found a greater element on right
                greater[i] = maxIndex;
            }
        }
        
        // Step 3: Find valid triplet
        for (int i = 0; i < n; i++) {
            // If both exist → valid subsequence
            if (smaller[i] != -1 && greater[i] != -1) {
                return {arr[smaller[i]], arr[i], arr[greater[i]]};
            }
        }
        
        // No valid subsequence found
        return {};
    }
};