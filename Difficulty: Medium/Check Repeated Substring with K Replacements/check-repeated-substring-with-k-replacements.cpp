class Solution {
public:
    bool kSubstr(string &s, int k) {
        int n = s.length();

        // Length of the repeating substring
        for (int len = 1; len <= n; len++) {

            // The whole string must be divisible by len
            if (n % len != 0)
                continue;

            int blocks = n / len;

            // We can replace only ONE substring of length k,
            // so the repeating substring length must be k.
            if (len != k)
                continue;

            unordered_map<string, int> freq;

            // Divide string into substrings of length k
            for (int i = 0; i < n; i += k) {
                string part = s.substr(i, k);
                freq[part]++;
            }

            /*
                Possible cases:

                1. All substrings are already same
                   Example: "abcabcabc"
                   => true

                2. Exactly one substring is different
                   Example: "abcbedabcabc"
                   => {"abc":3, "bed":1}
                   Replace "bed" with "abc"

                3. Only two substrings exist and both are different
                   Example: "bdac"
                   => {"bd":1, "ac":1}
                   Replace either one with the other

                Otherwise false.
            */

            if (freq.size() == 1)
                return true;

            if (freq.size() == 2) {
                int maxFreq = 0;

                for (auto &it : freq)
                    maxFreq = max(maxFreq, it.second);

                // One substring differs from all others
                if (maxFreq == blocks - 1)
                    return true;

                // Special case: only two blocks and both different
                if (blocks == 2)
                    return true;
            }

            return false;
        }

        return false;
    }
};