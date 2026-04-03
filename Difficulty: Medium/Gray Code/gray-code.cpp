class Solution {
public:
    vector<string> graycode(int n) {
        vector<string> result;  // Stores final Gray code sequence

        // Total number of Gray codes = 2^n
        int total = 1 << n;  // equivalent to pow(2, n)

        // Loop through all numbers from 0 to (2^n - 1)
        for (int i = 0; i < total; i++) {

            // Generate Gray code using formula:
            // G(i) = i ^ (i >> 1)
            // This ensures only one bit differs from previous number
            int gray = i ^ (i >> 1);

            // Convert the integer 'gray' to binary string of length n
            string binary = "";

            // Traverse bits from MSB to LSB
            for (int j = n - 1; j >= 0; j--) {

                // Check if j-th bit is set (1) or not (0)
                if (gray & (1 << j))
                    binary += '1';  // bit is 1
                else
                    binary += '0';  // bit is 0
            }

            // Add generated binary string to result
            result.push_back(binary);
        }

        // Return the complete Gray code sequence
        return result;
    }
};