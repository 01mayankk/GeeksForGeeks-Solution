class Solution {
public:
    int findMaximum(vector<int> &arr) {
        // Initialize left and right pointers for binary search
        int left = 0, right = arr.size() - 1;
        
        // Continue searching until left and right converge
        while(left < right) {
            // Find the middle index (safe from overflow)
            int mid = left + (right - left) / 2;
            
            // Check the slope at mid
            if(arr[mid] < arr[mid + 1]) {
                // We are on the increasing part of the bitonic array
                // So the peak must be to the right of mid
                left = mid + 1;
            } else {
                // We are on the decreasing part of the bitonic array
                // The peak could be at mid or to the left
                right = mid;
            }
        }
        
        // When left == right, we've found the peak (bitonic point)
        return arr[left];
    }
};
