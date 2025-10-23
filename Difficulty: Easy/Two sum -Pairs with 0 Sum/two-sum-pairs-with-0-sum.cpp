class Solution {
public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        vector<vector<int>> result;

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        // Step 2: Two-pointer traversal
        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == 0) {
                // Found a valid pair
                result.push_back({arr[left], arr[right]});

                int leftVal = arr[left];
                int rightVal = arr[right];

                // Step 3: Skip duplicates to avoid repeating pairs
                while (left < right && arr[left] == leftVal) left++;
                while (left < right && arr[right] == rightVal) right--;
            }
            else if (sum < 0) {
                // If sum < 0, we need a bigger value → move left forward
                left++;
            }
            else {
                // If sum > 0, we need a smaller value → move right backward
                right--;
            }
        }

        return result;
    }
};
