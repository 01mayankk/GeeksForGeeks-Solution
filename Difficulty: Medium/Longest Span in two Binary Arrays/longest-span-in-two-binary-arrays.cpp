class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        
        int n = a1.size();
        
        // Map to store first occurrence of each prefix sum
        unordered_map<int, int> mp;
        
        int prefixSum = 0;   // Running sum of difference array
        int maxLen = 0;      // Stores maximum span length
        
        for(int i = 0; i < n; i++) {
            
            // Create difference on the fly
            prefixSum += (a1[i] - a2[i]);
            
            // Case 1: If prefixSum becomes 0
            // Means subarray from 0 to i has equal sum
            if(prefixSum == 0) {
                maxLen = i + 1;
            }
            
            // Case 2: If prefixSum seen before
            // Means subarray between previous index+1 and i has sum 0
            if(mp.find(prefixSum) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixSum]);
            }
            else {
                // Store first occurrence only
                mp[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};