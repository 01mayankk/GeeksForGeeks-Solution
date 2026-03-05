class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        
        int n = s.size();
        
        int left = 0;
        int maxLen = -1;  // if no valid substring found, return -1
        
        unordered_map<char, int> freq; // stores frequency of characters
        
        // Expand the window using right pointer
        for(int right = 0; right < n; right++)
        {
            // include current character in window
            freq[s[right]]++;
            
            // if distinct characters exceed k, shrink window
            while(freq.size() > k)
            {
                freq[s[left]]--;
                
                // remove character if frequency becomes 0
                if(freq[s[left]] == 0)
                    freq.erase(s[left]);
                
                left++;
            }
            
            // if window has exactly k distinct characters
            if(freq.size() == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen;
    }
};