class Solution {
public:
    int maxPeopleDefeated(int p) {
        
        // We need the maximum n such that:
        // 1^2 + 2^2 + 3^2 + ... + n^2 <= p
        //
        // Sum of first n squares:
        // S = n * (n + 1) * (2 * n + 1) / 6
        //
        // Find the largest n satisfying S <= p using Binary Search.

        long long low = 0, high = 10000; // sufficient for p <= 3e8
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long sum =
                mid * (mid + 1) * (2 * mid + 1) / 6;

            if (sum <= p) {
                ans = mid;       // mid people can be defeated
                low = mid + 1;   // try for a larger answer
            } else {
                high = mid - 1;  // reduce n
            }
        }

        return ans;
    }
};