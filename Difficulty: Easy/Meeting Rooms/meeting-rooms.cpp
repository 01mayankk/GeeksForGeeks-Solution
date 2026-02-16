class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        
        // Step 1: Sort meetings based on starting time
        // Sorting ensures we can check overlap with previous meeting only
        sort(arr.begin(), arr.end());
        
        // Step 2: Traverse from second meeting onwards
        for(int i = 1; i < arr.size(); i++) {
            
            // If current meeting's start time is
            // less than previous meeting's end time,
            // then there is an overlap → cannot attend all
            if(arr[i][0] < arr[i-1][1]) {
                return false;
            }
        }
        
        // If no overlaps found, all meetings can be attended
        return true;
    }
};
