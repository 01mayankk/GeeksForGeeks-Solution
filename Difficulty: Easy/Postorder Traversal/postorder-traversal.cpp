/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    // Helper function to perform postorder traversal (Left → Right → Root)
    void traversal(Node* root, vector<int>& result) {
        if (root) {
            // Recur on left subtree
            traversal(root->left, result);
            
            // Recur on right subtree
            traversal(root->right, result);
            
            // Process current node
            result.push_back(root->data);
        }
    }

    // Main function to return postorder traversal as a vector
    vector<int> postOrder(Node* root) {
        vector<int> result;

        // Base case: if the tree is empty, return empty vector
        if (root == nullptr) {
            return {};  // return an empty vector
        }

        // Fill result using helper traversal function
        traversal(root, result);

        // Return the complete postorder traversal
        return result;
    }
};