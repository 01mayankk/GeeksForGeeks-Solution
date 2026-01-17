class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }

        // Result array initialized with -1
        vector<int> result(n, -1);

        // Stack to store indices of elements
        stack<int> st;

        // Step 2: Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop elements whose frequency is
            // less than or equal to current element
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }

            // If stack is not empty, top element
            // has greater frequency
            if (!st.empty()) {
                result[i] = arr[st.top()];
            }

            // Push current index to stack
            st.push(i);
        }

        return result;
    }
};
