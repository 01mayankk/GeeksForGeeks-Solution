class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int, int>map;
        
        vector<int>nums;
        for(int i = 0; i < arr.size(); i++)
        {
            map[arr[i]]++;
        }
        
        for(auto& elem : map)
        {
            if(elem.second == 2)
            {
                nums.push_back(elem.first);
            }
        }
        
        return nums;
    }
};