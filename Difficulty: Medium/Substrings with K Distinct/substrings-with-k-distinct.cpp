class Solution {
public:
    
    // Helper function: count substrings with at most k distinct characters
    long long atMostK(string &s, int k) {
        if (k < 0) return 0;

        vector<int> freq(26, 0);  // frequency of characters
        int left = 0;
        int distinct = 0;
        long long count = 0;

        for (int right = 0; right < s.size(); right++) {
            
            // Add current character
            if (freq[s[right] - 'a'] == 0)
                distinct++;
            freq[s[right] - 'a']++;

            // Shrink window if distinct chars > k
            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            // Number of valid substrings ending at right
            count += (right - left + 1);
        }

        return count;
    }

    // Main function: exactly k distinct characters
    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};
