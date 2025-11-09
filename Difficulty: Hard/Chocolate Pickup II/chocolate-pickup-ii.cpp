#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int n;
    vector<vector<vector<int>>> dp;

    // Recursive function with memoization
    int solve(vector<vector<int>>& mat, int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2; // because both robots have taken equal steps

        // Base cases: invalid or blocked cell
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || 
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return -1e9;

        // Reached destination (bottom-right)
        if (r1 == n - 1 && c1 == n - 1)
            return mat[r1][c1];

        // Check memoized result
        if (dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];

        // Current chocolates collected
        int chocolates = 0;
        if (r1 == r2 && c1 == c2)
            chocolates = mat[r1][c1]; // same cell, count once
        else
            chocolates = mat[r1][c1] + mat[r2][c2];

        // Explore 4 possible move combinations
        int nextMax = max({
            solve(mat, r1 + 1, c1, c2 + 1), // down, right
            solve(mat, r1, c1 + 1, c2 + 1), // right, right
            solve(mat, r1 + 1, c1, c2),     // down, down
            solve(mat, r1, c1 + 1, c2)      // right, down
        });

        chocolates += nextMax;
        return dp[r1][c1][c2] = chocolates;
    }

    int chocolatePickup(vector<vector<int>> &mat) {
        n = mat.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));

        int ans = solve(mat, 0, 0, 0);

        // If no valid path exists, return 0
        return max(0, ans);
    }
};
