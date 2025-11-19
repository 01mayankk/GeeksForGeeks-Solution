class Solution {
public:
    int minCostPath(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        // Min-heap storing {effort, x, y}
        // effort = maximum absolute difference so far along the path
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // effort[x][y] stores the minimum possible "maximum difference"
        // required to reach cell (x, y)
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        
        // Start at (0, 0) with effort 0
        effort[0][0] = 0;
        pq.push({0, 0, 0});  // {effort = 0, x = 0, y = 0}

        // Directions: down, up, right, left
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!pq.empty()) {

            // Get the state with the minimum effort so far
            auto t = pq.top(); 
            pq.pop();

            int cost = t[0];  // current path effort
            int x = t[1];
            int y = t[2];

            // If we reached bottom-right, this is the best possible answer
            if (x == n-1 && y == m-1) 
                return cost;

            // Ignore this entry if we already found a better path earlier
            if (cost > effort[x][y]) 
                continue;

            // Explore all 4 possible directions
            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                // Check boundaries
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {

                    // Edge cost = absolute difference between current and neighbor cell
                    int diff = abs(mat[x][y] - mat[nx][ny]);

                    // The effort of the path becomes the maximum edge so far
                    int newEffort = max(cost, diff);

                    // If this path gives a smaller maximum-difference to reach (nx, ny)
                    if (newEffort < effort[nx][ny]) {

                        // Update to a better effort
                        effort[nx][ny] = newEffort;

                        // Push the new state into the priority queue
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }

        // This won't be reached normally, because destination will always be returned earlier
        return 0;
    }
};
