class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        
        int n = arr.size();
        
        // Create separate arrays to store start times and end times
        vector<int> start(n), end(n);
        
        // Fill start[] and end[] from given intervals
        for(int i = 0; i < n; i++) {
            start[i] = arr[i][0];   // starting time of interval
            end[i]   = arr[i][1];   // ending time of interval
        }
        
        // Sort both arrays independently
        // This helps simulate timeline traversal
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0;     // pointer for start times
        int j = 0;     // pointer for end times
        int curr = 0;  // current number of overlapping intervals
        int maxi = 0;  // maximum overlapping intervals observed
        
        // Traverse both arrays using two pointers
        while(i < n && j < n) {
            
            /*
              If next interval starts before or exactly when 
              the current interval ends (inclusive overlap),
              it increases the overlap count.
            */
            if(start[i] <= end[j]) {
                curr++;                       // one interval added
                maxi = max(maxi, curr);       // update maximum overlap
                i++;                          // move to next start time
            }
            else {
                /*
                  If current interval ended before next one starts,
                  decrease overlap count.
                */
                curr--;       // one interval ended
                j++;          // move to next end time
            }
        }
        
        // Return maximum number of overlapping intervals
        return maxi;
    }
};
