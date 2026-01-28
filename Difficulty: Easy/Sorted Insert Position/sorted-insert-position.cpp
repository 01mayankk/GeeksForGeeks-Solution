class Solution {
public:
    int searchInsertK(vector<int> &arr, int k) {
        
        // start and end define the current search space
        int start = 0;
        int end = arr.size() - 1;

        // Binary search loop
        while (start <= end) {

            // Calculate mid safely to avoid overflow
            int mid = start + (end - start) / 2;

            // Case 1: If k is found, return its index
            if (arr[mid] == k) {
                return mid;
            }

            // Case 2: If k is greater than mid element,
            // it must lie in the right half
            else if (arr[mid] < k) {
                start = mid + 1;
            }

            // Case 3: If k is smaller than mid element,
            // it must lie in the left half
            else {
                end = mid - 1;
            }
        }

        /*
        If k is not found:
        - 'start' points to the first index where arr[start] > k
        - All elements before 'start' are smaller than k
        Hence, 'start' is the correct position to insert k
        */

        return start;
    }
};
