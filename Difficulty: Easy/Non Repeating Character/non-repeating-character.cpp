class Solution {
  public:
    char nonRepeatingChar(string &s) {
        // Step 1: Count frequencies of all characters
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Step 2: Traverse again to find the first character with freq = 1
        for (char c : s) {
            if (freq[c] == 1) {
                return c;
            }
        }
        
        // Step 3: If all characters repeat
        return '$';
    }
};
