class Solution {
public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();

        // Total sum of elements at even and odd indices
        int totalEven = 0, totalOdd = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                totalEven += arr[i];
            else
                totalOdd += arr[i];
        }

        int prefixEven = 0, prefixOdd = 0;
        int ans = 0;

        // Try removing each index
        for (int i = 0; i < n; i++) {

            // Remove current element from total
            if (i % 2 == 0)
                totalEven -= arr[i];
            else
                totalOdd -= arr[i];

            /*
              After removal:
              - Left part keeps same parity
              - Right part shifts → parity flips
            */

            int newEvenSum = prefixEven + totalOdd;
            int newOddSum  = prefixOdd + totalEven;

            // Check balance condition
            if (newEvenSum == newOddSum)
                ans++;

            // Add current element to prefix
            if (i % 2 == 0)
                prefixEven += arr[i];
            else
                prefixOdd += arr[i];
        }

        return ans;
    }
};
