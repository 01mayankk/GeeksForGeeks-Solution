#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        // Maps to store frequency of each number and how many subsequences end at each number
        unordered_map<int, int> count, end;

        // Step 1: Count occurrences of all numbers
        for (int x : arr) count[x]++;

        // Step 2: Iterate through the array (already sorted)
        for (int x : arr) {
            // If current number is already used in subsequences, skip it
            if (count[x] == 0) continue;

            // Use this number once
            count[x]--;

            // Case 1️⃣: Try to extend a previous subsequence ending at x-1
            if (end[x - 1] > 0) {
                end[x - 1]--;   // One subsequence ending at (x-1) now extends to x
                end[x]++;       // So we have one more subsequence ending at x
            } 
            // Case 2️⃣: Try to start a new subsequence of length at least k
            else {
                bool canForm = true;

                // Check if next (k-1) consecutive elements exist
                for (int i = 1; i < k; i++) {
                    if (count[x + i] == 0) { // If any number is missing
                        canForm = false;
                        break;
                    }
                }

                // If we can’t form such a subsequence, splitting isn’t possible
                if (!canForm) return false;

                // Use up the next (k-1) elements to form a new subsequence [x, x+1, ..., x+k-1]
                for (int i = 1; i < k; i++) count[x + i]--;

                // This new subsequence now ends at (x + k - 1)
                end[x + k - 1]++;
            }
        }

        // If we reach here, all numbers have been placed into valid subsequences
        return true;
    }
};
