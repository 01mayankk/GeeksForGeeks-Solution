class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> nums;  // To store the leaders
       
        // Initialize maxFromRight as the rightmost element
        int maxFromRight = arr[arr.size() - 1];
        nums.push_back(maxFromRight);  // The rightmost element is always a leader
        
        // Traverse the array from right to left starting from the second last element
        for (int i = arr.size() - 2; i >= 0; i--) {
            // If current element is greater than or equal to the max seen so far from the right
            if (arr[i] >= maxFromRight) {
                maxFromRight = arr[i];      // Update maxFromRight
                nums.push_back(arr[i]);     // Current element is a leader, add to result
            }
        }
        
        // Since we traversed from right to left, the leaders are in reverse order
        reverse(nums.begin(), nums.end());  // Reverse to maintain the order of appearance
        
        return nums;  // Return the list of leaders
    }
};
