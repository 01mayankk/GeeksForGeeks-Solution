class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int start = 0;
        int end = arr.size() - 1;  // use size(), not arr.end()

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Case 1: Found the key
            if (arr[mid] == key)
                return mid;

            // Case 2: Left half is sorted
            if (arr[start] <= arr[mid]) {
                // Check if key lies within the left sorted portion
                if (key >= arr[start] && key < arr[mid])
                    end = mid - 1;  // search left half
                else
                    start = mid + 1;  // search right half
            }
            // Case 3: Right half is sorted
            else {
                // Check if key lies within the right sorted portion
                if (key > arr[mid] && key <= arr[end])
                    start = mid + 1;  // search right half
                else
                    end = mid - 1;  // search left half
            }
        }

        // If key not found
        return -1;
    }
};
