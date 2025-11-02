class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // Step 1: If lengths differ, they can't be anagrams
        if (s1.size() != s2.size())
            return false;

        // Step 2: Frequency maps for both strings
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        // Count frequency of each character in s1
        for (char c : s1)
            freq1[c]++;

        // Count frequency of each character in s2
        for (char c : s2)
            freq2[c]++;

        // Step 3: Compare frequency maps
        if (freq1.size() != freq2.size())
            return false;

        // Step 4: Check if every character has same frequency
        for (auto& elem : freq1) {
            char c = elem.first;
            int count = elem.second;

            // If character not found or frequency differs
            if (freq2[c] != count)
                return false;
        }

        // Step 5: If all checks pass → they are anagrams
        return true;
    }
};
