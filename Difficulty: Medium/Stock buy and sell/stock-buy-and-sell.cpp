class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // Initialize total profit to 0
        int profit = 0;
        
        // Traverse through the price array
        for(int i = 1; i < arr.size(); i++)
        {
            // If today's price is greater than yesterday's,
            // it means we can profit by buying yesterday and selling today.
            if(arr[i] > arr[i - 1])
            {
                // Add that profit to total
                profit += arr[i] - arr[i - 1];
            }
        }
        
        // Return total accumulated profit
        return profit;
    }
};
