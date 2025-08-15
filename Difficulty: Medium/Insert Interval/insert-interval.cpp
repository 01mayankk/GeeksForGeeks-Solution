class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // Step 1: Add the new interval to the existing list
        intervals.push_back(newInterval);

        // Step 2: Sort intervals based on their start times
        // Default sort works here because vector<int> compares lexicographically
        sort(intervals.begin(), intervals.end());

        // Step 3: Initialize the result with the first interval
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        int index = 0; // Tracks the last merged interval in 'ans'
        
        // Step 4: Traverse through remaining intervals to merge overlaps
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval overlaps with the last one in 'ans'
            if (intervals[i][0] <= ans[index][1]) {
                // Merge by updating the end time to the maximum end
                ans[index][1] = max(ans[index][1], intervals[i][1]);
            } 
            else {
                // No overlap → add current interval as a new merged interval
                ans.push_back(intervals[i]);
                index++; // Move to the new merged interval
            }
        }
        
        // Step 5: Return the merged intervals
        return ans;
    }
};
