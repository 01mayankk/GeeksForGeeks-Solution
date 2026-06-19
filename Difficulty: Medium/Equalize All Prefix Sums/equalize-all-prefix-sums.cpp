class Solution {
public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();

        // Stores prefix sums
        vector<long long> pref(n);

        pref[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + arr[i];
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            // Median index of current prefix [0...i]
            int mid = i / 2;

            /*
                Cost to make all elements on the left side
                equal to arr[mid]

                Example:
                arr[mid]*(count of left elements)
                - sum(left elements)
            */
            long long leftCost =
                1LL * arr[mid] * (mid + 1) - pref[mid];

            /*
                Cost to make all elements on the right side
                equal to arr[mid]

                sum(right elements)
                - arr[mid]*(count of right elements)
            */
            long long rightCost =
                (pref[i] - pref[mid])
                - 1LL * arr[mid] * (i - mid);

            ans[i] = leftCost + rightCost;
        }

        return ans;
    }
};