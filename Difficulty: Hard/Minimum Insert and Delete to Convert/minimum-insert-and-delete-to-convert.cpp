class Solution {
public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {

        int n = a.size();
        int m = b.size();

        // Map each value in array 'b' to its index.
        // Since 'b' is sorted and contains distinct elements,
        // every value has a unique position.
        unordered_map<int, int> indexInB;

        for (int i = 0; i < m; i++) {
            indexInB[b[i]] = i;
        }

        // Store only those elements of 'a' that are present in 'b'.
        // Instead of storing the actual values, store their indices in 'b'.
        vector<int> filtered;

        for (int value : a) {
            if (indexInB.count(value)) {
                filtered.push_back(indexInB[value]);
            }
        }

        // Find the Longest Increasing Subsequence (LIS)
        // of the mapped indices.
        //
        // Since indices are increasing only when the relative
        // order matches array 'b', the LIS length is equal to
        // the Longest Common Subsequence (LCS) length.
        vector<int> lis;

        for (int index : filtered) {

            // Find the first element >= current index.
            auto it = lower_bound(lis.begin(), lis.end(), index);

            // Extend the LIS if current index is greater
            // than all existing elements.
            if (it == lis.end()) {
                lis.push_back(index);
            }
            // Otherwise replace the element to maintain
            // the smallest possible tail for this LIS length.
            else {
                *it = index;
            }
        }

        int lcsLength = lis.size();

        // Elements not in LCS must be deleted from 'a'.
        int deletions = n - lcsLength;

        // Missing elements from 'b' must be inserted.
        int insertions = m - lcsLength;

        return deletions + insertions;
    }
};