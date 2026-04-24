class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st; // stack to store the resulting elements
        
        // Traverse each element from left to right
        for (int x : arr) {
            bool removed = false; // flag to check if current element gets removed
            
            // Continue resolving while:
            // 1. stack is not empty
            // 2. top element and current element have opposite signs
            while (!st.empty() && ((st.back() > 0 && x < 0) || (st.back() < 0 && x > 0))) {
                
                int top = st.back(); // get the top element of stack
                
                // Case 1: Both have equal absolute values
                // → remove both elements
                if (abs(top) == abs(x)) {
                    st.pop_back();   // remove stack top
                    removed = true; // current element also removed
                    break;          // stop further processing
                }
                
                // Case 2: Stack top has larger absolute value
                // → current element is removed
                else if (abs(top) > abs(x)) {
                    removed = true; // current element is destroyed
                    break;          // no further checks needed
                }
                
                // Case 3: Current element has larger absolute value
                // → remove stack top and continue checking
                else {
                    st.pop_back(); // remove weaker stack element
                    // continue loop to check with next stack element
                }
            }
            
            // If current element survived all collisions,
            // push it into the stack
            if (!removed) {
                st.push_back(x);
            }
        }
        
        // Final stack contains the reduced array
        return st;
    }
};