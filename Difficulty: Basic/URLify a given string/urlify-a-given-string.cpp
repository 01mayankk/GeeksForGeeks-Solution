class Solution {
  public:
    string URLify(string &s) {
        // Result string to store final answer
        string result = "";
        
        // Traverse each character in the input string
        for (int i = 0; i < s.length(); i++) {
            
            // If current character is a space
            if (s[i] == ' ') {
                // Replace space with "%20"
                result += "%20";
            } 
            else {
                // Otherwise, add the character as it is
                result += s[i];
            }
        }
        
        // Return the modified string
        return result;
    }
};