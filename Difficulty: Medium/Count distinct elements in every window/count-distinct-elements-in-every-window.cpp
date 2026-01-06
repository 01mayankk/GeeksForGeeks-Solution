class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {

        vector<int> result;                  // To store distinct count of each window
        unordered_map<int, int> freq;        // Frequency map for elements in current window

        // ------------------ STEP 1: Process first window ------------------
        // Add first k elements to the frequency map
        for (int i = 0; i < k; i++) {
            freq[arr[i]]++;                  // Increase frequency of current element
        }

        // Number of distinct elements in first window
        result.push_back(freq.size());

        // ------------------ STEP 2: Slide the window ------------------
        // i moves from k to end of array
        for (int i = k; i < arr.size(); i++) {

            // Remove the element that goes out of the window
            freq[arr[i - k]]--;              // Decrease its frequency
            if (freq[arr[i - k]] == 0) {
                freq.erase(arr[i - k]);      // Remove completely if frequency becomes 0
            }

            // Add the new element entering the window
            freq[arr[i]]++;                  // Increase frequency

            // Store current number of distinct elements
            result.push_back(freq.size());
        }

        return result;                       // Return result for all windows
    }
};
