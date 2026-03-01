// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        
        int j = 0;                  // Pointer to place the next non-zero element
        int n = arr.size();         // Get size of the array
        
        // Traverse the array
        for(int i = 0; i < n; i++) {
            
            // If current element is non-zero
            if(arr[i] != 0) {
                
                // Place it at position j
                arr[j++] = arr[i];
            }
        }
        
        // After placing all non-zero elements,
        // fill remaining positions with 0
        while(j < n) {
            arr[j++] = 0;
        }
    }
};