// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // Get the size of the array
        int len = arr.size();
        
        // Store the last element, since it will move to the front
        int last = arr[len - 1];
        
        // Shift all elements one position to the right
        // Start from the end to avoid overwriting values
        for(int i = len - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        
        // Place the last element at the first position
        arr[0] = last;
    }
};
