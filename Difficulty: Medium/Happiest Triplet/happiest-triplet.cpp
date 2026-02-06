class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {

        // Sort all three arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, k = 0;

        int bestDiff = INT_MAX;
        int bestSum = INT_MAX;
        vector<int> ans(3);

        // Traverse arrays using three pointers
        while (i < a.size() && j < b.size() && k < c.size()) {

            int x = a[i];
            int y = b[j];
            int z = c[k];

            int currMin = min({x, y, z});
            int currMax = max({x, y, z});
            int currDiff = currMax - currMin;
            int currSum = x + y + z;

            // Update result if:
            // 1) smaller difference OR
            // 2) same difference but smaller sum
            if (currDiff < bestDiff || 
               (currDiff == bestDiff && currSum < bestSum)) {

                bestDiff = currDiff;
                bestSum = currSum;
                ans = {x, y, z};
            }

            // Move the pointer pointing to the minimum value
            if (currMin == x) {
                i++;
            } else if (currMin == y) {
                j++;
            } else {
                k++;
            }
        }

        // Sort answer in decreasing order as required
        sort(ans.begin(), ans.end(), greater<int>());

        return ans;
    }
};
