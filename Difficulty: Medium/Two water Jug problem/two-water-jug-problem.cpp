class Solution {
public:

    // Function to calculate GCD using Euclidean algorithm
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // Function to simulate pouring from one jug to another
    int pour(int fromCap, int toCap, int d) {
        int from = fromCap; // Fill the "from" jug
        int to = 0;         // "to" jug initially empty

        int step = 1; // First step: filling from jug

        while (from != d && to != d) {

            // Pour water from "from" jug to "to" jug
            int temp = min(from, toCap - to);
            to += temp;
            from -= temp;

            step++;

            // Check if we got desired amount
            if (from == d || to == d)
                break;

            // If "from" jug becomes empty → fill it
            if (from == 0) {
                from = fromCap;
                step++;
            }

            // If "to" jug becomes full → empty it
            if (to == toCap) {
                to = 0;
                step++;
            }
        }

        return step;
    }

    int minSteps(int m, int n, int d) {

        // If d is more than both jugs → impossible
        if (d > max(m, n)) return -1;

        // If d is not multiple of gcd → impossible
        if (d % gcd(m, n) != 0) return -1;

        // If d equals one of the jugs
        if (d == m || d == n) return 1;

        // Compute both ways and take minimum
        return min(pour(m, n, d), pour(n, m, d));
    }
};