class Solution {
public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        
        int count = 0;   // Final answer
        int len = 1;     // Length of current increasing subarray
        
        for (int i = 1; i < n; i++) {
            // If current element is greater than previous → increasing
            if (arr[i] > arr[i - 1]) {
                len++;  
                
                // Add number of new subarrays ending at index i
                // Example: len = 3 → add 2 ([prev,i], [start,...,i])
                count += (len - 1);
            } 
            else {
                // Reset length when sequence breaks
                len = 1;
            }
        }
        
        return count;
    }
};