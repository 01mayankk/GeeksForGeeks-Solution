class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int start = 0;
        int end = arr.size() - 1;

        // Standard binary search loop
        while (start <= end) {

            // Find mid safely to avoid overflow
            int mid = start + (end - start) / 2;

            // If key is found at mid
            if (arr[mid] == key) {
                return mid;
            }

            // Check if left half is sorted
            if (arr[start] <= arr[mid]) {

                // If key lies in the sorted left half
                if (key >= arr[start] && key < arr[mid]) {
                    end = mid - 1;   // Search in left half
                } 
                else {
                    start = mid + 1; // Search in right half
                }
            }
            // Otherwise, right half must be sorted
            else {

                // If key lies in the sorted right half
                if (key > arr[mid] && key <= arr[end]) {
                    start = mid + 1; // Search in right half
                } 
                else {
                    end = mid - 1;   // Search in left half
                }
            }
        }

        // Key not found
        return -1;
    }
};
