/* The Node structure is defined as:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:

    // Helper function: performs an inorder traversal (Left → Root → Right)
    // and stores all node values in 'result' vector in sorted order.
    void inOrder(Node* root, vector<int>& result) {
        if (root) {
            inOrder(root->left, result);          // Traverse the left subtree
            result.push_back(root->data);         // Visit the root (store current node)
            inOrder(root->right, result);         // Traverse the right subtree
        }
    }

    int kthLargest(Node *root, int k) {
        // Vector to store the inorder traversal of BST
        vector<int> result;

        // Perform inorder traversal → gives elements in ascending order
        inOrder(root, result);

        // The inorder traversal gives sorted data:
        // result[0] = smallest, result[n-1] = largest
        // So, the Kth largest element = (n - K)th index in sorted order

        int n = result.size();

        // Return the Kth largest element
        // Example: for K = 1 → largest → result[n - 1]
        // for K = 2 → 2nd largest → result[n - 2], etc.
        return result[n - k];
    }
};
