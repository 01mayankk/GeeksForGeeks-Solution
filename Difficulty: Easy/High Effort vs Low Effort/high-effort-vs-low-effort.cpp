class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        
        // Base case for a single day
        if (n == 1) return max(h[0], l[0]);
        
        // prev2 represents the maximum tasks completed up to day i-2
        int prev2 = max(h[0], l[0]);
        
        // prev1 represents the maximum tasks completed up to day i-1
        int prev1 = max(prev2 + l[1], h[1]);
        
        for (int i = 2; i < n; ++i) {
            // Option 1: Perform a low-effort task today
            // We add today's low-effort tasks to the max tasks up to yesterday
            int do_low = prev1 + l[i];
            
            // Option 2: Perform a high-effort task today
            // This requires resting yesterday, so we add today's high-effort tasks to the max tasks up to the day before yesterday
            int do_high = prev2 + h[i];
            
            // The max tasks up to today is the best of both options
            int current = max(do_low, do_high);
            
            // Shift the values forward for the next iteration
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};