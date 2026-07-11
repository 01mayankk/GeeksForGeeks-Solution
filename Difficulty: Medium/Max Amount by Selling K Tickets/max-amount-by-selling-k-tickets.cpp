class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {
        // Max-heap to always pick the seller with the maximum available tickets
        priority_queue<int> pq(arr.begin(), arr.end());
        
        long long total_amount = 0;
        long long MOD = 1e9 + 7;
        
        // Process up to k tickets
        while (k > 0 && !pq.empty()) {
            int current_max = pq.top();
            pq.pop();
            
            // If the maximum tickets available from any seller is 0, we can't sell more
            if (current_max == 0) {
                break;
            }
            
            // Add the current price (which equals the number of remaining tickets) to the total
            total_amount = (total_amount + current_max) % MOD;
            
            // Push the updated ticket count back into the max-heap
            pq.push(current_max - 1);
            k--;
        }
        
        return total_amount;
    }
};