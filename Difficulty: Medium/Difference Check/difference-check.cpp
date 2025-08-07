class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // Step 1: Get the number of time strings in the input
        int n = arr.size();
        
        // Vector to store total seconds for each time string
        vector<long long> tm;

        // Step 2: Convert each time string "HH:MM:SS" to total seconds and store in tm
        for (string ch : arr) {
            int hr = stoi(ch.substr(0, 2));     // Extract hours (0 to 1 index)
            int min = stoi(ch.substr(3, 2));    // Extract minutes (3 to 4 index)
            int sec = stoi(ch.substr(6, 2));    // Extract seconds (6 to 7 index)

            // Convert to total seconds: hr*3600 + min*60 + sec
            long long total = hr * 3600 + min * 60 + sec;

            // Store the result
            tm.push_back(total);
        }

        // Step 3: Sort the time values (in seconds)
        sort(tm.begin(), tm.end());

        // Step 4: Initialize the minimum difference as maximum possible
        long long ans = LLONG_MAX;

        // Step 5: Compare differences between adjacent time points in sorted order
        for (int i = 1; i < n; i++) {
            long long diff = tm[i] - tm[i - 1];
            ans = min(ans, diff);  // Update minimum difference
        }

        // Step 6: Consider wrap-around case (last and first time of day)
        // A full day is 86400 seconds, so the wrap-around difference is:
        long long wrapDiff = 86400 - tm[n - 1] + tm[0];

        // Update answer with wrap-around difference
        ans = min(ans, wrapDiff);

        // Step 7: Return the minimum time difference (as integer)
        return (int)ans;
    }
};
