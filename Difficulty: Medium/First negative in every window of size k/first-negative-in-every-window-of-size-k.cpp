class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {

        int n = arr.size();

        // Stores the answer for each window
        vector<int> ans;

        // Queue stores indices of negative elements
        queue<int> q;

        // Traverse the array
        for (int i = 0; i < n; i++) {

            // If current element is negative, store its index
            if (arr[i] < 0) {
                q.push(i);
            }

            // Start processing once the first window of size k is formed
            if (i >= k - 1) {

                // Remove indices that are no longer inside the current window
                while (!q.empty() && q.front() < i - k + 1) {
                    q.pop();
                }

                // If queue is not empty, front holds the first negative element
                if (!q.empty()) {
                    ans.push_back(arr[q.front()]);
                }
                // Otherwise, there is no negative element in this window
                else {
                    ans.push_back(0);
                }
            }
        }

        return ans;
    }
};