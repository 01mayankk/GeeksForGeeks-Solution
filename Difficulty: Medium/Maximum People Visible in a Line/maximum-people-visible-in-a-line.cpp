class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();

        // Stack will store indices of people
        stack<int> s;

        // ng[i] = index of next greater or equal height person to the right
        // default n means no such person
        vector<int> ng(n, n);

        // pg[i] = index of previous greater or equal height person to the left
        // default -1 means no such person
        vector<int> pg(n, -1);

        int ans = 0;

        // ---------- FIND NEXT GREATER (OR EQUAL) TO RIGHT ----------
        // Monotonic decreasing stack
        for (int i = 0; i < n; i++) {
            // If current person is taller or equal,
            // they block visibility for people in stack
            while (!s.empty() && arr[i] >= arr[s.top()]) {
                ng[s.top()] = i;   // first blocker on the right
                s.pop();
            }
            s.push(i);
        }

        // Clear stack before reuse
        while (!s.empty()) s.pop();

        // ---------- FIND PREVIOUS GREATER (OR EQUAL) TO LEFT ----------
        // Again a monotonic decreasing stack
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[i] >= arr[s.top()]) {
                pg[s.top()] = i;   // first blocker on the left
                s.pop();
            }
            s.push(i);
        }

        // ---------- COMPUTE MAX VISIBLE PEOPLE ----------
        for (int i = 0; i < n; i++) {
            // People visible are strictly between blockers
            ans = max(ans, ng[i] - pg[i] - 1);
        }

        return ans;
    }
};
