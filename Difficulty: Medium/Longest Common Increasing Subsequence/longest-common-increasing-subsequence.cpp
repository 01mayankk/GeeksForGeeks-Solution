class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();

        // dp[j] = length of the LCIS that ends exactly at b[j]
        vector<int> dp(m, 0);

        // Traverse each element in array a
        for (int i = 0; i < n; i++) {

            // Stores the best LCIS length so far where value in b[] < a[i]
            int current_max = 0;

            // Compare a[i] with every element of b
            for (int j = 0; j < m; j++) {

                // Case 1: b[j] < a[i]
                // b[j] can contribute to an increasing subsequence before a[i]
                if (b[j] < a[i]) {
                    current_max = max(current_max, dp[j]);
                }

                // Case 2: b[j] == a[i]
                // We found a matching element → we can extend the LCIS
                else if (b[j] == a[i]) {
                    dp[j] = current_max + 1;  
                    // dp[j] will hold LCIS ending at this matching value
                }
            }
        }

        // The answer is the maximum LCIS length found across dp[]
        int ans = 0;
        for (int v : dp) 
            ans = max(ans, v);

        return ans;
    }
};
