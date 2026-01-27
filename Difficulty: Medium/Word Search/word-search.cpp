class Solution {
public:
    
    int n, m;   // Dimensions of the grid (rows and columns)
    
    // Direction vectors for moving:
    // up, down, left, right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // DFS function to check if word[index...] can be formed starting from (x, y)
    bool dfs(int x, int y, int index,
             vector<vector<char>> &mat,
             string &word,
             vector<vector<bool>> &visited)
    {
        // Base case:
        // If we have matched all characters of the word
        if(index == word.size())
            return true;
        
        // Boundary checks:
        // If indices are outside the grid
        if(x < 0 || y < 0 || x >= n || y >= m)
            return false;
        
        // If cell is already used OR character does not match current word character
        if(visited[x][y] || mat[x][y] != word[index])
            return false;
        
        // Mark current cell as visited to avoid reusing it
        visited[x][y] = true;
        
        // Explore all 4 adjacent cells
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir]; // new x-coordinate
            int ny = y + dy[dir]; // new y-coordinate
            
            // Recursively search for next character
            if(dfs(nx, ny, index + 1, mat, word, visited))
                return true;   // Path found
        }
        
        // Backtracking:
        // Unmark current cell before returning
        visited[x][y] = false;
        
        return false; // No valid path from this cell
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        
        // Store grid dimensions
        n = mat.size();
        m = mat[0].size();
        
        // Visited matrix to track used cells in current path
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Try to start DFS from every cell in the grid
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // Start DFS only if first character matches
                if(mat[i][j] == word[0])
                {
                    if(dfs(i, j, 0, mat, word, visited))
                        return true;   // Word found
                }
            }
        }
        
        // Word cannot be formed anywhere in the grid
        return false;
    }
};
