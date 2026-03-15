/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    // Helper function for DFS traversal
    void dfs(Node* root, long long currSum, int k, int &count,
             unordered_map<long long, int> &prefix) {
        
        if(root == NULL) 
            return;
        
        // Add current node value to running sum
        currSum += root->data;
        
        /*
        If (currSum - k) exists in the map,
        it means there is a prefix path whose removal
        gives a subpath with sum = k
        */
        if(prefix.find(currSum - k) != prefix.end()) {
            count += prefix[currSum - k];
        }
        
        // Store current prefix sum in map
        prefix[currSum]++;
        
        // Traverse left subtree
        dfs(root->left, currSum, k, count, prefix);
        
        // Traverse right subtree
        dfs(root->right, currSum, k, count, prefix);
        
        /*
        Backtracking step:
        remove current sum when returning to parent
        to avoid affecting other paths
        */
        prefix[currSum]--;
    }
    
    
    int countAllPaths(Node *root, int k) {
        
        // Map to store prefix sums and their frequency
        unordered_map<long long, int> prefix;
        
        // Base case: sum = 0 occurs once
        prefix[0] = 1;
        
        int count = 0;
        
        // Start DFS traversal
        dfs(root, 0, k, count, prefix);
        
        return count;
    }
};