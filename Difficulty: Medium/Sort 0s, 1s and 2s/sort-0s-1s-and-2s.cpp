class Solution {
public:
    void sort012(vector<int>& arr) {

        // 'low'  -> boundary for 0s (elements before low are all 0)
        // 'mid'  -> current element being processed
        // 'high' -> boundary for 2s (elements after high are all 2)
        int low = 0, mid = 0, high = arr.size() - 1;

        // Process elements until mid crosses high
        while (mid <= high) {

            // Case 1: current element is 0
            if (arr[mid] == 0) {
                // Swap current element with the element at 'low'
                swap(arr[low], arr[mid]);

                // Move both pointers forward
                low++;
                mid++;
            }

            // Case 2: current element is 1
            else if (arr[mid] == 1) {
                // 1 is already in correct position
                mid++;
            }

            // Case 3: current element is 2
            else {
                // Swap current element with the element at 'high'
                swap(arr[mid], arr[high]);

                // Move 'high' pointer backward
                // Do NOT increment mid because swapped value
                // from the end needs to be checked
                high--;
            }
        }
    }
};
