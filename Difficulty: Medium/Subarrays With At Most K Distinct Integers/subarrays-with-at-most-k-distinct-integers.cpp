class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {

        int n = arr.size();  

        // Hash map to store frequency of each element
        // in the current sliding window
        unordered_map<int, int> freq;

        // Left pointer of the sliding window
        int left = 0;

        // Stores the total count of valid subarrays
        // long long is used to prevent overflow
        long long count = 0;

        // Right pointer expands the window
        for (int right = 0; right < n; right++) {

            // Step 1: Include current element into the window
            freq[arr[right]]++;

            // Step 2: If number of distinct elements exceeds k,
            // shrink the window from the left
            while (freq.size() > k) {

                // Reduce frequency of the element at 'left'
                freq[arr[left]]--;

                // If frequency becomes zero,
                // remove it from the map (no longer in window)
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }

                // Move left pointer to shrink window
                left++;
            }

            // Step 3:
            // At this point, window [left ... right]
            // has AT MOST k distinct elements
            //
            // Number of valid subarrays ending at 'right' =
            // (right - left + 1)
            //
            // All subarrays:
            // [left, right], [left+1, right], ..., [right, right]
            count += (right - left + 1);
        }

        // Return total count of valid subarrays
        return count;
    }
};
