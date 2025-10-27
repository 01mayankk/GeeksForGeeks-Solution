class Solution {
  public:
  
    // Depth-First Search helper function
    bool dfs(int i, int j, vector<vector<char>> &mat, string &word, int index) {
        
        // ✅ Base case: if we’ve matched all characters of the word
        if (index == word.size()) {
            return true;
        }

        // ❌ Boundary conditions + mismatch check
        // Out of bounds OR character doesn’t match
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] != word[index]) {
            return false;
        }

        // ⚙️ Mark current cell as visited (to avoid reusing same cell)
        char temp = mat[i][j];
        mat[i][j] = '#'; // any non-alphabet marker works

        // 🔁 Explore all 4 possible directions: Down, Up, Right, Left
        bool found = dfs(i + 1, j, mat, word, index + 1) ||  // move down
                     dfs(i - 1, j, mat, word, index + 1) ||  // move up
                     dfs(i, j + 1, mat, word, index + 1) ||  // move right
                     dfs(i, j - 1, mat, word, index + 1);    // move left

        // 🔙 Backtrack — restore the original character
        mat[i][j] = temp;

        // ✅ Return whether the word was found in any direction
        return found;
    }

    // Main function to check if the word exists in the matrix
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        
        int row = mat.size();
        int col = mat[0].size();
        
        // 🔍 Traverse each cell in the grid
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                // If first character matches, start DFS search from that cell
                if (mat[i][j] == word[0] && dfs(i, j, mat, word, 0)) {
                    return true; // Word found in the grid
                }
            }
        }
        
        // ❌ If not found anywhere, return false
        return false;
    }
};
