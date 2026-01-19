class Solution {
  public:
    string removeKdig(string &s, int k) {
        int n = s.size();
        
        // Stack to store the digits of the final number
        string st;

        for (char ch : s) {
            // While we can remove digits, and the current digit
            // is smaller than the last digit in stack, pop it
            while (!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }

        // If k digits are still left to remove, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }

        string result = st.substr(i);

        // If result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};
