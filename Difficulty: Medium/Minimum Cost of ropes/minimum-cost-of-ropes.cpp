class Solution {
  public:
    int minCost(vector<int>& arr) {
        // If only one rope, cost is 0
        if (arr.size() <= 1) return 0;

        // Min-heap (priority queue with smallest element on top)
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

        int totalCost = 0;

        // Keep connecting until only one rope remains
        while (minHeap.size() > 1) {
            int first = minHeap.top(); minHeap.pop();
            int second = minHeap.top(); minHeap.pop();

            int cost = first + second;
            totalCost += cost;

            // Push combined rope length back to heap
            minHeap.push(cost);
        }

        return totalCost;
    }
};
