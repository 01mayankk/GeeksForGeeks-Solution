class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        
        // If there are no prices, profit is 0
        if (prices.size() == 0) return 0;
        
        // minPrice stores the lowest stock price seen so far
        int minPrice = prices[0];
        
        // maxProfit stores the maximum profit achievable
        int maxProfit = 0;
        
        // Traverse prices from day 1 onwards
        for (int i = 1; i < prices.size(); i++) {
            
            // Update minimum price if current price is lower
            minPrice = min(minPrice, prices[i]);
            
            // Calculate profit if we sell on current day
            int profit = prices[i] - minPrice;
            
            // Update maximum profit if better profit found
            maxProfit = max(maxProfit, profit);
        }
        
        // If profit is negative or no transaction possible, returns 0
        return maxProfit;
    }
};
