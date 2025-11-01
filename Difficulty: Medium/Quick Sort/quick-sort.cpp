class Solution {
  public:
    // 🧩 Quick Sort function (recursive)
    void quickSort(vector<int>& arr, int low, int high) {
        // Base condition: only sort if low < high
        if (low < high) {
            
            // Step 1: Partition the array and get the pivot index
            int pi = partition(arr, low, high);
            
            // Step 2: Recursively sort the elements before pivot
            quickSort(arr, low, pi - 1);
            
            // Step 3: Recursively sort the elements after pivot
            quickSort(arr, pi + 1, high);
        }
    }

  public:
    // ⚙️ Partition function: places pivot element at its correct sorted position
    // and ensures all smaller elements are on left and greater ones on right
    int partition(vector<int>& arr, int low, int high) {
        
        int pivot = arr[high];  // Choose last element as pivot
        int i = (low - 1);      // 'i' marks the boundary of elements smaller than pivot
        
        // Traverse from low to high-1
        for (int k = low; k < high; k++) {
            
            // If current element is smaller than pivot
            if (arr[k] < pivot) {
                i++; // move boundary forward
                swap(arr[k], arr[i]); // swap smaller element to left side
            }
        }
        
        // Finally, place the pivot after all smaller elements
        swap(arr[i + 1], arr[high]);
        
        // Return pivot's final sorted index
        return (i + 1);
    }
};
