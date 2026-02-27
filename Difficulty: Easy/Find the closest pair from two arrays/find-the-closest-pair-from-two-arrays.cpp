class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        
        int n = arr1.size();
        int m = arr2.size();
        
        // Pointer i for arr1 (start from beginning)
        int i = 0;
        
        // Pointer j for arr2 (start from end)
        int j = m - 1;
        
        // To store minimum difference
        long long minDiff = LLONG_MAX;
        
        // To store result pair
        vector<int> result(2);
        
        // Traverse both arrays
        while(i < n && j >= 0) {
            
            long long sum = (long long)arr1[i] + arr2[j];
            long long diff = llabs(sum - x);
            
            // Update minimum difference and result pair
            if(diff < minDiff) {
                minDiff = diff;
                result[0] = arr1[i];
                result[1] = arr2[j];
            }
            
            // If sum is greater than x → decrease sum
            if(sum > x) {
                j--;
            }
            // If sum is less than x → increase sum
            else {
                i++;
            }
        }
        
        return result;
    }
};