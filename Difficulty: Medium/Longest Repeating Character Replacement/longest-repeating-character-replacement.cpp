class Solution {
  public:
    int longestSubstr(string& s, int k) {
        
        vector<int> freq(26, 0); // frequency of characters
        int left = 0, maxFreq = 0, maxLen = 0;

        // Right pointer expands the window
        for (int right = 0; right < s.size(); right++) {
            
            // Increase frequency of current character
            freq[s[right] - 'A']++;
            
            // Track the maximum frequency in current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If more than k replacements needed, shrink window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--; // remove left char
                left++; // shrink window
            }

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};