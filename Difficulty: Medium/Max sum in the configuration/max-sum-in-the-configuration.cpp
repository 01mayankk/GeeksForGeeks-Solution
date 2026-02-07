class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();

        // Step 1: Calculate sum of array elements
        int arrSum = 0;
        for (int x : arr) {
            arrSum += x;
        }

        // Step 2: Calculate initial value of i*arr[i]
        int currVal = 0;
        for (int i = 0; i < n; i++) {
            currVal += i * arr[i];
        }

        // Initialize result with first configuration
        int maxVal = currVal;

        // Step 3: Compute values for remaining rotations
        for (int i = 1; i < n; i++) {
            /*
               Formula:
               R(i) = R(i-1) + arrSum - n * arr[n - i]
               arr[n-i] is the element that moves from end to front
            */
            currVal = currVal + arrSum - n * arr[n - i];

            // Update maximum value
            maxVal = max(maxVal, currVal);
        }

        return maxVal;
    }
};
