#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to check whether a string segment is a valid IP part
    bool isValid(string part) {
        
        // Length must be between 1 and 3
        if (part.size() == 0 || part.size() > 3)
            return false;

        // Leading zero check
        // If length > 1 and starts with '0', it's invalid
        if (part.size() > 1 && part[0] == '0')
            return false;

        // Convert to integer
        int num = stoi(part);

        // Must be between 0 and 255
        return num >= 0 && num <= 255;
    }

    // Backtracking function to build IP segments
    void solve(int index, int parts, string current,
               string &s, vector<string> &result) {

        // If we already formed 4 parts
        if (parts == 4) {

            // If entire string is used -> valid IP
            if (index == s.size()) {

                // Remove last '.'
                current.pop_back();
                result.push_back(current);
            }
            return;
        }

        // Try segment lengths 1, 2, 3
        for (int len = 1; len <= 3; len++) {

            // Ensure substring stays within bounds
            if (index + len > s.size())
                break;

            // Extract substring
            string part = s.substr(index, len);

            // Check if valid IP segment
            if (isValid(part)) {

                // Add segment + dot and recurse
                solve(index + len,
                      parts + 1,
                      current + part + ".",
                      s,
                      result);
            }
        }
    }

    vector<string> generateIp(string &s) {

        vector<string> result;

        // Quick pruning:
        // Minimum length = 4 (1 digit each)
        // Maximum length = 12 (3 digits each)
        if (s.size() < 4 || s.size() > 12)
            return result;

        // Start backtracking
        solve(0, 0, "", s, result);

        return result;
    }
};