#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        // Step 1: Collect all blocked rows and columns
        vector<int> blockedRows;
        vector<int> blockedCols;
        
        for (int i = 0; i < k; ++i) {
            blockedRows.push_back(arr[i][0]);
            blockedCols.push_back(arr[i][1]);
        }
        
        // Add virtual boundaries for rows (0 and n + 1)
        blockedRows.push_back(0);
        blockedRows.push_back(n + 1);
        
        // Add virtual boundaries for columns (0 and m + 1)
        blockedCols.push_back(0);
        blockedCols.push_back(m + 1);
        
        // Step 2: Sort the blocked row and column indices to find continuous intervals
        sort(blockedRows.begin(), blockedRows.end());
        sort(blockedCols.begin(), blockedCols.end());
        
        // Step 3: Find the maximum gap between consecutive blocked rows
        int maxRowGap = 0;
        for (size_t i = 1; i < blockedRows.size(); ++i) {
            int gap = blockedRows[i] - blockedRows[i - 1] - 1;
            maxRowGap = max(maxRowGap, gap);
        }
        
        // Step 4: Find the maximum gap between consecutive blocked columns
        int maxColGap = 0;
        for (size_t i = 1; i < blockedCols.size(); ++i) {
            int gap = blockedCols[i] - blockedCols[i - 1] - 1;
            maxColGap = max(maxColGap, gap);
        }
        
        // Step 5: The largest continuous unblocked submatrix area is maxRowGap * maxColGap
        return maxRowGap * maxColGap;
    }
};