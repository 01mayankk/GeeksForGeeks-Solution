class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // Create an unordered_map to store frequency of each element
        unordered_map<int, int> map;

        // Traverse through the array
        for (int i = 0; i < arr.size(); i++) {
            // Increment the frequency count for arr[i]
            map[arr[i]]++;
        }

        // Check if the target element exists in the map
        if (map.find(target) != map.end()) {
            // If found, return its frequency
            return map[target];
        }

        // If target not found in the map, return 0
        return 0; 
    }
};
