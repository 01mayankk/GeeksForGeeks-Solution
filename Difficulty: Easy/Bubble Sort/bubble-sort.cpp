class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();  // total number of elements

        // Outer loop for each pass
        for (int i = 0; i < n; i++) {
            bool swapped = false;  // flag to track if any swap happens in this pass

            // Inner loop: compare adjacent elements
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);  // swap if elements are in wrong order
                    swapped = true;           // mark that a swap happened
                }
            }

            // If no swaps occurred in this pass, array is already sorted
            if (!swapped) {
                break;  // exit early
            }
        }
    }
};
