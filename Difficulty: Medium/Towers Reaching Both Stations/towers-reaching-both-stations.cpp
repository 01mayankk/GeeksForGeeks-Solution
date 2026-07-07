class Solution {
public:
    // Four possible movement directions:
    // Up, Down, Left, Right
    const vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    /*
        Performs Reverse DFS starting from a station boundary.

        Instead of checking which cells can flow to the station,
        we start from the station itself and move towards cells
        having greater or equal signal strength.

        Why?
        Original Flow:
            Current -> Neighbour (Neighbour <= Current)

        Reverse Flow:
            Station -> Higher/Equal Cell
            (Neighbour >= Current)
    */
    void dfs(int row,
             int col,
             vector<vector<int>>& mat,
             vector<vector<bool>>& visited) {

        // Mark current cell as reachable from this station
        visited[row][col] = true;

        int rows = mat.size();
        int cols = mat[0].size();

        // Explore all four neighbouring cells
        for (auto [dr, dc] : directions) {

            int newRow = row + dr;
            int newCol = col + dc;

            // Skip if the neighbour is outside the grid
            if (newRow < 0 || newRow >= rows ||
                newCol < 0 || newCol >= cols)
                continue;

            // Skip already processed cells
            if (visited[newRow][newCol])
                continue;

            /*
                Reverse DFS condition:

                We can move only to a cell whose value is
                greater than or equal to the current cell.

                This exactly reverses the original signal flow.
            */
            if (mat[newRow][newCol] >= mat[row][col]) {
                dfs(newRow, newCol, mat, visited);
            }
        }
    }

    int countCoordinates(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        // Stores cells reachable from Station P (Top + Left)
        vector<vector<bool>> stationP(rows, vector<bool>(cols, false));

        // Stores cells reachable from Station Q (Bottom + Right)
        vector<vector<bool>> stationQ(rows, vector<bool>(cols, false));

        // =====================================================
        // Reverse DFS from Station P (Top boundary + Left boundary)
        // =====================================================

        // Start DFS from every cell in the top row
        for (int col = 0; col < cols; col++) {
            if (!stationP[0][col]) {
                dfs(0, col, mat, stationP);
            }
        }

        // Start DFS from every cell in the left column
        for (int row = 0; row < rows; row++) {
            if (!stationP[row][0]) {
                dfs(row, 0, mat, stationP);
            }
        }

        // =====================================================
        // Reverse DFS from Station Q (Bottom boundary + Right boundary)
        // =====================================================

        // Start DFS from every cell in the bottom row
        for (int col = 0; col < cols; col++) {
            if (!stationQ[rows - 1][col]) {
                dfs(rows - 1, col, mat, stationQ);
            }
        }

        // Start DFS from every cell in the right column
        for (int row = 0; row < rows; row++) {
            if (!stationQ[row][cols - 1]) {
                dfs(row, cols - 1, mat, stationQ);
            }
        }

        // Count cells that are reachable from both stations
        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // Cell can send signal to both stations
                if (stationP[row][col] && stationQ[row][col]) {
                    answer++;
                }
            }
        }

        return answer;
    }
};