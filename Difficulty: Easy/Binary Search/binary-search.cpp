class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        int result = -1; // to store the first occurrence index
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(arr[mid] == k) {
                result = mid;       // store index
                right = mid - 1;    // search in left half for earlier occurrence
            }
            else if(arr[mid] < k) {
                left = mid + 1;     // go right
            }
            else {
                right = mid - 1;    // go left
            }
        }
        
        return result;
    }
};
