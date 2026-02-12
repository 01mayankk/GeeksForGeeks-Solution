class Solution {
public:

    // ---------------------------------------------------------
    // Function to check:
    // Can we make every flower's height >= ht
    // using at most k watering operations?
    // ---------------------------------------------------------
    bool canAchieve(vector<int>& a, int k, int w, long long ht) {
        
        int n = a.size();
        
        // This array works as a Difference Array.
        // flower[i] stores how much extra water effect starts at i.
        // We use long long because height can become large.
        vector<long long> flower(n + 1, 0);
        
        long long days = 0;   // total operations used
        
        for(int i = 0; i < n; i++) {
            
            // Convert difference array to prefix sum
            // So flower[i] represents total water applied at index i
            if(i > 0)
                flower[i] += flower[i - 1];
            
            // Current actual height after applied watering
            long long currentHeight = a[i] + flower[i];
            
            // If below target height, calculate needed increment
            long long diff = max(0LL, ht - currentHeight);
            
            if(diff > 0) {
                
                // Use 'diff' watering operations
                days += diff;
                
                // If we exceed allowed k days → impossible
                if(days > k)
                    return false;
                
                // Apply watering starting from index i
                flower[i] += diff;
                
                // Stop watering effect after w flowers
                // i+w is first index that should NOT get this increment
                if(i + w < n)
                    flower[i + w] -= diff;
            }
        }
        
        // If we stayed within k operations
        return true;
    }


    // ---------------------------------------------------------
    // Main function:
    // Return maximum possible minimum height
    // ---------------------------------------------------------
    int maxMinHeight(vector<int> &a, int k, int w) {
        
        // Lowest possible answer = minimum element
        long long low = *min_element(a.begin(), a.end());
        
        // Highest possible answer:
        // In worst case, we increase smallest element k times
        long long high = low + k;
        
        // Binary search on answer space
        while(low < high) {
            
            // Upper mid to prevent infinite loop
            long long mid = (low + high + 1) / 2;
            
            // If we can achieve mid height
            if(canAchieve(a, k, w, mid))
                low = mid;       // try to go higher
            else
                high = mid - 1;  // reduce target
        }
        
        // Final answer
        return low;
    }
};
