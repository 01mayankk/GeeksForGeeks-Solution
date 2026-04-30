class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();

    // We only need to check non-leaf nodes
    // Last non-leaf node = (n - 2) / 2
    for (int i = 0; i <= (n - 2) / 2; i++) {

        // Calculate left and right child indices
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If left child exists and is greater than parent → not a max heap
        if (left < n && arr[i] < arr[left])
            return false;

        // If right child exists and is greater than parent → not a max heap
        if (right < n && arr[i] < arr[right])
            return false;
    }

    // If all parent-child relationships satisfy max heap property
    return true;
    }
};
