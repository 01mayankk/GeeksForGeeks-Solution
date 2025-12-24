class Solution {
public:  // Add public access specifier
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int count = 0;
        
        // Approach: Use binary search to find pivot, then count in both parts
        
        // Step 1: Find the pivot point (index of minimum element)
        // The pivot is where the array is rotated
        int pivot = findPivot(arr, n);
        
        // Step 2: Count elements <= x in the left part [0 to pivot-1]
        // This part contains larger elements in sorted order
        if (pivot > 0) {
            count += countInSortedArray(arr, 0, pivot - 1, x);
        }
        
        // Step 3: Count elements <= x in the right part [pivot to n-1]
        // This part contains smaller elements in sorted order
        count += countInSortedArray(arr, pivot, n - 1, x);
        
        return count;
    }
    
private:
    // Helper function to find the pivot (index of minimum element)
    int findPivot(vector<int>& arr, int n) {
        int left = 0, right = n - 1;
        
        // If array is not rotated
        if (arr[left] <= arr[right]) {
            return 0;
        }
        
        // Binary search for pivot
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid is the pivot
            // Pivot is the point where arr[mid] > arr[mid+1]
            if (mid < n - 1 && arr[mid] > arr[mid + 1]) {
                return mid + 1;
            }
            
            // Check if previous element is the pivot
            if (mid > 0 && arr[mid - 1] > arr[mid]) {
                return mid;
            }
            
            // Decide which half to search
            // If left part is sorted, pivot must be in right part
            if (arr[left] <= arr[mid]) {
                left = mid + 1;
            } else {
                // Pivot is in left part
                right = mid - 1;
            }
        }
        
        return 0;
    }
    
    // Helper function to count elements <= x in a sorted array range
    int countInSortedArray(vector<int>& arr, int start, int end, int x) {
        // If the smallest element in this range is > x, count is 0
        if (arr[start] > x) {
            return 0;
        }
        
        // If the largest element in this range is <= x, all elements count
        if (arr[end] <= x) {
            return end - start + 1;
        }
        
        // Binary search to find the rightmost element <= x
        int left = start, right = end;
        int result = start - 1; // Initialize to start-1 in case no element is found
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] <= x) {
                result = mid; // Update result
                left = mid + 1; // Search in right half for larger valid elements
            } else {
                right = mid - 1; // Search in left half
            }
        }
        
        // Count is: (index of rightmost element <= x) - start + 1
        return result - start + 1;
    }
};