// class Solution {
//   public:
//     int minSquares(int n) {
//         // Create a DP array where dp[i] will store 
//         // the minimum number of perfect squares that sum up to i
//         vector<int> dp(n + 1, INT_MAX);

//         // Base case: 0 can be represented with 0 squares
//         dp[0] = 0;

//         // Iterate through all numbers from 1 to n
//         for (int i = 1; i <= n; i++) {
//             // Try every perfect square less than or equal to i
//             for (int j = 1; j * j <= i; j++) {
//                 // If we use j*j, then we add 1 (for this square)
//                 // and add the minimum count for the remaining part (i - j*j)
//                 dp[i] = min(dp[i], 1 + dp[i - j * j]);
//             }
//         }
        
//         // The result for n will be stored in dp[n]
//         return dp[n];
//     }
// };



class Solution {
public:
    int minSquares(int n) {
        // Base case: if n is 0 or less, we need 0 squares
        if (n <= 0) return 0;

        // Queue to perform BFS
        queue<int> q;

        // Visited array to mark which numbers we have already processed
        // This prevents reprocessing and reduces time complexity
        vector<bool> visited(n + 1, false);

        // Start BFS from number n
        q.push(n);
        visited[n] = true;

        // 'level' represents the number of perfect squares used so far
        int level = 0;

        // Standard BFS loop
        while (!q.empty()) {
            int size = q.size();  // Number of elements at the current BFS level
            level++;              // Each level corresponds to adding one more perfect square

            // Process all elements in the current level
            while (size--) {
                int curr = q.front();
                q.pop();

                // Try subtracting every possible perfect square (1, 4, 9, 16, ...)
                for (int i = 1; i * i <= curr; i++) {
                    int next = curr - i * i;

                    // If we reach 0, that means 'level' perfect squares sum up to n
                    if (next == 0) 
                        return level;

                    // If this value hasn't been visited, push it for the next level
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        // Control should never reach here (by theory every number ≤ n can be represented)
        return level;
    }
};
