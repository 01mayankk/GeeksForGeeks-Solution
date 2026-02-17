#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to return precedence of operators
    int precedence(char ch) {
        
        // Highest precedence
        if(ch == '^')
            return 3;
        
        // Medium precedence
        else if(ch == '*' || ch == '/')
            return 2;
        
        // Lowest precedence
        else if(ch == '+' || ch == '-')
            return 1;
        
        // For '(' or invalid
        else
            return -1;
    }

    string infixToPostfix(string& s) {
        
        stack<char> st;     // Stack to store operators
        string result = ""; // Final postfix expression
        
        // Traverse the infix expression
        for(int i = 0; i < s.length(); i++) {
            
            char ch = s[i];
            
            // 1️⃣ If operand → directly add to result
            if(isalnum(ch)) {
                result += ch;
            }
            
            // 2️⃣ If '(' → push to stack
            else if(ch == '(') {
                st.push(ch);
            }
            
            // 3️⃣ If ')' → pop until '('
            else if(ch == ')') {
                
                while(!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                
                // Remove '(' from stack
                if(!st.empty())
                    st.pop();
            }
            
            // 4️⃣ If operator
            else {
                
                // Special case: Right associative operator (^)
                while(!st.empty() && 
                     (precedence(st.top()) > precedence(ch) ||
                     (precedence(st.top()) == precedence(ch) && ch != '^'))) {
                    
                    result += st.top();
                    st.pop();
                }
                
                st.push(ch);
            }
        }
        
        // 5️⃣ Pop remaining operators from stack
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};
