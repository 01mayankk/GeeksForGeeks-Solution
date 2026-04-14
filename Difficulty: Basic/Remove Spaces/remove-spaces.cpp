class Solution {
  public:
    string removeSpaces(string& s) {
        int j = 0; // Pointer for placing non-space characters
        
        // Traverse the string
        for (int i = 0; i < s.length(); i++) {
            
            // If not a space, move character to position j
            if (s[i] != ' ') {
                s[j++] = s[i];
            }
        }
        
        // Resize string to remove extra characters
        s.resize(j);
        
        return s;
    }
};