class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // Step 1: Create a set from the array elements
        // The set will automatically remove duplicates and store elements in sorted order
        set<int> s(arr.begin(), arr.end());
        
        // Step 2: Initialize variable to store the missing number
        // Using INT_MIN as a placeholder (will change once we find the missing number)
        int missing = INT_MIN;
        
        // Step 3: Iterate through positive numbers starting from 1
        // We only need to check up to s.size() + 1 (to handle cases like [1,2,3] → missing = 4)
        for (int i = 1; i <= s.size(); i++) {
            
            // Step 4: Check if 'i' exists in the set
            // If 'i' is not found, that means it's the smallest missing positive number
            if (s.find(i) == s.end()) {
                missing = i; // store the missing number
                break;        // exit loop as we found the first missing one
            }
        }
        
        // Step 5: If all numbers from 1 to s.size() are present,
        // then the smallest missing number is the next integer (s.size() + 1)
        if (missing == INT_MIN) {
            missing = s.size() + 1;
        }
        
        // Step 6: Return the smallest missing positive number
        return missing;
    }
};
