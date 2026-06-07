class Solution {
public:
    string profession(int level, int pos) {
        // Root (level 1, position 1) is Engineer.
        //
        // Moving to:
        // - first child  -> profession remains same
        // - second child -> profession changes
        //
        // For a given position, the number of profession changes
        // from the root to that node is equal to the number of
        // set bits in (pos - 1).
        //
        // Even number of changes -> Engineer
        // Odd number of changes  -> Doctor

        int flips = __builtin_popcount(pos - 1);

        return (flips % 2 == 0) ? "Engineer" : "Doctor";
    }
};