class Solution {
public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();

        // This will store the final answer
        long long result = 0;

        // We check each bit position independently (0 to 31 for integers)
        for (int bit = 0; bit < 32; bit++) {

            // Count how many numbers have current bit set (1)
            long long count1 = 0;

            // Traverse array to count set bits at this position
            for (int i = 0; i < n; i++) {

                // Check if current bit is set in arr[i]
                // (1 << bit) creates a mask for the current bit
                if (arr[i] & (1 << bit)) {
                    count1++;
                }
            }

            // Numbers that do NOT have this bit set
            long long count0 = n - count1;

            /*
             For XOR:
             - A bit contributes 1 only when bits are different
             - So valid pairs = (count of 1s) * (count of 0s)
            */
            long long pairs = count1 * count0;

            /*
             Each such pair contributes (2^bit) to the final XOR sum
             Multiply number of valid pairs with value of this bit
            */
            result += pairs * (1LL << bit);
        }

        // Return total XOR sum of all distinct pairs
        return result;
    }
};