class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);   // to store answers
        stack<int> st;            // stack to store potential next greater elements

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // If stack not empty, top is the next greater
            if (!st.empty()) {
                res[i] = st.top();
            }

            // Push current element for the next iteration
            st.push(arr[i]);
        }

        return res;
    }
};
