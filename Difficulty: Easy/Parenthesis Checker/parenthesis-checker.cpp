class Solution {
  public:
    bool isBalanced(string& s) {
        
        // Stack to keep track of opening brackets
        stack<char> st;
        
        // Traverse each character in string
        for(char ch : s)
        {
            // If it is an opening bracket, push into stack
            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                // If closing bracket appears and stack is empty,
                // there is no corresponding opening bracket
                if(st.empty())
                    return false;
                
                // Get the top element (last unmatched opening bracket)
                char top = st.top();
                st.pop();  // Remove it as we are trying to match it
                
                // Check if current closing bracket matches the opening one
                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '['))
                {
                    return false;  // Mismatch found
                }
            }
        }
        
        // If stack is empty, all brackets were matched properly
        // If not empty, some opening brackets were not closed
        return st.empty();
    }
};