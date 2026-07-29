class Solution {
public:
    int minSubsets(vector<int>& arr) {
        // If the array is empty, there are 0 subsets
        if (arr.empty()) {
            return 0;
        }
        
        // Sort the array to easily find consecutive elements
        sort(arr.begin(), arr.end());
        
        // At least one subset will exist if the array is not empty
        int count = 1;
        
        // Traverse the sorted array starting from the second element
        for (int i = 1; i < arr.size(); i++) {
            // If the current element is not exactly 1 greater than the previous,
            // it means a new subset of consecutive numbers is starting
            if (arr[i] != arr[i - 1] + 1) {
                count++;
            }
        }
        
        return count;
    }
};