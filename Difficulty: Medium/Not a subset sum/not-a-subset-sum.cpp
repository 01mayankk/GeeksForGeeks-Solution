class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // res stores the smallest value
        // that we currently cannot form
        long long res = 1;
        
        // Traverse all elements
        for(int i = 0; i < arr.size(); i++) {
            
            // If current element is greater than res,
            // then res cannot be formed
            if(arr[i] > res) {
                break;
            }
            
            // Otherwise, we can extend the range
            // of possible sums till res + arr[i] - 1
            res += arr[i];
        }
        
        // res is the smallest number
        // that cannot be represented
        return res;
    }
};