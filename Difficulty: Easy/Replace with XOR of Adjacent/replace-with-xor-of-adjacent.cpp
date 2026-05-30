class Solution {
public:

    void replaceElements(vector<int>& arr) {

        int n = arr.size();

        // Create a copy of the original array
        // because every new value must be computed
        // using the original adjacent elements.
        vector<int> originalArray = arr;

        // First element:
        // arr[0] = arr[0] ^ arr[1]
        arr[0] =
            originalArray[0] ^
            originalArray[1];

        // Middle elements:
        // arr[i] = arr[i-1] ^ arr[i+1]
        for (int index = 1; index < n - 1; index++) {

            arr[index] =
                originalArray[index - 1] ^
                originalArray[index + 1];
        }

        // Last element:
        // arr[n-1] = arr[n-2] ^ arr[n-1]
        arr[n - 1] =
            originalArray[n - 2] ^
            originalArray[n - 1];
    }
};