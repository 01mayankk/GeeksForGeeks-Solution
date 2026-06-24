class Solution {
  public:
  
    // Backtracking function to generate numbers
    void solve(int n, int lastDigit, string curr, vector<int>& ans) {
        
        // If we have selected n digits, convert to integer and store
        if (curr.length() == n) {
            ans.push_back(stoi(curr));
            return;
        }

        // Pick next digit greater than previous digit
        for (int digit = lastDigit + 1; digit <= 9; digit++) {
            solve(n, digit, curr + char('0' + digit), ans);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        // Special case: single digit numbers
        if (n == 1) {
            for (int i = 0; i <= 9; i++) {
                ans.push_back(i);
            }
            return ans;
        }

        // More than 9 digits is impossible
        // because digits must be strictly increasing
        if (n > 9)
            return ans;

        // Start from digits 1 to 9
        // (leading zero is not allowed for n > 1)
        solve(n, 0, "", ans);

        return ans;
    }
};