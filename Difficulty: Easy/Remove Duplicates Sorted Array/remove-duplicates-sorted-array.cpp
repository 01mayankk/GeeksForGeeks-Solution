class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        set<int>nums(arr.begin(), arr.end());
        
        arr.clear();
        
        for(auto& elem: nums)
        {
            arr.push_back(elem);
        }
        
        return arr;
        
        
    }
};