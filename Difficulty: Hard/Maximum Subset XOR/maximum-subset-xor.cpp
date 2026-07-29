class Solution {
public:
    int maxSubsetXOR(vector<int>& arr) {
        // Array to store the basis of the vector space representing the numbers
        int basis[32] = {0};

        // Iterate through all elements in the given array
        for (int x : arr) {
            // Try to insert the current element 'x' into the basis
            for (int i = 31; i >= 0; i--) {
                // Check if the i-th bit of 'x' is set
                if ((x >> i) & 1) {
                    // If no basis element exists for this bit, store 'x' and break
                    if (!basis[i]) {
                        basis[i] = x;
                        break;
                    }
                    // Otherwise, XOR 'x' with the existing basis element to cancel the i-th bit
                    x ^= basis[i];
                }
            }
        }

        // Variable to accumulate the maximum XOR value
        int maxXor = 0;
        
        // Traverse the basis array from the most significant bit to the least
        for (int i = 31; i >= 0; i--) {
            // Include this basis element if it strictly increases our accumulated XOR
            if ((maxXor ^ basis[i]) > maxXor) {
                maxXor ^= basis[i];
            }
        }

        return maxXor;
    }
};