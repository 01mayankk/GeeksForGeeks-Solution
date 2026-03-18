/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    
    // Structure to store information about each subtree
    struct Info {
        bool isBST;   // tells whether this subtree is a BST
        int size;     // number of nodes in this subtree
        int minVal;   // minimum value in this subtree
        int maxVal;   // maximum value in this subtree
    };
    
    int maxSize = 0; // global variable to track largest BST size
    
    // Recursive helper function (postorder traversal)
    Info solve(Node* root) {
        
        // Base case: empty tree is always a BST
        // min = +infinity, max = -infinity (helps in comparison)
        if (root == NULL) {
            return {true, 0, INT_MAX, INT_MIN};
        }
        
        // Get info from left subtree
        Info left = solve(root->left);
        
        // Get info from right subtree
        Info right = solve(root->right);
        
        Info curr; // info for current node
        
        // Check BST condition:
        // 1. Left subtree must be BST
        // 2. Right subtree must be BST
        // 3. Current node must be greater than max in left subtree
        // 4. Current node must be smaller than min in right subtree
        if (left.isBST && right.isBST &&
            root->data > left.maxVal &&
            root->data < right.minVal) {
            
            // Current subtree is BST
            curr.isBST = true;
            
            // Total nodes = left + right + current node
            curr.size = left.size + right.size + 1;
            
            // Update minimum value of this subtree
            // (either from left subtree or current node)
            curr.minVal = min(root->data, left.minVal);
            
            // Update maximum value of this subtree
            // (either from right subtree or current node)
            curr.maxVal = max(root->data, right.maxVal);
            
            // Update global maximum BST size
            maxSize = max(maxSize, curr.size);
        }
        else {
            // If not BST
            curr.isBST = false;
            
            // Size is not useful for BST, but we keep max of children
            // (this helps propagate largest BST found so far)
            curr.size = max(left.size, right.size);
            
            // Set values so that parent cannot consider this as BST
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }
        
        return curr;
    }
    
    int largestBst(Node *root) {
        maxSize = 0;   // reset before computation
        solve(root);   // start traversal
        return maxSize; // return largest BST size found
    }
};