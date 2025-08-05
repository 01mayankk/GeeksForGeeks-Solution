class Solution {
  public:
    // Function to find common elements in three sorted arrays without using extra data structures
    vector<int> commonElements(vector<int>& A, vector<int>& B, vector<int>& C) {
        int i = 0, j = 0, k = 0;         // Initialize pointers for all three arrays
        vector<int> result;             // Vector to store the common elements

        // Traverse all three arrays until one of them is exhausted
        while (i < A.size() && j < B.size() && k < C.size()) {

            // Case 1: If elements at all three pointers are equal
            if (A[i] == B[j] && B[j] == C[k]) {
                // Add to result only if it's not already added (to avoid duplicates)
                if (result.empty() || result.back() != A[i]) {
                    result.push_back(A[i]);
                }
                i++; j++; k++;  // Move all pointers forward
            }
            // Case 2: Move the pointer with the smallest value forward
            else if (A[i] < B[j]) {
                i++;  // Move pointer i since A[i] is smallest
            }
            else if (B[j] < C[k]) {
                j++;  // Move pointer j since B[j] is smaller than C[k]
            }
            else {
                k++;  // Move pointer k since C[k] is smallest
            }
        }

        // If no common elements found, return -1
        if (result.empty()) return {-1};

        // Return the final list of common elements
        return result;
    }
};
