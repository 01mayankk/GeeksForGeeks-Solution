class Solution {
public:
    // Helper function to count subarrays with at most k odd numbers
    int countAtMost(vector<int>& arr, int k) {
        int left = 0, oddCount = 0;
        long long result = 0;

        for (int right = 0; right < arr.size(); right++) {

            // If current element is odd, increase odd count
            if (arr[right] % 2 == 1) {
                oddCount++;
            }

            // Shrink window until oddCount <= k
            while (oddCount > k) {
                if (arr[left] % 2 == 1) {
                    oddCount--;
                }
                left++;
            }

            // All subarrays ending at 'right' and starting
            // from [left ... right] are valid
            result += (right - left + 1);
        }

        return result;
    }

    int countSubarrays(vector<int>& arr, int k) {

        // Exactly k odds = at most k odds - at most (k - 1) odds
        return countAtMost(arr, k) - countAtMost(arr, k - 1);
    }
};
