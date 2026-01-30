class Solution {
  public:
    
    // Helper function to check
    // whether books can be allocated to k students
    // such that the maximum pages assigned is <= mid
    bool canBeAllocated(vector<int>& arr, int k, int mid)
    {
        int studentCount = 1;   // Start by allocating to first student
        int pagesSum = 0;       // Pages allocated to current student
        
        for(int i = 0; i < arr.size(); i++)
        {
            // If a single book has more pages than mid,
            // allocation is impossible
            if(arr[i] > mid)
                return false;
            
            // If adding current book exceeds mid
            if(pagesSum + arr[i] > mid)
            {
                // Allocate book to next student
                studentCount++;
                pagesSum = arr[i];
                
                // If students exceed k, allocation fails
                if(studentCount > k)
                    return false;
            }
            else
            {
                // Allocate book to current student
                pagesSum += arr[i];
            }
        }
        
        // Allocation possible within k students
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        
        // If students are more than books, allocation impossible
        if(k > arr.size())
            return -1;
        
        int start = *max_element(arr.begin(), arr.end()); // Minimum possible answer
        int end = accumulate(arr.begin(), arr.end(), 0); // Maximum possible answer
        int ans = -1; // Stores final answer
        
        // Binary search on answer
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            // Check if allocation possible with max pages = mid
            if(canBeAllocated(arr, k, mid))
            {
                ans = mid;        // Store potential answer
                end = mid - 1;    // Try to minimize the maximum pages
            }
            else
            {
                start = mid + 1;  // Increase pages limit
            }
        }
        
        return ans;
    }
};
