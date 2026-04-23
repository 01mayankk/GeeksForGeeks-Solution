class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int n = arr.size();
        
        // First building always gets sunlight
        int count = 1;
        
        // Store maximum height seen so far
        int maxHeight = arr[0];
        
        // Traverse from second building
        for (int i = 1; i < n; i++) {
            
            // If current building is taller or equal,
            // it can see sunlight
            if (arr[i] >= maxHeight) {
                count++;                 // Increase count
                maxHeight = arr[i];      // Update max height
            }
        }
        
        return count;
    }
};