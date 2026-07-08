class Solution {
public:
    int countKdivPairs(vector<int>& arr, int k) {
        // Stores how many numbers have each remainder when divided by k
        vector<int> remainderCount(k, 0);

        // Total number of valid pairs
        int pairCount = 0;

        // Process each element one by one
        for (int number : arr) {
            // Current remainder
            int remainder = number % k;

            // Required remainder so that:
            // (remainder + requiredRemainder) % k == 0
            int requiredRemainder = (k - remainder) % k;

            // All previously seen numbers having the required remainder
            // can form a valid pair with the current number.
            pairCount += remainderCount[requiredRemainder];

            // Store the current remainder for future elements
            remainderCount[remainder]++;
        }

        return pairCount;
    }
};