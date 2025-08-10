/*
  GFG: Count Palindromic Substrings (count substrings of length >= 2)

  Approach:
    Expand-around-center:
      - For odd-length palindromes, treat each character as a center.
      - For even-length palindromes, treat each gap between characters as a center.
    For every center, expand left and right while characters match.
    Count every palindrome found whose length is at least 2.

  Time complexity: O(n^2) worst-case (e.g., "aaaa..."), because for each center
                   we may expand up to O(n) characters.
  Space complexity: O(1) (only constant extra space used).
*/

class Solution {
  public:
    int countPS(string &s) {
        // length of input string (store once to avoid repeated calls)
        int n = s.length();

        // result counter: number of palindromic substrings of length >= 2
        int count = 0;

        // -------------------------
        // 1) Odd-length palindromes
        // -------------------------
        // Example centers: for string "aba", center at 'b' gives palindrome "aba".
        // We set left = center, right = center and expand outward.
        for (int center = 0; center < n; center++) {
            int left = center;   // start left pointer at center
            int right = center;  // start right pointer at center

            // Expand while inside bounds and characters at both ends are equal
            while (left >= 0 && right < n && s[left] == s[right]) {
                // we've found a palindrome s[left..right]
                // length = right - left + 1
                // only count palindromes of length >= 2 (problem requirement)
                int len = right - left + 1;
                if (len >= 2) {
                    ++count;
                }

                // move outward to check for bigger palindrome centered at same place
                --left;
                ++right;
            }
        }

        // --------------------------
        // 2) Even-length palindromes
        // --------------------------
        // Example centers: for string "aa", the center is between the two 'a's.
        // We set left = center and right = center + 1 and expand outward.
        for (int center = 0; center < n - 1; center++) {
            int left = center;       // left char of the pair
            int right = center + 1;  // right char of the pair

            // Expand while inside bounds and characters match
            // Note: initial check (s[left] == s[right]) ensures substring length is at least 2,
            // so every palindrome encountered here should be counted immediately.
            while (left >= 0 && right < n && s[left] == s[right]) {
                // s[left..right] is a palindrome of length >= 2
                ++count;

                // expand outward to find longer even-length palindromes
                --left;
                ++right;
            }
        }

        // Return total count of palindromic substrings with length >= 2
        return count;
    }
};
