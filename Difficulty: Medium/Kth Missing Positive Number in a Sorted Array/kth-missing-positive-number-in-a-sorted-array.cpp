class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        
        int low = 0, high = n - 1;

        // Binary search to find first index where missing numbers >= k
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Number of missing positives before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // After binary search, low is the position
        // kth missing number = low + k
        return low + k;
    }
};
