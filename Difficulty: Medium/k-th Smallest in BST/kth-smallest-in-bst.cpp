/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    // Helper function: Perform an inorder traversal (Left → Root → Right)
    // Inorder traversal of a Binary Search Tree gives elements in sorted order.
    void inOrder(Node* root, vector<int>& result) {
        // Base condition: if current node is NULL, just return
        if (root) {
            // Visit left subtree first
            inOrder(root->left, result);
            
            // Process the current node (store its value)
            result.push_back(root->data);
            
            // Visit right subtree
            inOrder(root->right, result);
        }
    }

    // Main function to find the k-th smallest element in the BST
    int kthSmallest(Node *root, int k) {
        // Vector to store the inorder traversal result (sorted elements)
        vector<int> result;
        
        // Step 1: Perform inorder traversal to get sorted node values
        inOrder(root, result);
        
        // Step 2: Check for invalid conditions
        // Case 1: Tree is empty
        if (root == nullptr) {
            return -1;
        }
        // Case 2: k is larger than number of nodes
        else if (result.size() < k) {
            return -1;
        }
        
        // Step 3: Return the k-th smallest element (1-based indexing)
        // Since vector is 0-indexed, we access result[k - 1]
        return result[k - 1];
    }
};