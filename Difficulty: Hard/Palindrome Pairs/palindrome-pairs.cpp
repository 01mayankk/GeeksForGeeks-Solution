class Solution {
public:

    // ---------------------------------------------------
    // Function to check whether substring s[l...r]
    // is palindrome or not
    // ---------------------------------------------------
    bool isPalindrome(string &s, int l, int r) {

        while (l < r) {

            // If characters mismatch,
            // then not palindrome
            if (s[l] != s[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    bool palindromePair(vector<string>& arr) {

        int n = arr.size();

        // ---------------------------------------------------
        // HashMap:
        // string -> index
        //
        // Used for O(1) lookup
        // ---------------------------------------------------
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        // ---------------------------------------------------
        // Traverse every string
        // ---------------------------------------------------
        for (int i = 0; i < n; i++) {

            string s = arr[i];

            int len = s.length();

            // ---------------------------------------------------
            // Try every possible split
            //
            // Example:
            // s = "abcd"
            //
            // j=0 -> ""    | "abcd"
            // j=1 -> "a"   | "bcd"
            // j=2 -> "ab"  | "cd"
            // j=3 -> "abc" | "d"
            // j=4 -> "abcd"| ""
            // ---------------------------------------------------
            for (int j = 0; j <= len; j++) {

                // Split into prefix and suffix
                string prefix = s.substr(0, j);
                string suffix = s.substr(j);

                // =================================================
                // CASE 1:
                //
                // If prefix is palindrome,
                // then reverse(suffix) should exist
                //
                // Example:
                // s = "abc"
                //
                // prefix = "a"  -> palindrome
                // suffix = "bc"
                //
                // reverse("bc") = "cb"
                //
                // If "cb" exists,
                // then "cb" + "abc" becomes palindrome
                // =================================================
                if (isPalindrome(prefix, 0, prefix.length() - 1)) {

                    // Reverse the suffix
                    string revSuffix = suffix;

                    reverse(revSuffix.begin(), revSuffix.end());

                    // Check:
                    // 1. reversed suffix exists
                    // 2. should not be same index
                    if (mp.count(revSuffix) &&
                        mp[revSuffix] != i) {

                        return true;
                    }
                }

                // =================================================
                // CASE 2:
                //
                // If suffix is palindrome,
                // then reverse(prefix) should exist
                //
                // Example:
                // s = "abc"
                //
                // prefix = "ab"
                // suffix = "c" -> palindrome
                //
                // reverse("ab") = "ba"
                //
                // If "ba" exists,
                // then "abc" + "ba" becomes palindrome
                // =================================================

                // j != len prevents duplicate checking
                if (j != len &&
                    isPalindrome(suffix, 0, suffix.length() - 1)) {

                    // Reverse the prefix
                    string revPrefix = prefix;

                    reverse(revPrefix.begin(), revPrefix.end());

                    // Check whether reversed prefix exists
                    // and index should be different
                    if (mp.count(revPrefix) &&
                        mp[revPrefix] != i) {

                        return true;
                    }
                }
            }
        }

        // No palindrome pair found
        return false;
    }
};