/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    void traversal(Node* root, int& node)
    {
        if(root != nullptr)
        {
            node++;
            
            traversal(root -> left, node);
            traversal(root -> right , node);
        }
    }
    int getSize(Node* root) {
        // code here
        
        if(root == nullptr)
        {
            return 0;
        }
        
        int node = 0;
        class Solution {
  public:
  
    // Recursive function to traverse the tree
    // and count the number of nodes
    void traversal(Node* root, int& node)
    {
        // Check if current node exists
        if(root != nullptr)
        {
            // Count the current node
            node++;
            
            // Traverse the left subtree
            traversal(root->left, node);
            
            // Traverse the right subtree
            traversal(root->right, node);
        }
    }

    // Function to return the total number of nodes
    // in the binary tree
    int getSize(Node* root) {
        
        // If tree is empty, size is 0
        if(root == nullptr)
        {
            return 0;
        }
        
        // Variable to store node count
        int node = 0;
        
        // Start tree traversal and counting
        traversal(root, node);
        
        // Return total number of nodes
        return node;
    }
};
        traversal(root, node);
        
        return node;
    }
};