/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to find predecessor and successor of a given key in a BST
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;   // Will hold the predecessor node (largest smaller than key)
        Node* suc = NULL;   // Will hold the successor node (smallest greater than key)
        Node* curr = root;  // Pointer to traverse the tree

        // ----------------------------
        // STEP 1: Find the Successor
        // ----------------------------
        // Successor = smallest node whose value is strictly greater than key
        while (curr) {
            if (curr->data > key) {
                // Current node is greater than key, so it can be a possible successor
                suc = curr;

                // But there might exist a smaller node still greater than key
                // hence move left to find a closer candidate
                curr = curr->left;
            } else {
                // Current node's data <= key → successor must be in right subtree
                curr = curr->right;
            }
        }

        // Reset curr to root before searching for predecessor
        curr = root;

        // ----------------------------
        // STEP 2: Find the Predecessor
        // ----------------------------
        // Predecessor = largest node whose value is strictly smaller than key
        while (curr) {
            if (curr->data < key) {
                // Current node is smaller than key, so it can be a possible predecessor
                pre = curr;

                // But there might exist a larger node still smaller than key
                // hence move right to find a closer candidate
                curr = curr->right;
            } else {
                // Current node's data >= key → predecessor must be in left subtree
                curr = curr->left;
            }
        }

        // Return both predecessor and successor in a vector
        // If not found, they will remain NULL
        return {pre, suc};
    }
};

