class Solution {
public:
    
    // Function to compute Catalan numbers up to n
    vector<int> computeCatalan(int n) {
        // Create a DP array to store Catalan values from 0 to n
        vector<int> catalan(n + 1, 0);
        
        // Base cases:
        // With 0 nodes → 1 BST (empty tree)
        // With 1 node → 1 BST
        catalan[0] = 1;
        catalan[1] = 1;
        
        // Fill Catalan numbers using DP
        // Formula: C(n) = sum(C(i) * C(n-i-1))
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // Left subtree has j nodes
                // Right subtree has (i - j - 1) nodes
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        
        return catalan; // Return computed Catalan array
    }

    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Copy and sort the array
        // Sorting helps us determine how many elements are smaller/larger
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        // Step 2: Precompute Catalan numbers up to n
        vector<int> catalan = computeCatalan(n);
        
        // This will store final answers
        vector<int> result;
        
        // Step 3: Process each element as root
        for (int i = 0; i < n; i++) {
            
            int root = arr[i]; // current root
            
            // Count elements smaller than root
            // lower_bound gives position of root in sorted array
            int leftCount = lower_bound(sorted.begin(), sorted.end(), root) - sorted.begin();
            
            // Remaining elements (excluding root and left subtree)
            int rightCount = n - leftCount - 1;
            
            // Total BSTs = (ways to form left subtree) × (ways to form right subtree)
            int ways = catalan[leftCount] * catalan[rightCount];
            
            // Store result for this root
            result.push_back(ways);
        }
        
        return result; // Return final answer
    }
};