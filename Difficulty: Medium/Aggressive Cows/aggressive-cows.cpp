class Solution {
public:
    
    /*
        This function checks:
        "Is it possible to place 'k' cows such that
         the minimum distance between any two cows is at least 'minDist'?"

        It does NOT try to maximize anything.
        It just returns true or false.
    */
    bool canPlaceCows(vector<int> &stalls, int k, int minDist) {
        
        // Place the first cow in the very first stall
        int cowsPlaced = 1;
        int lastPos = stalls[0];

        // Try placing remaining cows
        for (int i = 1; i < stalls.size(); i++) {
            
            // Check if current stall is far enough from last placed cow
            if (stalls[i] - lastPos >= minDist) {
                
                // Place a cow here
                cowsPlaced++;
                lastPos = stalls[i];

                // If all cows are placed successfully
                if (cowsPlaced == k)
                    return true;
            }
        }

        // Not enough cows could be placed
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Step 1: Sort stall positions
        // Required so that we place cows from left to right
        sort(stalls.begin(), stalls.end());

        // Step 2: Define binary search space
        int low = 1;                                 // minimum possible distance
        int high = stalls.back() - stalls.front();  // maximum possible distance
        int answer = 0;                              // stores best possible answer

        // Step 3: Binary search on distance
        while (low <= high) {

            // Middle distance
            int mid = low + (high - low) / 2;

            /*
                Check:
                Can we place all cows
                with minimum distance = mid ?
            */
            if (canPlaceCows(stalls, k, mid)) {

                // If yes, mid is a valid answer
                answer = mid;

                // Try for a larger minimum distance
                low = mid + 1;
            } else {

                // If not possible, reduce the distance
                high = mid - 1;
            }
        }

        // answer stores the largest minimum distance found
        return answer;
    }
};
