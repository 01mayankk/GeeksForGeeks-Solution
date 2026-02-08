class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        
        // Initialize max, min product ending at index 0
        int maxEnding = arr[0];
        int minEnding = arr[0];
        
        // Final answer
        int ans = arr[0];
        
        for (int i = 1; i < n; i++) {
            // If current element is negative,
            // swap max and min because sign will flip
            if (arr[i] < 0)
                swap(maxEnding, minEnding);
            
            // Update max and min product ending at current index
            maxEnding = max(arr[i], maxEnding * arr[i]);
            minEnding = min(arr[i], minEnding * arr[i]);
            
            // Update answer
            ans = max(ans, maxEnding);
        }
        
        return ans;
    }
};
