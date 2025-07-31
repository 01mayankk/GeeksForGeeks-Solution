class Solution {
public:
    // Helper function to reverse a portion of the array from index 'start' to 'end'
    void reverse(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]); // Swap the elements at the start and end
            start++;
            end--;
        }
    }

    // Function to rotate the array by 'd' elements in counter-clockwise direction
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size(); // Get the size of the array

        // Edge case: if the array is empty or no rotation is needed
        if (n == 0 || d == 0) return;

        // In case d > n, we use modulo to avoid extra rotations
        d = d % n;

        // Step 1: Reverse the first 'd' elements
        reverse(arr, 0, d - 1);

        // Step 2: Reverse the remaining 'n - d' elements
        reverse(arr, d, n - 1);

        // Step 3: Reverse the entire array to get the final rotated form
        reverse(arr, 0, n - 1);
    }
};
