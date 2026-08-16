class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;

        // Array to store jumps (ladders and snakes)
        vector<int> jump(N + 1, -1);

        // Populate ladders
        for (int i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }

        // Populate snakes
        for (int i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }

        // Queue for BFS storing pairs of {current_cell, dice_throws}
        queue<pair<int, int>> q;
        vector<bool> visited(N + 1, false);

        // Start from cell 1 with 0 throws
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, throws] = q.front();
            q.pop();

            // If we reached the final cell
            if (curr == N) {
                return throws;
            }

            // Try all possible dice throws from 1 to 6
            for (int dice = 1; dice <= 6; ++dice) {
                int next_cell = curr + dice;

                // Ensure we don't go out of the board limits
                if (next_cell <= N) {
                    // Calculate actual destination after taking snake or ladder if one exists
                    int actual_next = (jump[next_cell] != -1) ? jump[next_cell] : next_cell;

                    // If the resulting cell hasn't been visited yet, add to queue
                    if (!visited[actual_next]) {
                        visited[actual_next] = true;
                        q.push({actual_next, throws + 1});
                    }
                }
            }
        }

        // If destination is unreachable
        return -1;
    }
};