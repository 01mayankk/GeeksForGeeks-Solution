class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;                  // pointer at beginning
        int right = arr.size() - 1;    // pointer at end
        
        // loop until both pointers meet
        while(left < right) {
            
            // move left pointer forward if already 0
            while(left < right && arr[left] == 0) {
                left++;
            }
            
            // move right pointer backward if already 1
            while(left < right && arr[right] == 1) {
                right--;
            }
            
            // now arr[left] = 1 and arr[right] = 0 → swap needed
            if(left < right) {
                swap(arr[left], arr[right]);
                left++;    // move both pointers
                right--;
            }
        }
    }
};