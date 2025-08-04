class Solution {
  public:
    // Kadane's algorithm to find the maximum sum subarray in 1D
    int kadane(vector<int>& arr) {
        int curr = arr[0], maxSum = arr[0];

        // Traverse the array from index 1 to end
        for (int i = 1; i < arr.size(); i++) {
            // Either take the current element or extend the previous subarray
            curr = max(arr[i], curr + arr[i]);

            // Update the overall maximum sum
            maxSum = max(maxSum, curr);
        }

        return maxSum;
    }

    // Function to find the maximum sum rectangle in a 2D matrix
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();        // Number of rows
        int m = mat[0].size();     // Number of columns
        int maxSum = INT_MIN;      // Initialize maxSum to the smallest integer

        // Iterate over all possible pairs of columns as left and right boundaries
        for (int left = 0; left < m; left++) {
            // Temporary array to store the sum of elements between left and right columns
            vector<int> temp(n, 0);

            for (int right = left; right < m; right++) {
                // Add elements of the current column 'right' to 'temp'
                for (int i = 0; i < n; i++) {
                    temp[i] += mat[i][right];
                }

                // Apply Kadane's algorithm on the 1D temp array to find max subarray sum
                // This effectively finds the maximum sum rectangle between columns left and right
                maxSum = max(maxSum, kadane(temp));
            }
        }

        // Return the overall maximum rectangle sum found
        return maxSum; 
    }
};
