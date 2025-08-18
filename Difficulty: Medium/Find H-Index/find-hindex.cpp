class Solution {
  public:
    // Helper function to check if there are at least 'mid' papers
    // with citations >= 'mid'
    bool check(vector<int>& citations, int n, int mid){
        int cnt = 0;
        // Count number of papers with citations >= mid
        for(int i = 0; i < n; i++){ // O(N)
            if(citations[i] >= mid) cnt++;
        }
        // If at least 'mid' papers have citations >= mid, return true
        return cnt >= mid;
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();

        // Binary search range: possible H-index values are [0, n]
        int lo = 0, hi = n;

        // Perform binary search on possible H-index
        while(lo <= hi){   // O(logN)
            int mid = (lo + hi) / 2;

            // If mid is a valid H-index (at least mid papers with >= mid citations)
            if(check(citations, n, mid)){
                // Try for a higher value
                lo = mid + 1;
            }
            else{
                // Otherwise, reduce the value
                hi = mid - 1;
            }
        }

        // At the end, 'hi' will store the maximum valid H-index
        return hi;
    }
};
