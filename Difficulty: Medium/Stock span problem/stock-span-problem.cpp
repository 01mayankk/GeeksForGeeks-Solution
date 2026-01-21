class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);          // to store result
        stack<int> st;               // stack to store indices

        for (int i = 0; i < n; i++) {

            // Pop elements from stack while
            // current price is greater than or equal
            // to price at stack top index
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack is empty, price is greater than all previous prices
            span[i] = st.empty() ? (i + 1) : (i - st.top());

            // Push current index onto stack
            st.push(i);
        }

        return span;
    }
};
