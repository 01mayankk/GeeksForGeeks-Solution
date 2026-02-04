class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        // This will store the time when the last ant falls off
        int ans = 0;

        // Case 1: Ants moving to the LEFT
        // An ant at position 'pos' moving left
        // will fall off the plank in 'pos' seconds
        for (int pos : left) {
            ans = max(ans, pos);
        }

        // Case 2: Ants moving to the RIGHT
        // An ant at position 'pos' moving right
        // will fall off the plank in (n - pos) seconds
        for (int pos : right) {
            ans = max(ans, n - pos);
        }

        // The maximum time among all ants
        // is the moment when the last ant falls
        return ans;
    }
};
