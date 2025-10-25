class Solution {
  public:
  
    int findFirst(vector<int>& arr, int x)
    {
        int start = 0;
        int end = arr.size() - 1;
        int found = -1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(arr[mid] == x)
            {
                found = mid;
                end = mid - 1;
            }
            else if(arr[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        return found;
    }
    
    int findLast(vector<int>& arr, int x)
    {
        int start = 0;
        int end = arr.size() - 1;
        int found = -1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(arr[mid] == x)
            {
                found = mid;
                start = mid + 1;
            }
            else if(arr[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        return found;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        
        return { findFirst(arr, x) ,
        findLast(arr, x) };
    }
};