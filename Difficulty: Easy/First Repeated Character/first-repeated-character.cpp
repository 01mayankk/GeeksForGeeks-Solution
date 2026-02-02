class Solution {
  public:
    string firstRepChar(string s) {
        
        // Unordered set to keep track of characters
        // that have already been seen in the string
        unordered_set<char> unique;
        
        // Traverse each character in the string
        for (char ch : s) {
            
            // If the character is already present in the set,
            // it means this character is the first repeated one
            if (unique.count(ch)) {
                // Return the repeated character as a string
                return string(1, ch);
            }
            
            // Otherwise, insert the character into the set
            unique.insert(ch);
        }
        
        // If no repeating character is found,
        // return "-1" as per the problem statement
        return "-1";
    }
};
