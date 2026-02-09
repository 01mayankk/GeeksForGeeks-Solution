class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        
        int start = 0;
        int end = arr.size() - 1;
        
        // Binary search to find the index of the minimum element
        while (start < end) {
            
            // Mid index
            int mid = start + (end - start) / 2;
            
            /*
             If arr[mid] > arr[end], it means:
             - The minimum element lies in the right half
             - Because the right part is unsorted due to rotation
            */
            if (arr[mid] > arr[end]) {
                start = mid + 1;
            }
            /*
             Else:
             - Minimum element could be at mid or in the left half
             - So we reduce the search space to left
            */
            else {
                end = mid;
            }
        }
        
        /*
         At the end of the loop:
         - start == end
         - This index points to the minimum element
         - Number of rotations = index of minimum element
        */
        return start;
    }
};
