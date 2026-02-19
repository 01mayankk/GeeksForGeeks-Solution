/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
  
    // Helper function to traverse the binary tree
    // and count leaf nodes.
    // It takes:
    // 1️⃣ root  -> current node
    // 2️⃣ count -> reference variable to store number of leaf nodes
    void traversal(Node* root, int& count)
    {
        // Base condition:
        // If current node is not NULL
        if(root != nullptr)
        {
            // Check if current node is a LEAF node
            // Leaf node = node with no left and no right child
            if(root->left == nullptr && root->right == nullptr)
            {
                count++;   // Increment leaf count
            }
            else
            {
                // Recursively check left subtree
                traversal(root->left, count);

                // Recursively check right subtree
                traversal(root->right, count);
            }
        }
    }

    // Main function that returns total number of leaf nodes
    int countLeaves(Node* root) {
        
        int count = 0;   // Initialize leaf counter
        
        // Call traversal function
        traversal(root, count);
        
        // Return total leaf count
        return count;
    }
};
