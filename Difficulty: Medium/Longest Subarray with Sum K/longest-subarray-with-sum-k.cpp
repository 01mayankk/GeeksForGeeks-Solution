class Solution {
  public:
  
    int longestSubarray(vector<int>& arr, int k) {
        
        // Map to store:
        // prefixSum -> first index where it appeared
        unordered_map<long long, int> mp;
        
        long long prefixSum = 0;
        
        // Stores answer (maximum length)
        int maxLen = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            
            // Add current element to prefix sum
            prefixSum += arr[i];
            
            // Case 1:
            // If prefix sum itself becomes k,
            // then subarray from 0 to i has sum = k
            if (prefixSum == k) {
                maxLen = i + 1;
            }
            
            // Case 2:
            // If (prefixSum - k) existed before,
            // then subarray between those indices has sum = k
            long long remaining = prefixSum - k;
            
            if (mp.find(remaining) != mp.end()) {
                
                // Length of subarray
                int len = i - mp[remaining];
                
                // Update maximum length
                maxLen = max(maxLen, len);
            }
            
            // Store prefix sum only first time
            // because we want longest subarray
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};