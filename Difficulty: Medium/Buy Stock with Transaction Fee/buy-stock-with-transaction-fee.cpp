class Solution {
public:
    int maxProfit(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        // Edge case
        if(n == 0) return 0;
        
        // hold: max profit when holding a stock
        // cash: max profit when not holding a stock
        int hold = -arr[0];   // we buy on first day
        int cash = 0;         // no profit initially
        
        for(int i = 1; i < n; i++) {
            
            // If we buy today OR continue holding previous stock
            hold = max(hold, cash - arr[i]);
            
            // If we sell today OR continue without stock
            // subtract transaction fee k while selling
            cash = max(cash, hold + arr[i] - k);
        }
        
        // Final answer: max profit when we are NOT holding stock
        return cash;
    }
};