class Solution {
  public:
    int countWays(int n, int k) {
        
        // Base cases
        if(n == 1) return k;
        if(n == 2) return k * k;
        
        // same: last two posts have same color
        // diff: last two posts have different colors
        
        int same = k;           // For n = 2 → same = k (AA type)
        int diff = k * (k - 1); // For n = 2 → diff = k*(k-1)
        
        // Iterate from post 3 to n
        for(int i = 3; i <= n; i++) {
            
            int new_same = diff;  // Only way to get same is from previous diff
            
            int new_diff = (same + diff) * (k - 1); 
            // Choose different color from last → (k-1)
            
            same = new_same;
            diff = new_diff;
        }
        
        // Total ways = same + diff
        return same + diff;
    }
};