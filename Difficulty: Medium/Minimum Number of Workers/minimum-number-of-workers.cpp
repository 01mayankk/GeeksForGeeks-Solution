class Solution {
public:
    int minMen(vector<int>& arr) {

        int n = arr.size();

        // This will store all valid working intervals [L, R]
        vector<pair<int,int>> intervals;

        // STEP 1: Convert each person into an interval
        for (int i = 0; i < n; i++) {
            // If person is available
            if (arr[i] != -1) {

                // Left boundary of coverage
                int L = max(0, i - arr[i]);

                // Right boundary of coverage
                int R = min(n - 1, i + arr[i]);

                // Store the interval
                intervals.push_back({L, R});
            }
        }

        // STEP 2: Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        int count = 0;          // Number of people selected
        int currentEnd = 0;     // Current time index to be covered
        int i = 0;              // Iterator for intervals

        // STEP 3: Greedy interval coverage
        while (currentEnd < n) {

            // Farthest position we can reach from currentEnd
            int farthest = currentEnd - 1;

            // Check all intervals that start at or before currentEnd
            while (i < intervals.size() && intervals[i].first <= currentEnd) {

                // Extend coverage as far right as possible
                farthest = max(farthest, intervals[i].second);
                i++;
            }

            // If we cannot extend coverage, return -1
            if (farthest < currentEnd) {
                return -1;
            }

            // One person selected
            count++;

            // Move to the next uncovered position
            currentEnd = farthest + 1;
        }

        // Return minimum number of persons needed
        return count;
    }
};
