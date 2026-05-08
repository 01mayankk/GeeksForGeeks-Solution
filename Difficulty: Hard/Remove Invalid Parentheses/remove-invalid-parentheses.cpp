class Solution {
public:

    // ------------------------------------------------------------
    // Function to check whether a string is valid or not
    //
    // A valid string must:
    // 1. Never have more ')' than '(' while traversing
    // 2. Final count of '(' and ')' must become 0
    // ------------------------------------------------------------
    bool isValid(string &s) {

        int balance = 0;

        for (char ch : s) {

            // Opening bracket
            if (ch == '(') {
                balance++;
            }

            // Closing bracket
            else if (ch == ')') {
                balance--;
            }

            // Invalid case:
            // More closing brackets than opening
            if (balance < 0) {
                return false;
            }
        }

        // Valid only if all brackets are balanced
        return balance == 0;
    }

    // ------------------------------------------------------------
    // Function to remove minimum invalid parentheses
    // and return all valid possible strings
    // ------------------------------------------------------------
    vector<string> validParenthesis(string &s) {

        // Stores final answers
        vector<string> ans;

        // Visited set prevents duplicate processing
        unordered_set<string> visited;

        // BFS queue
        queue<string> q;

        // Start BFS from original string
        q.push(s);
        visited.insert(s);

        // Once we find valid strings at a level,
        // we stop generating deeper levels
        bool found = false;

        // --------------------------------------------------------
        // BFS Traversal
        // --------------------------------------------------------
        while (!q.empty()) {

            string curr = q.front();
            q.pop();

            // ----------------------------------------------------
            // Check whether current string is valid
            // ----------------------------------------------------
            if (isValid(curr)) {

                ans.push_back(curr);

                // We found at least one valid string
                found = true;
            }

            // ----------------------------------------------------
            // IMPORTANT:
            //
            // If valid string already found at this level,
            // do NOT generate next level states
            //
            // This guarantees minimum removals
            // ----------------------------------------------------
            if (found) {
                continue;
            }

            // ----------------------------------------------------
            // Generate all possible states
            // by removing one parenthesis
            // ----------------------------------------------------
            for (int i = 0; i < curr.length(); i++) {

                // Ignore normal characters
                if (curr[i] != '(' && curr[i] != ')') {
                    continue;
                }

                // Create new string after removing current char
                string next = curr;

                next.erase(i, 1);

                // Process only unvisited states
                if (!visited.count(next)) {

                    visited.insert(next);

                    q.push(next);
                }
            }
        }

        // Return answers in lexicographical order
        sort(ans.begin(), ans.end());

        return ans;
    }
};