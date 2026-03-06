class Solution {
  public:
    string minWindow(string &s, string &p) {
        
        int n = s.size();
        int m = p.size();
        
        // Frequency array to store characters needed from p
        vector<int> need(26, 0);
        
        // Fill frequency of pattern characters
        for(char c : p)
            need[c - 'a']++;
        
        int left = 0, right = 0;
        
        // Total characters still required to match
        int required = m;
        
        // To store answer window
        int minLen = INT_MAX;
        int startIndex = -1;
        
        while(right < n)
        {
            // If current character is needed
            if(need[s[right] - 'a'] > 0)
                required--;
            
            // Decrease frequency (even if negative for extra chars)
            need[s[right] - 'a']--;
            
            right++;
            
            // When all characters are matched
            while(required == 0)
            {
                // Update minimum window
                if(right - left < minLen)
                {
                    minLen = right - left;
                    startIndex = left;
                }
                
                // Try shrinking window
                need[s[left] - 'a']++;
                
                // If this character becomes required again
                if(need[s[left] - 'a'] > 0)
                    required++;
                
                left++;
            }
        }
        
        // If no valid window found
        if(startIndex == -1)
            return "";
        
        return s.substr(startIndex, minLen);
    }
};