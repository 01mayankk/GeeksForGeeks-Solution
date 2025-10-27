class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> result;
        if (arr1.empty() || arr2.empty() || k <= 0) return result;
        
        // Min heap storing: {sum, i, j}
        // where i and j are indices in arr1 and arr2 respectively
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Push first k pairs with arr2[0]
        // (only need to go up to k because larger i gives larger sums)
        for (int i = 0; i < arr1.size() && i < k; i++) {
            minHeap.push({arr1[i] + arr2[0], i, 0});
        }
        
        // Extract k smallest pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            
            int i = top[1];
            int j = top[2];
            result.push_back({arr1[i], arr2[j]});
            
            // Move to next element in arr2 for the same i
            if (j + 1 < arr2.size()) {
                minHeap.push({arr1[i] + arr2[j + 1], i, j + 1});
            }
        }
        
        return result;
    }
};
