class Solution {
public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        
        vector<int> result;
        
        // Min heap (smallest element on top)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < arr.size(); i++) {
            
            // Step 1: Add current element
            minHeap.push(arr[i]);
            
            // Step 2: Keep only k largest elements
            if (minHeap.size() > k) {
                minHeap.pop(); // remove smallest
            }
            
            // Step 3: Decide answer
            if (minHeap.size() < k) {
                result.push_back(-1);
            } else {
                result.push_back(minHeap.top()); // kth largest
            }
        }
        
        return result;
    }
};