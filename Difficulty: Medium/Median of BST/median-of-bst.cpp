/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    // Helper function to perform inorder traversal of BST
    // Inorder traversal (Left → Root → Right) of a BST gives sorted values
    void inOrder(Node* root, vector<int>& result) {
        if (root) {
            // Traverse the left subtree
            inOrder(root->left, result);
            
            // Visit the current node (store its value)
            result.push_back(root->data);
            
            // Traverse the right subtree
            inOrder(root->right, result);
        }
    }

    // Function to find the median of all elements in the BST
    int findMedian(Node* root) {
        // Vector to store inorder traversal (which will be sorted)
        vector<int> result;

        // Base case: if tree is empty, return 0 (no median)
        if (root == nullptr) {
            return 0;
        }

        // Step 1: Perform inorder traversal to get all node values in sorted order
        inOrder(root, result);

        // Step 2: Find the total number of nodes
        int len = result.size();

        // Step 3: Determine median
        // If number of nodes is even → return lower middle element (as per GFG’s convention)
        // Example: [1, 2, 3, 4] → median = 2  (element at index (4/2) - 1)
        if (len % 2 == 0) {
            return result[(len / 2) - 1];
        }

        // If number of nodes is odd → return the middle element
        // Example: [1, 2, 3, 4, 5] → median = 3  (element at index len/2)
        return result[len / 2];
    }
};