#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ==========================================================
    // Fenwick Tree (Binary Indexed Tree)
    // Supports:
    // 1. Point Update      -> O(log N)
    // 2. Prefix Sum Query  -> O(log N)
    // ==========================================================
    class Fenwick {

        vector<int> bit;   // Stores frequencies
        int n;

    public:

        // Constructor
        Fenwick(int size) {
            n = size;
            bit.assign(n + 1, 0);
        }

        // ------------------------------------------------------
        // Inserts "value" at a compressed index.
        // All responsible parent nodes are updated.
        // ------------------------------------------------------
        void update(int index, int value) {

            while (index <= n) {

                bit[index] += value;

                // Move to the next responsible node.
                index += index & (-index);
            }
        }

        // ------------------------------------------------------
        // Returns the sum of frequencies from index [1...index]
        // ------------------------------------------------------
        int query(int index) {

            int sum = 0;

            while (index > 0) {

                sum += bit[index];

                // Move to the parent node.
                index -= index & (-index);
            }

            return sum;
        }
    };

    int countSubstring(string &s) {

        int n = s.size();

        // ------------------------------------------------------
        // Step 1:
        // Convert the binary string into prefix sums.
        //
        // '1' contributes +1
        // '0' contributes -1
        //
        // A substring has more 1's than 0's iff
        //
        // prefix[j] > prefix[i]
        //
        // where i < j.
        // ------------------------------------------------------
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {

            if (s[i] == '1')
                prefix[i + 1] = prefix[i] + 1;
            else
                prefix[i + 1] = prefix[i] - 1;
        }

        // ------------------------------------------------------
        // Step 2:
        // Coordinate Compression
        //
        // Prefix sums may contain negative values.
        // Fenwick Tree works on positive indices only.
        //
        // Example:
        // Prefix = [-2,0,3,-1]
        //
        // becomes
        //
        // [-2,-1,0,3]
        //   1  2 3 4
        // ------------------------------------------------------
        vector<int> values = prefix;

        sort(values.begin(), values.end());

        values.erase(unique(values.begin(), values.end()), values.end());

        // Fenwick Tree stores frequency of prefix sums seen so far.
        Fenwick ft(values.size());

        long long answer = 0;

        // ------------------------------------------------------
        // Step 3:
        // Process every prefix sum from left to right.
        //
        // We need to know:
        //
        // How many previous prefix sums are STRICTLY smaller
        // than the current prefix sum?
        //
        // Every such prefix forms one valid substring.
        // ------------------------------------------------------
        for (int x : prefix) {

            // Convert actual prefix value into compressed index.
            int idx = lower_bound(values.begin(), values.end(), x)
                      - values.begin() + 1;

            // Count all previous prefix sums smaller than x.
            answer += ft.query(idx - 1);

            // Store current prefix for future substrings.
            ft.update(idx, 1);
        }

        return (int)answer;
    }
};