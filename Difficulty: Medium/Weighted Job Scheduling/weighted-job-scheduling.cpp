class Solution {
  public:
    // Comparator function to sort jobs by their end time
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] < b[1]; // Sort jobs by end time in ascending order
    }

    // Function to find the index of the last non-overlapping job using binary search
    int findLastNonOverlapping(vector<vector<int>> &jobs, int index) {
        int low = 0, high = index - 1;
        int ans = -1; // Stores index of last job that doesn't overlap

        while (low <= high) {
            int mid = (low + high) / 2;

            // If the current job's end time <= start time of current index job
            if (jobs[mid][1] <= jobs[index][0]) {
                ans = mid;         // This job doesn't overlap
                low = mid + 1;     // Try to find a later non-overlapping job
            } else {
                high = mid - 1;    // Move left if overlapping
            }
        }

        return ans; // Return index of last non-overlapping job, or -1 if none
    }

    int maxProfit(vector<vector<int>> &jobs) {
        // Step 1: Sort jobs by their end times
        sort(jobs.begin(), jobs.end(), compare);

        int n = jobs.size();

        // dp[i] will store the maximum profit that can be earned by scheduling jobs[0..i]
        vector<int> dp(n);

        // Base case: Only one job, so max profit = its own profit
        dp[0] = jobs[0][2];

        // Step 2: Fill dp array for each job
        for (int i = 1; i < n; i++) {
            // Option 1: Include current job's profit
            int includeProfit = jobs[i][2];

            // Find last non-overlapping job
            int last = findLastNonOverlapping(jobs, i);

            // If such a job exists, add its profit
            if (last != -1)
                includeProfit += dp[last];

            // Option 2: Exclude current job → take profit up to previous job (dp[i-1])

            // Step 3: Choose the maximum of including or excluding the current job
            dp[i] = max(dp[i - 1], includeProfit);
        }

        // Step 4: The last element contains the maximum profit achievable
        return dp[n - 1];
    }
};
