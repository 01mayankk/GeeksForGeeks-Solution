class Solution {
  public:
    int smallestSubstring(string s) {
        int n = s.size();
        
        // Frequency of '0', '1', '2'
        vector<int> freq(3, 0);
        
        int left = 0;
        int minLen = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            // Include current character in window
            freq[s[right] - '0']++;
            
            // Check if current window contains all 3 characters
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                
                // Update minimum length
                minLen = min(minLen, right - left + 1);
                
                // Try to shrink window from left
                freq[s[left] - '0']--;
                left++;
            }
        }
        
        // If no valid window found
        return (minLen == INT_MAX) ? -1 : minLen;
    }
};