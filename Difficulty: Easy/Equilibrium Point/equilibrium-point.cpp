class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        
        int n = arr.size();
        
        // Step 1: Calculate total sum of array
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        int leftSum = 0;
        
        // Step 2: Traverse array
        for(int i = 0; i < n; i++)
        {
            // Remove current element from totalSum
            // Now totalSum acts as rightSum
            totalSum -= arr[i];
            
            // Check equilibrium condition
            if(leftSum == totalSum)
            {
                return i;   // 0-based index
            }
            
            // Add current element to leftSum
            leftSum += arr[i];
        }
        
        return -1;  // No equilibrium index found
    }
};