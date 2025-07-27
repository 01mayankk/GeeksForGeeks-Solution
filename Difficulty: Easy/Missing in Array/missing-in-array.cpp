class Solution {
  public:
    int missingNum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        if (arr[0] != 1) {
            return 1;
        }
        
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] + 1 != arr[i + 1]) {
                return arr[i] + 1;
            }
        }

        // Return the next number if all previous are in sequence
        return arr.back() + 1;
    }
};
