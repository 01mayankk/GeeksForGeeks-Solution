class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        int m = arr.size();
        // find n such that n*(n-1)/2 = m
        int n = 2;
        while ((long long)n * (n - 1) / 2 < m) ++n;

        // special case: n == 2
        if (n == 2) {
            // any pair (x, arr[0]-x) is valid; choose a simple one
            return {1, arr[0] - 1};
        }

        // For ordered pair sums as described:
        // arr[0] = a + b
        // arr[1] = a + c
        // arr[n-1] = b + c
        long long S1 = arr[0];
        long long S2 = arr[1];
        long long S3 = arr[n - 1];

        long long a_ll = (S1 + S2 - S3);
        // Should be even for valid integer solution
        if (a_ll % 2 != 0) {
            // invalid or non-integer original array — but problem says input is appropriate
            // fallback: return empty vector to indicate failure
            return {};
        }
        a_ll /= 2;

        vector<int> res(n);
        res[0] = (int)a_ll;

        // first n-1 entries in arr are: a + res[1], a + res[2], ..., a + res[n-1]
        for (int k = 1; k < n; ++k) {
            res[k] = (int)(arr[k - 1] - a_ll);
        }
        return res;
    }
};
