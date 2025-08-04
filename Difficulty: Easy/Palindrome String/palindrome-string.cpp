class Solution {
  public:
    // Function to check if a given string is a palindrome
    bool isPalindrome(string& s) {
        // Initialize two pointers: one from the start and one from the end
        int left = 0;
        int right = s.size() - 1;

        // Loop until the two pointers meet or cross
        while (left <= right) {
            // If characters at both ends are equal, move inward
            if (s[left] == s[right]) {
                left++;     // Move left pointer to the right
                right--;    // Move right pointer to the left
            } else {
                // Mismatch found — not a palindrome
                return false;
            }
        }

        // If all corresponding characters matched, it's a palindrome
        return true;
    }
};
