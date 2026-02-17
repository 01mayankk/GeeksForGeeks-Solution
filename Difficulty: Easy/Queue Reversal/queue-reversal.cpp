class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        
        stack<int> st;
        
        // Step 1: Push all elements from queue to stack
        while(!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        
        // Step 2: Push all elements back to queue
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
};
