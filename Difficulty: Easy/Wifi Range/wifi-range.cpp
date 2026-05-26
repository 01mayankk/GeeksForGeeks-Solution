class Solution {
  public:
    bool wifiRange(string &s, int x) {
        
        int n = s.size();

        // Difference array for range coverage
        vector<int> diff(n + 1, 0);

        // Process every router
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '1') {
                
                // Coverage range
                int left = max(0, i - x);
                int right = min(n - 1, i + x);

                // Mark range using difference array
                diff[left] += 1;
                
                if(right + 1 < n) {
                    diff[right + 1] -= 1;
                }
            }
        }

        int coverage = 0;

        // Check coverage for every room
        for(int i = 0; i < n; i++) {
            
            coverage += diff[i];

            // If no wifi coverage
            if(coverage <= 0) {
                return false;
            }
        }

        return true;
    }
};