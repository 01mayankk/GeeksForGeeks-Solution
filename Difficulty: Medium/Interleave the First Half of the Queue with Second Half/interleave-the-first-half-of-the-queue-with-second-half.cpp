class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();

        // If queue has only 0 or 1 element, no rearrangement needed
        if (n <= 1)
            return;

        stack<int> st;

        // Step 1: Push first half of queue into stack
        for (int i = 0; i < n / 2; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Push stack elements back into queue
        // This reverses the first half
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move first half of queue to the back
        // This helps restore correct order
        for (int i = 0; i < n / 2; i++) {
            q.push(q.front());
            q.pop();
        }

        // Step 4: Again push first half into stack
        for (int i = 0; i < n / 2; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 5: Interleave elements
        // One from stack (first half), one from queue (second half)
        while (!st.empty()) {
            q.push(st.top());
            st.pop();

            q.push(q.front());
            q.pop();
        }
    }
};
