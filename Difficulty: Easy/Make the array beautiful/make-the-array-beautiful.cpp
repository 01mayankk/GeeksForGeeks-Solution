class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        
        // Stack-like vector to store beautiful array elements
        vector<int> result;
        
        // Traverse the array
        for(int i = 0; i < arr.size(); i++) {
            
            // If result is not empty
            if(!result.empty()) {
                
                // Check signs of current element and last element
                // If one is negative and other is non-negative,
                // remove the previous element
                if((result.back() >= 0 && arr[i] < 0) ||
                   (result.back() < 0 && arr[i] >= 0)) {
                    
                    result.pop_back();
                }
                else {
                    // Same sign -> keep current element
                    result.push_back(arr[i]);
                }
            }
            else {
                // First element always gets added
                result.push_back(arr[i]);
            }
        }
        
        return result;
    }
};