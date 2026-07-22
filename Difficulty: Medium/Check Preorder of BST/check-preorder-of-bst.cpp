class Solution {
  public:
    bool canRepresentBST(vector<int>& arr) {
        // Initialize root as the minimum possible integer
        int root = INT_MIN;
        stack<int> s;

        for (int x : arr) {
            // If we find a node in the right subtree that is smaller 
            // than the root of the current subtree, return false
            if (x < root) {
                return false;
            }

            // Keep removing items from stack that are smaller than x, 
            // making the last removed item the new root
            while (!s.empty() && s.top() < x) {
                root = s.top();
                s.pop();
            }

            // Push current element to stack
            s.push(x);
        }

        return true;
    }
};