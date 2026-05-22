/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
    // Function to convert the binary tree into Sum Tree
    int solve(Node* root) {
        
        // Base case
        if (root == NULL)
            return 0;
        
        // Store original value of current node
        int oldValue = root->data;
        
        // Recursively calculate sum of left and right subtrees
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        
        // Update current node value
        // New value = sum of left subtree + sum of right subtree
        root->data = leftSum + rightSum;
        
        // Return total sum of subtree rooted at current node
        // (original node value + left subtree sum + right subtree sum)
        return oldValue + root->data;
    }
  
    void toSumTree(Node *root) {
        solve(root);
    }
};