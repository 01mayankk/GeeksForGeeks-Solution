/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:
    Node* solve(vector<int>& pre, vector<int>& preMirror, int pre_s, int pre_e, int m_s, int m_e) {
        // Base case: if start index exceeds end index, return null
        if (pre_s > pre_e) {
            return nullptr;
        }

        // Create the root node using the current start of preorder traversal
        Node* root = new Node(pre[pre_s]);

        // If this is a leaf node (only one element in the current range)
        if (pre_s == pre_e) {
            return root;
        }

        // The left child is the very next element in the preorder traversal
        int left_val = pre[pre_s + 1];

        // Search for the left child's value in the preMirror traversal
        int idx = m_s + 1;
        while (idx <= m_e && preMirror[idx] != left_val) {
            idx++;
        }

        // Calculate the number of nodes in the left subtree
        int left_nodes = m_e - idx + 1;

        // Recursively construct the left and right subtrees
        root->left = solve(pre, preMirror, pre_s + 1, pre_s + left_nodes, idx, m_e);
        root->right = solve(pre, preMirror, pre_s + left_nodes + 1, pre_e, m_s + 1, idx - 1);

        return root;
    }

    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {
        int n = pre.size();
        return solve(pre, preMirror, 0, n - 1, 0, n - 1);
    }
};