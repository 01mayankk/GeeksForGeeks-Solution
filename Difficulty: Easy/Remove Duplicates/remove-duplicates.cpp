// User function template for C++
class Solution {
  public:

    string removeDups(string &s) {
        // Your code goes here
        unordered_map<char, bool> seen;   // stores whether a character has appeared before
        string ans;                       // final string with unique characters in order

        // Iterate through each character of the string
        for (char c : s) {

            // If character is NOT seen before, keep it
            if (!seen[c]) {
                ans += c;      // add to answer
                seen[c] = true;   // mark as seen
            }
            // If seen[c] is true → skip (ignore duplicate)
        }

        return ans;    // return result string
        
    }
};