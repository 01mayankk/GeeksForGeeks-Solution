class Solution {
public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> result;
        int n = arr.size();
        int i = 0;
        int levelSize = 1; // Number of elements expected at the current level

        // Process elements level by level
        while (i < n) {
            vector<int> currentLevel;
            
            // Extract elements for the current level
            for (int j = 0; j < levelSize && i < n; j++, i++) {
                currentLevel.push_back(arr[i]);
            }
            
            // Sort the elements of the current level in ascending order
            sort(currentLevel.begin(), currentLevel.end());
            
            // Add sorted level to the result
            result.push_back(currentLevel);
            
            // The next level in a binary tree can have up to twice as many nodes
            levelSize *= 2;
        }

        return result;
    }
};