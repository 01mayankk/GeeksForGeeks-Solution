class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // If k is greater than queue size, no change needed
        if(k > q.size())
        {
            return q;
        }
        
        int copy = k;   // Copy of k since we'll modify it
        
        stack<int> st;  // Stack to help reverse first k elements
        
        // Step 1: Remove first k elements from queue and push into stack
        // This reverses their order (LIFO property of stack)
        while(!q.empty() && copy > 0)
        {
            st.push(q.front());   // Push front element of queue into stack
            q.pop();              // Remove it from queue
            copy--;
        }
        
        // Step 2: Push stack elements back into queue
        // Since stack is LIFO, elements get reversed
        while(!st.empty())
        {
            q.push(st.top());  // Push top of stack to queue
            st.pop();
        }
        
        // Step 3: Move remaining (n-k) elements to the back of queue
        // This keeps their relative order same
        int rem = q.size() - k;
        
        while(!q.empty() && rem > 0)
        {
            int val = q.front();  // Take front element
            q.pop();              // Remove it
            q.push(val);          // Push it back to maintain order
            rem--;
        }
        
        return q;  // Return modified queue
    }
};
