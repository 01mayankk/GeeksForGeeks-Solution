class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0;          // left pointer of window
        int zeroCount = 0;     // number of zeros in current window
        int maxLen = 0;        // answer

        // expand the window using right pointer
        for (int right = 0; right < arr.size(); right++) {
            
            // if current element is 0, we need one flip
            if (arr[right] == 0)
                zeroCount++;

            // if flips exceed k, shrink window from left
            while (zeroCount > k) {
                if (arr[left] == 0)
                    zeroCount--;
                left++;
            }

            // update maximum window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
