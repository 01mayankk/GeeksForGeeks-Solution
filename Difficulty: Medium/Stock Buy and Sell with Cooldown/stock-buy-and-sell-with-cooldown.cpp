class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // States:
        // buy  → Max profit when we currently HOLD a stock
        // sell → Max profit when we just SOLD a stock
        // cool → Max profit when we are in cooldown (rest day)

        int buy = -prices[0]; // If we buy on day 0
        int sell = 0;         // Can't sell on day 0
        int cool = 0;         // Start with no transaction (rest)

        for (int i = 1; i < n; i++) {
            int prevBuy = buy;
            int prevSell = sell;
            int prevCool = cool;

            // If we buy today: either keep holding OR buy today after cooldown
            buy = max(prevBuy, prevCool - prices[i]);

            // If we sell today: we must have held the stock before
            sell = prevBuy + prices[i];

            // If we cooldown today: we can come from either cooldown or sell
            cool = max(prevCool, prevSell);
        }

        // Answer: max profit after last day (either in sell or cooldown)
        return max(sell, cool);
    }
};
