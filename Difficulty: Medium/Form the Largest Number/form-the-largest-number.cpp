class Solution {
public:

    // Static comparator function
    static bool compare(string &a, string &b) {
        // Compare concatenated results
        return (a + b) > (b + a);
    }

    string findLargest(vector<int> &arr) {
        
        int n = arr.size();
        
        // Step 1: Convert integers to strings
        vector<string> nums;
        for(int i = 0; i < n; i++) {
            nums.push_back(to_string(arr[i]));
        }
        
        // Step 2: Sort using custom comparator
        sort(nums.begin(), nums.end(), compare);
        
        // Step 3: Edge Case
        // If the largest element is "0", then all are zeros
        if(nums[0] == "0") {
            return "0";
        }
        
        // Step 4: Concatenate the result
        string result = "";
        for(int i = 0; i < n; i++) {
            result += nums[i];
        }
        
        return result;
    }
};