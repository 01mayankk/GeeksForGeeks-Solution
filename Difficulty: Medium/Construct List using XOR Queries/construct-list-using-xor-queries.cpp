class Solution {
public:
    vector<int> constructList(vector<vector<int>> &queries) {

        // Stores cumulative XOR of all type-1 queries
        int currXor = 0;

        // Result array
        vector<int> ans;

        int n = queries.size();

        // Process queries from right to left
        for (int i = n - 1; i >= 0; i--) {

            int type = queries[i][0];
            int x = queries[i][1];

            // XOR operation
            if (type == 1) {
                currXor ^= x;
            }

            // Insert operation
            else {

                // This element will eventually be affected
                // by all XORs that appear after it.
                ans.push_back(x ^ currXor);
            }
        }

        // Initial element 0 is always present in the list
        ans.push_back(currXor);

        // Return elements in sorted order
        sort(ans.begin(), ans.end());

        return ans;
    }
};