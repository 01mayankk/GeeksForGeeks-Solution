class Solution {
  public:
  
    // dp[index][prevSum]
    // Stores number of valid groupings
    // starting from 'index' with previous group sum = prevSum
    int dp[101][901];

    // Recursive + Memoization function
    int solve(int index, int prevSum, string &s)
    {
        // If entire string is used,
        // we found one valid grouping
        if(index == s.size())
            return 1;

        // Return already computed answer
        if(dp[index][prevSum] != -1)
            return dp[index][prevSum];

        int ans = 0;
        int currentSum = 0;

        // Form all possible groups starting from 'index'
        for(int i = index; i < s.size(); i++)
        {
            // Add current digit to group sum
            currentSum += (s[i] - '0');

            // Group is valid only if:
            // current group sum >= previous group sum
            if(currentSum >= prevSum)
            {
                // Recur for remaining string
                ans += solve(i + 1, currentSum, s);
            }
        }

        // Store and return result
        return dp[index][prevSum] = ans;
    }

    int validGroups(string &s) {
        
        // Initialize DP table with -1
        memset(dp, -1, sizeof(dp));

        // Start from index 0
        // Previous sum = 0
        return solve(0, 0, s);
    }
};