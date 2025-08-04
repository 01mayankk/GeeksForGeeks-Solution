class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        return *max_element(arr.begin(), arr.end());
    }
};
