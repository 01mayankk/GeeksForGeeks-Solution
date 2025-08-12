class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Calculate the number of candies to consider after removing the k most expensive or cheapest ones
        int n = prices.size();
        int heap_size = (n + k) / (k + 1); // Effective number of candies to keep in each heap

        // Max heap to store largest prices (for calculating min sum by removing expensive ones)
        priority_queue<int> max_heap;

        // Min heap to store smallest prices (for calculating max sum by removing cheapest ones)
        priority_queue<int, vector<int>, greater<int>> min_heap;

        int max_sum = 0; // Stores the maximum possible sum of candies
        int min_sum = 0; // Stores the minimum possible sum of candies

        // Iterate through each candy price
        for (auto price : prices) {
            // Add the price to both heaps
            max_heap.push(price);
            min_heap.push(price);

            // Add price to both sums initially
            max_sum += price;
            min_sum += price;

            // Maintain max_heap size to heap_size for min_sum calculation
            // If heap exceeds size, remove the largest element and adjust min_sum
            if (max_heap.size() > heap_size) {
                min_sum -= max_heap.top();
                max_heap.pop();
            }

            // Maintain min_heap size to heap_size for max_sum calculation
            // If heap exceeds size, remove the smallest element and adjust max_sum
            if (min_heap.size() > heap_size) {
                max_sum -= min_heap.top();
                min_heap.pop();
            }
        }

        // Return the minimum and maximum sum as a vector
        return {min_sum, max_sum};
    }
};
