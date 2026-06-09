class Solution {
public:
    bool canSeatAllPeople(int k, vector<int> &seats) {

        int n = seats.size();

        // Traverse all seats
        for (int i = 0; i < n && k > 0; i++) {

            // We can only try to seat a person on an empty seat
            if (seats[i] == 0) {

                // Check left adjacent seat
                bool leftEmpty = (i == 0 || seats[i - 1] == 0);

                // Check right adjacent seat
                bool rightEmpty = (i == n - 1 || seats[i + 1] == 0);

                // If both adjacent positions are empty (or don't exist),
                // we can place a person here
                if (leftEmpty && rightEmpty) {
                    seats[i] = 1;  // Mark seat as occupied
                    k--;           // One person seated
                }
            }
        }

        // If all k people have been seated, return true
        return k == 0;
    }
};