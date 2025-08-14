class Solution {
  public:
    // Function to count reverse pairs between two sorted halves of the array
    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int count = 0;           // Stores the number of reverse pairs
        int right = mid + 1;     // Pointer for the right subarray
        
        // For each element in the left subarray
        for(int i = low; i <= mid; i++)
        {
            // Find the first element in the right subarray such that:
            // arr[i] > 2 * arr[right]
            // Since both halves are sorted, we move `right` pointer only forward
            while(right <= high && (arr[i] > 2LL * arr[right])) // 2LL to prevent overflow
                right++;
            
            // All elements before `right` in right half satisfy the condition
            count += right - (mid + 1);
        }
        return count;
    }

    // Standard merge step for merge sort
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;        // Temporary array to store sorted elements
        int left = low;          // Pointer for left subarray
        int right = mid + 1;     // Pointer for right subarray
        
        // Merge the two sorted halves
        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        // Copy remaining elements from left half (if any)
        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from right half (if any)
        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        
        // Copy sorted data back to original array
        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    // Modified merge sort to count reverse pairs
    int mergesort(vector<int> &arr, int low, int high)
    {
        int count = 0;  // Number of reverse pairs
        
        if(low >= high) // Base case: single element or empty range
            return count;
        
        int mid = (low + high) / 2;
        
        // Recursively sort and count in left half
        count += mergesort(arr, low, mid);
        
        // Recursively sort and count in right half
        count += mergesort(arr, mid + 1, high);
        
        // Count reverse pairs across the two halves
        count += countPairs(arr, low, mid, high);
        
        // Merge the two halves
        merge(arr, low, mid, high);
        
        return count;
    }

    // Main function to count reverse pairs in the array
    int countRevPairs(vector<int> &arr)
    {
        return mergesort(arr, 0, arr.size() - 1);
    }
};
