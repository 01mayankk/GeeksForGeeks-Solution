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
  
    // Function to insert a new key into the Binary Search Tree (BST)
    Node* insert(Node* root, int key) {
        
        // 🟢 Base case: If tree (or subtree) is empty, create a new node
        if (root == nullptr) {
            return new Node(key);
        }
        
        // 🔹 If key is greater than current node's data → go to the right subtree
        else if (key > root->data) {
            // Recursively insert in right subtree and update the right child link
            root->right = insert(root->right, key);
        }
        // 🔹 Otherwise, if key is smaller → go to the left subtree
        else if (key < root->data) {
            // Recursively insert in left subtree and update the left child link
            root->left = insert(root->left, key);
        }
        // ⚪ If key == root->data, we do nothing (no duplicates in BST)
        // (You can handle duplicates here if required)
        
        // 🔙 Return the (possibly unchanged) root pointer of this subtree
        return root;
    }
};

