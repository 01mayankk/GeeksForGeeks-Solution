/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    // Helper function to recursively traverse the BST and search for the key
    void traversal(Node* root, int key, bool& found)
    {
        if(root)  // Base condition: check if current node exists
        {
            // If current node's data matches the key, mark found as true
            if(root -> data == key)
            {
                found = true;
                return;
            }
            // If key is greater than current node's data, move to right subtree
            else if(root -> data < key)
            {
                traversal(root -> right, key, found);
            }
            // If key is smaller, move to left subtree
            else
            {
                traversal(root -> left, key, found);
            }
        }
        // If root is NULL, recursion will stop automatically (base case)
    }

    bool search(Node* root, int key) {
        // Main function to start searching in BST
        
        bool found = false;  // Initially, key is not found
        
        // If the tree is empty, directly return false
        if(root == nullptr)
        {
            return false;
        }
        
        // Start recursive search from the root
        traversal(root, key, found);
        
        // Return true if key found, otherwise false
        return found;
    }
};
