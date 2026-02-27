class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        
        // Get dimensions of matrix
        int n = mat.size();
        int m = mat[0].size();
        
        /*
        -------------------------------------------------------------
        STEP 1: Build 2D Prefix Sum Array
        -------------------------------------------------------------
        prefix[i][j] will store sum of elements from
        (0,0) to (i-1, j-1) in original matrix.
        
        We use size (n+1) x (m+1) to avoid boundary checks.
        */
        
        vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                
                // Formula of 2D prefix sum
                prefix[i][j] = mat[i-1][j-1]        // current element
                               + prefix[i-1][j]     // top
                               + prefix[i][j-1]     // left
                               - prefix[i-1][j-1];  // remove double counted area
            }
        }
        
        // Variable to count valid square submatrices
        int count = 0;
        
        /*
        -------------------------------------------------------------
        STEP 2: Try all possible square sizes
        -------------------------------------------------------------
        Smallest square = 1x1
        Largest square = min(n, m)
        */
        
        for(int size = 1; size <= min(n, m); size++) {
            
            /*
            ---------------------------------------------------------
            STEP 3: Slide square of given size over matrix
            ---------------------------------------------------------
            (i, j) represents top-left corner of square
            */
            
            for(int i = 0; i + size <= n; i++) {
                for(int j = 0; j + size <= m; j++) {
                    
                    // Coordinates of square
                    int r1 = i;
                    int c1 = j;
                    int r2 = i + size - 1;
                    int c2 = j + size - 1;
                    
                    /*
                    -------------------------------------------------
                    STEP 4: Calculate square sum in O(1)
                    -------------------------------------------------
                    Using prefix sum formula:
                    
                    sum = total area
                          - upper extra part
                          - left extra part
                          + overlapped removed part
                    */
                    
                    long long sum = prefix[r2 + 1][c2 + 1]
                                   - prefix[r1][c2 + 1]
                                   - prefix[r2 + 1][c1]
                                   + prefix[r1][c1];
                    
                    // If square sum equals x → increment count
                    if(sum == x) {
                        count++;
                    }
                }
            }
        }
        
        // Return total number of valid square submatrices
        return count;
    }
};