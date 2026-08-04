class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // Sort the array to efficiently find valid pairs
        sort(arr.begin(), arr.end());
        
        int count = 0;
        
        // Iterate through the array
        for (int i = 0; i < arr.size(); ++i) {
            // Find the iterator to the first element that is >= arr[i] + k
            auto it = lower_bound(arr.begin() + i + 1, arr.end(), arr[i] + k);
            
            // All elements between index (i + 1) and (it - 1) 
            // have an absolute difference strictly less than k with arr[i]
            count += (it - (arr.begin() + i + 1));
        }
        
        return count;
    }
};