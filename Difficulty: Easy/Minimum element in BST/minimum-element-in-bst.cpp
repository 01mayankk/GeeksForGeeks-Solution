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
  
    int minValue(Node* root) {
        if (!root) return -1;  // empty BST

        Node* current = root;
        
        while (current->left != nullptr) { // move left
            current = current->left;
        }
        return current->data;  // leftmost node data
    }

};