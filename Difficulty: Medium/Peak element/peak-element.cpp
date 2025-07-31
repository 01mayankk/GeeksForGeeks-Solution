class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();

        // Check if first element is a peak
        if (n == 1 || arr[0] >= arr[1]) {
            return 0;
        }

        // Check if last element is a peak
        if (arr[n - 1] >= arr[n - 2]) {
            return n - 1;
        }

        // Check middle elements
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
                return i;
            }
        }

        return -1; // No peak found (should never reach here if array has at least one element)
    }
};
