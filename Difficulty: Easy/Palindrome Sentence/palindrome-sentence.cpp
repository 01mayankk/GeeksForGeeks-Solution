class Solution {
  public:
    // Function to check if a sentence is a palindrome, ignoring non-alphabet characters and case
    bool isPalinSent(string &s) {
        string ss; // This will store the filtered and lowercased alphabet characters from the sentence

        // Step 1: Filter out only alphabetic characters and convert them to lowercase
        for (char c : s) {
            if (isalnum(c)) {             // Check if the character is an English alphabet
                ss += tolower(c);         // Convert to lowercase and append to the new string
            }
        }

        // Step 2: Use two-pointer technique to check if the filtered string is a palindrome
        int left = 0;                     // Pointer starting from the beginning of the string
        int right = ss.size() - 1;        // Pointer starting from the end of the string

        while (left <= right) {
            if (ss[left] != ss[right]) {  // If characters at both ends don't match, not a palindrome
                return false;
            }
            left++;                       // Move left pointer to the right
            right--;                      // Move right pointer to the left
        }

        // If all characters matched, it is a palindrome
        return true;
    }
};
