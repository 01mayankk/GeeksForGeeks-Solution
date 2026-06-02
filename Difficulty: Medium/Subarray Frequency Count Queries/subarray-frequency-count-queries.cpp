class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        // Store all positions (indices) of each value
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        }

        vector<int> ans;

        // Process each query
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];

            // If x is not present in array
            if (pos.find(x) == pos.end()) {
                ans.push_back(0);
                continue;
            }

            vector<int> &indices = pos[x];

            /*
                Count indices of x lying in range [l, r]

                lower_bound -> first position >= l
                upper_bound -> first position > r

                Difference gives number of occurrences.
            */
            int left = lower_bound(indices.begin(), indices.end(), l) - indices.begin();
            int right = upper_bound(indices.begin(), indices.end(), r) - indices.begin();

            ans.push_back(right - left);
        }

        return ans;
    }
};