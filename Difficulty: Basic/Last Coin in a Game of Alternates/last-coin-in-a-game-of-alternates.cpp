class Solution {
  public:
    int coin(vector<int>& arr) {
        
        // Two pointers for the beginning and end of the array
        int left = 0;
        int right = arr.size() - 1;
        
        // Continue removing coins until only one coin remains
        while (left < right) {
            
            // Players always pick the larger coin
            // from the two available ends
            
            if (arr[left] >= arr[right]) {
                // Remove the left coin
                left++;
            } else {
                // Remove the right coin
                right--;
            }
        }
        
        // The remaining coin is the answer
        return arr[left];
    }
};