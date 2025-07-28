class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        sort(arr.begin(), arr.end(), greater<int>());
        
        vector<int>ans;
        int left = 0;
        int right = arr.size() - 1;
        for(int i = 0; i < arr.size(); i++)
        {
            if(i % 2 == 0)
            {
                ans.push_back(arr[left]);
                left++;
            }
            else
            {
                ans.push_back(arr[right]);
                right--;
            }
            
        }
        
        return ans;
    }
};
