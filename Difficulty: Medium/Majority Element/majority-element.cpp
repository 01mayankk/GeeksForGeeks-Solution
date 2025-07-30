class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int majority = arr.size() / 2 +1;
        sort(arr.begin(), arr.end());
        unordered_map<int, int>map;
        for(int i = 0; i < arr.size(); i++)
        {
            map[arr[i]]++;
        }
        
        for(auto& elem : map)
        {
            if(elem.second >= majority )
            {
                return elem.first;
            }
        }
        
        return -1;
    }
};