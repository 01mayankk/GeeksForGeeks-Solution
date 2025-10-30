/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
  
    // Helper function to perform preorder traversal of a binary tree
    // and store the visited node values in the given vector.
    void preOrder(Node* root, vector<int>& arr)
    {
        // If the current node is not null
        if(root)
        {
            // Visit the current node (root)
            arr.push_back(root->data);
            
            // Recursively traverse the left subtree
            preOrder(root->left, arr);
            
            // Recursively traverse the right subtree
            preOrder(root->right, arr);
        }
    }
  
    // Function to check if two binary trees are identical
    bool isIdentical(Node* r1, Node* r2) {
        // Vectors to store preorder traversal of both trees
        vector<int> tree1;
        vector<int> tree2;
        
        // Perform preorder traversal on both trees
        preOrder(r1, tree1);
        preOrder(r2, tree2);
        
        // Compare the traversal results
        // If both vectors are equal, the trees have the same structure and values
        if(tree1 == tree2)
        {
            return true;  // Trees are identical
        }
        
        // Otherwise, they are different
        return false;
    }
};
