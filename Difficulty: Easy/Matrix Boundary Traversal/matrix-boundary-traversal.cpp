class Solution {
  public:
    vector<int> boundaryTraversal(vector<vector<int>>& mat) {
        vector<int> result;
        
        int row = mat.size();
        int col = mat[0].size();

        // Top row
        for(int j = 0; j < col; j++)
            result.push_back(mat[0][j]);

        // Right column
        for(int i = 1; i < row; i++)
            result.push_back(mat[i][col - 1]);

        // Bottom row (only if more than 1 row)
        if(row > 1) {
            for(int j = col - 2; j >= 0; j--)
                result.push_back(mat[row - 1][j]);
        }

        // Left column (only if more than 1 column)
        if(col > 1) {
            for(int i = row - 2; i > 0; i--)
                result.push_back(mat[i][0]);
        }

        return result;
    }
};
