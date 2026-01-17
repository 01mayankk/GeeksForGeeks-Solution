class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;

        for(char ch : s) {
            // Push every character except closing bracket
            if(ch != ')') {
                st.push(ch);
            }
            else {
                // Found a closing bracket
                bool hasOperator = false;

                // Pop until opening bracket is found
                while(!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();

                    // Check if operator exists inside brackets
                    if(top == '+' || top == '-' || 
                       top == '*' || top == '/') {
                        hasOperator = true;
                    }
                }

                // Remove opening '('
                st.pop();

                // No operator means redundant brackets
                if(!hasOperator) {
                    return true;
                }
            }
        }
        return false;
    }
};
