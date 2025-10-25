class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1; // store the index of floor

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == x) {
                ans = mid;      // possible answer
                start = mid + 1; // check if there is a later occurrence
            }
            else if (arr[mid] < x) {
                ans = mid;      // possible floor
                start = mid + 1; // try to find a larger element ≤ x
            }
            else {
                end = mid - 1;  // move left
            }
        }

        return ans; // if no floor found, remains -1
    }
};
