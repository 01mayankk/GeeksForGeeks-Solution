/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
public:

    void solve(Node* root, int currentLen, int expectedVal, int& maxLen) {
        if (!root) return;

        // If current node's value matches the expected value in sequence
        if (root->data == expectedVal) {
            currentLen++;
        } else {
            // Reset sequence length to 1 starting from this node
            currentLen = 1;
        }

        // Update the global maximum length found so far
        maxLen = max(maxLen, currentLen);

        // Recursively traverse left and right subtrees with expected next value (root->data + 1)
        solve(root->left, currentLen, root->data + 1, maxLen);
        solve(root->right, currentLen, root->data + 1, maxLen);
    }
    
    
    int longestConsecutive(Node* root) {
        if (!root) return -1;

        int maxLen = 0;
        // Start DFS from root with initial length 0 and expected value equal to root->data
        solve(root, 0, root->data, maxLen);

        // If no consecutive path of length >= 2 exists, return -1
        return (maxLen > 1) ? maxLen : -1;
    }
};