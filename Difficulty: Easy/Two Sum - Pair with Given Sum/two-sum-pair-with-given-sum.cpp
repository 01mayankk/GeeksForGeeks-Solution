class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int component;
        unordered_map<int, int>map;
        
        for(int i = 0; i < arr.size(); i++)
        {
            component = target - arr[i];
            
            if(map.find(component) != map.end())
            {
                return true;
            }
            
            map[arr[i]] = i;
        }
        
        return false;
    }
};