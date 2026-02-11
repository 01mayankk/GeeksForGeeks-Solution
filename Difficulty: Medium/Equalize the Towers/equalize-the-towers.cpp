class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        
        int n = heights.size();
        
        // Step 1: Store height and cost together
        vector<pair<int,int>> towers;
        for(int i = 0; i < n; i++) {
            towers.push_back({heights[i], cost[i]});
        }
        
        // Step 2: Sort based on heights
        sort(towers.begin(), towers.end());
        
        // Step 3: Find total cost (total weight)
        long long totalCost = 0;
        for(int i = 0; i < n; i++) {
            totalCost += towers[i].second;
        }
        
        // Step 4: Find weighted median
        long long cumulativeCost = 0;
        int targetHeight = 0;
        
        for(int i = 0; i < n; i++) {
            cumulativeCost += towers[i].second;
            
            // When cumulative cost reaches half of total weight,
            // that height becomes weighted median
            if(cumulativeCost >= (totalCost + 1) / 2) {
                targetHeight = towers[i].first;
                break;
            }
        }
        
        // Step 5: Calculate minimum cost
        long long answer = 0;
        
        for(int i = 0; i < n; i++) {
            answer += 1LL * abs(heights[i] - targetHeight) * cost[i];
        }
        
        return answer;
    }
};
