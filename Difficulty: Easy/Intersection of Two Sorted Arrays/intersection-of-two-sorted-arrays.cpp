class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        
        int n = a.size();
        int m = b.size();
        
        int i = 0, j = 0;  // two pointers
        
        vector<int> result;
        
        // Traverse both arrays
        while (i < n && j < m) {
            
            // If both elements are equal → common element found
            if (a[i] == b[j]) {
                
                // Add only if it's not duplicate in result
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                
                i++;
                j++;
            }
            
            // If element in 'a' is smaller → move i forward
            else if (a[i] < b[j]) {
                i++;
            }
            
            // If element in 'b' is smaller → move j forward
            else {
                j++;
            }
        }
        
        return result;
    }
};