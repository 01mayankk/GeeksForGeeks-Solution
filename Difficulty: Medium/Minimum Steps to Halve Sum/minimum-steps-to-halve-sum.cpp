class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // Step 1: Compute total sum
        double total = 0;
        for (int x : arr) total += x;

        double target = total / 2.0;

        // Step 2: Max heap with double values
        priority_queue<double> pq;
        for (int x : arr) pq.push((double)x);

        double reduced = 0.0;
        int operations = 0;

        // Step 3: Keep halving the largest element until reduction >= target
        while (reduced < target) {
            double x = pq.top();
            pq.pop();

            double half = x / 2.0;
            reduced += (x - half);
            pq.push(half);
            operations++;
        }

        return operations;
    }
};