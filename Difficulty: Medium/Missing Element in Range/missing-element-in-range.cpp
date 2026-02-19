#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        
        vector<int> ans;   // To store missing numbers
        
        // Step 1: Store all elements of array into unordered_set
        // so that we can check existence in O(1) time
        unordered_set<int> s;
        
        for(int i = 0; i < arr.size(); i++) {
            s.insert(arr[i]);
        }
        
        // Step 2: Iterate from low to high
        for(int num = low; num <= high; num++) {
            
            // Step 3: If number is not found in set, it is missing
            if(s.find(num) == s.end()) {
                ans.push_back(num);
            }
        }
        
        // Step 4: Return missing numbers (already sorted)
        return ans;
    }
};
