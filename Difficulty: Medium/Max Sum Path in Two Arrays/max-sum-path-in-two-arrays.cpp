class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        int m = a.size(), n = b.size();
        
        // Variables to store the sum of elements between intersection points
        int sumA = 0, sumB = 0;
        int totalSum = 0;
        
        // Traverse both arrays simultaneously using a two-pointer approach
        while (i < m && j < n) {
            if (a[i] < b[j]) {
                sumA += a[i++];
            } 
            else if (b[j] < a[i]) {
                sumB += b[j++];
            } 
            else { // Intersection point found
                // Take the maximum sum segment accumulated so far,
                // and add the common element (counted only once)
                totalSum += max(sumA, sumB) + a[i];
                
                // Reset segment sums for the next path segment
                sumA = 0;
                sumB = 0;
                i++;
                j++;
            }
        }
        
        // Collect remaining elements from array a, if any
        while (i < m) {
            sumA += a[i++];
        }
        
        // Collect remaining elements from array b, if any
        while (j < n) {
            sumB += b[j++];
        }
        
        // Add the maximum of the final remaining segments
        totalSum += max(sumA, sumB);
        
        return totalSum;
    }
};