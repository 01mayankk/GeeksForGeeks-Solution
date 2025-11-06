class Solution {
  public:
    int transitionPoint(vector<int>& arr) {
        // The array 'arr' consists of only 0s followed by 1s.
        // We need to find the index of the **first occurrence of 1**.
        // If there is no 1, return -1.

        int start = 0;
        int end = arr.size() - 1;
        int found = -1; // Will store the index of the first 1 if found

        // Binary search approach
        while (start <= end) {
            int mid = start + (end - start) / 2; // Prevents integer overflow

            // Case 1: Found a 1 → possible transition point
            // But we still need to check if there's another 1 on the left.
            if (arr[mid] == 1) {
                found = mid;   // Store this index as a potential answer
                end = mid - 1; // Move left to find an earlier 1
            }
            // Case 2: Current element is 0
            // Since the array is sorted (0s before 1s),
            // all elements before mid are also 0.
            else if (arr[mid] < 1) {
                start = mid + 1; // Move right to find the first 1
            }
        }

        // Return the first occurrence of 1 if found, otherwise -1
        return found;
    }
};
