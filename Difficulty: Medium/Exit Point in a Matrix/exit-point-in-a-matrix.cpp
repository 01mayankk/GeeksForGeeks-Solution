class Solution {
public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int row = 0, col = 0;

        // Directions:
        // 0 -> Right
        // 1 -> Down
        // 2 -> Left
        // 3 -> Up
        int dir = 0;

        while (true) {

            // If current cell contains 1,
            // turn right and make it 0
            if (mat[row][col] == 1) {
                dir = (dir + 1) % 4;
                mat[row][col] = 0;
            }

            // Move according to current direction
            if (dir == 0) {          // Right
                col++;
            }
            else if (dir == 1) {     // Down
                row++;
            }
            else if (dir == 2) {     // Left
                col--;
            }
            else {                   // Up
                row--;
            }

            // Check if we have moved outside the matrix
            if (row < 0) {
                row++;      // last valid row
                break;
            }
            if (row >= n) {
                row--;
                break;
            }
            if (col < 0) {
                col++;
                break;
            }
            if (col >= m) {
                col--;
                break;
            }
        }

        return {row, col};
    }
};