// class Solution {
// public:
//     int helper(vector<int>& height, int start)
//     {
//         if (start == height.size() - 1) return 0;


//         int oneStep = abs(height[start + 1] - height[start]) + helper(height, start + 1);


//         int twoStep = INT_MAX;
//         if (start + 2 < height.size()) {
//             twoStep = abs(height[start + 2] - height[start]) + helper(height, start + 2);
//         }

//         return min(oneStep, twoStep);
//     }

//     int minCost(vector<int>& height) {
//         return helper(height, 0);
//     }
// };

//above code is using recurrsion which is giving TLE
class Solution {
public:
    int helper(vector<int>& height, int start, vector<int>& dp) {
        if (start == height.size() - 1) return 0;
        if (dp[start] != -1) return dp[start];

        int oneStep = INT_MAX, twoStep = INT_MAX;

        // If jump 1 is possible
        if (start + 1 < height.size()) {
            oneStep = abs(height[start + 1] - height[start]) + helper(height, start + 1, dp);
        }

        // If jump 2 is possible
        if (start + 2 < height.size()) {
            twoStep = abs(height[start + 2] - height[start]) + helper(height, start + 2, dp);
        }

        return dp[start] = min(oneStep, twoStep);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return helper(height, 0, dp);
    }
};
