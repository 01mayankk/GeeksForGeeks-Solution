class Solution {
  public:
  
    int minSteps(vector<int>& arr, int start, int end) {

        // If start and end are same,
        // no operation is needed
        if(start == end)
            return 0;

        // Distance array to store minimum steps
        // required to reach every number from 0 to 999
        vector<int> dist(1000, 1e9);

        // Queue used for BFS
        // pair = {current number, steps taken}
        queue<pair<int,int>> q;

        // Start BFS from 'start'
        q.push({start, 0});

        // Distance to start node is 0
        dist[start] = 0;

        // Perform BFS
        while(!q.empty()) {

            // Take front element from queue
            int node = q.front().first;
            int steps = q.front().second;

            q.pop();

            // Try multiplying current number
            // with every element in arr
            for(int num : arr) {

                // New value after multiplication and modulo
                int newNode = (node * num) % 1000;

                // If we found a shorter path
                // to reach newNode
                if(steps + 1 < dist[newNode]) {

                    // Update minimum steps
                    dist[newNode] = steps + 1;

                    // If end is reached,
                    // return answer immediately
                    if(newNode == end)
                        return steps + 1;

                    // Push new state into queue
                    q.push({newNode, steps + 1});
                }
            }
        }

        // If end cannot be reached
        return -1;
    }
};