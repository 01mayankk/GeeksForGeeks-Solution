class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        
        // hint[i] tells whether a flip started at index i
        vector<int> hint(n, 0);
        
        int flip = 0;   // current flip parity (0 = even flips, 1 = odd flips)
        int ans = 0;    // number of flips performed
        
        for (int i = 0; i < n; i++) {
            
            // Remove effect of flip window that ended
            if (i >= k) {
                flip ^= hint[i - k];
            }
            
            // If current bit after considering flips is 0
            if ((arr[i] ^ flip) == 0) {
                
                // If we cannot flip k elements from here
                if (i + k > n)
                    return -1;
                
                // Start a new flip
                hint[i] = 1;
                flip ^= 1;
                ans++;
            }
        }
        
        return ans;
    }
};