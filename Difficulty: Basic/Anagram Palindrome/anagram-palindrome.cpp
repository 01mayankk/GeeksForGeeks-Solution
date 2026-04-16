class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // Step 1: Create frequency array for 26 lowercase letters
        vector<int> freq(26, 0);
        
        // Step 2: Count frequency of each character
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        
        // Step 3: Count characters with odd frequency
        int oddCount = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 != 0) {
                oddCount++;
            }
        }
        
        // Step 4: Check condition
        // At most one odd frequency allowed
        if(oddCount > 1) {
            return false;
        }
        
        return true;
    }
};