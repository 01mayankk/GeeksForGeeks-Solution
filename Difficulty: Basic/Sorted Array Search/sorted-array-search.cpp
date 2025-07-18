class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        // code here
        int start = 0;
        int end = arr.size() - 1;
        
        while(start <= end)
        {
            int mid = start + (end - start ) / 2;
            
            if(arr[mid] == k)
            {
                return true;
            }
            else if(arr[mid] < k)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        return false;
    }
};