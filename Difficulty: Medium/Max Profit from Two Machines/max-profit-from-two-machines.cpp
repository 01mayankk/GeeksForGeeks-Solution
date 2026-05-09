class Solution {
public:

    // Comparator function
    // Sort tasks based on absolute profit difference
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {

        // Larger difference should come first
        return abs(p1.first - p1.second) >
               abs(p2.first - p2.second);
    }

    int maxProfit(int x, int y, vector<int>& a, vector<int>& b) {

        int n = a.size();

        // Store profits of both machines together
        vector<pair<int, int>> tasks;

        for (int i = 0; i < n; i++) {
            tasks.push_back({a[i], b[i]});
        }

        // Sort by maximum profit difference
        //
        // Why?
        // Tasks having large difference are more important
        // to assign optimally first.
        sort(tasks.begin(), tasks.end(), cmp);

        int totalProfit = 0;

        // Traverse all tasks
        for (auto& task : tasks) {

            int profitA = task.first;
            int profitB = task.second;

            // Case 1:
            // Machine A gives more profit
            if (profitA >= profitB) {

                // Assign to A if capacity available
                if (x > 0) {
                    totalProfit += profitA;
                    x--;
                }
                else {
                    // Otherwise assign to B
                    totalProfit += profitB;
                    y--;
                }
            }

            // Case 2:
            // Machine B gives more profit
            else {

                // Assign to B if capacity available
                if (y > 0) {
                    totalProfit += profitB;
                    y--;
                }
                else {
                    // Otherwise assign to A
                    totalProfit += profitA;
                    x--;
                }
            }
        }

        // Return maximum total profit
        return totalProfit;
    }
};