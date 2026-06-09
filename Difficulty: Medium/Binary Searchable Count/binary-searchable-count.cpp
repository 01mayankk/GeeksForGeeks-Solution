class Solution {
public:
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        // Check each element of the array
        for (int i = 0; i < n; i++) {

            // Current element to search for
            int target = arr[i];

            // Initialize binary search boundaries
            int left = 0;
            int right = n - 1;

            // Perform standard binary search on the given array
            while (left <= right) {

                // Find middle index
                int mid = left + (right - left) / 2;

                // Element found
                if (arr[mid] == target) {
                    count++;
                    break;
                }

                // Move to left half
                if (arr[mid] > target) {
                    right = mid - 1;
                }
                // Move to right half
                else {
                    left = mid + 1;
                }
            }
        }

        // Return the number of binary searchable elements
        return count;
    }
};