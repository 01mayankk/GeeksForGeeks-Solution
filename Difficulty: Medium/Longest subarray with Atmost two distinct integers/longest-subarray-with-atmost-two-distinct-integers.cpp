class Solution {
  public:
    int totalElements(vector<int> &arr) {
        
        int n = arr.size();
        
        // Map to store frequency of elements in current window
        unordered_map<int, int> freq;
        
        int left = 0;          // Left pointer of sliding window
        int maxLen = 0;        // To store maximum length
        
        // Traverse using right pointer
        for(int right = 0; right < n; right++) {
            
            // Include current element into window
            freq[arr[right]]++;
            
            // If more than 2 distinct elements, shrink window
            while(freq.size() > 2) {
                
                // Reduce frequency of left element
                freq[arr[left]]--;
                
                // If frequency becomes 0, remove from map
                if(freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                
                // Move left pointer forward
                left++;
            }
            
            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};