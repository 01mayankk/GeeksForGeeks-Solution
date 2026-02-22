class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        // This map will store:
        // key   -> prefix XOR value
        // value -> frequency of that prefix XOR
        unordered_map<int, int> mp;  
        
        int prefixXor = 0;   // stores XOR from index 0 to current index
        long count = 0;      // stores final answer (number of valid subarrays)
        
        // Very important:
        // If prefixXor itself becomes equal to k,
        // then prefixXor ^ k = 0.
        // So we initialize frequency of 0 as 1,
        // meaning an empty prefix before starting.
        mp[0] = 1;
        
        // Traverse the array
        for(int i = 0; i < arr.size(); i++)
        {
            // Step 1:
            // Update prefixXor by XOR-ing current element
            prefixXor ^= arr[i];
            
            /*
              Step 2:
              If there exists some previous prefix XOR such that:
              
              previousPrefixXor ^ prefixXor = k
              
              Then:
              previousPrefixXor = prefixXor ^ k
              
              So we check if (prefixXor ^ k) exists in map.
            */
            if(mp.find(prefixXor ^ k) != mp.end())
            {
                // If found, add its frequency to count
                count += mp[prefixXor ^ k];
            }
            
            // Step 3:
            // Store/update frequency of current prefixXor
            mp[prefixXor]++;
        }
        
        // Return total subarrays having XOR = k
        return count;
    }
};