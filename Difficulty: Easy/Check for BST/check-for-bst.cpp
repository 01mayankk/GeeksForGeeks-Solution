class Solution {
  public:
    bool isValidBST(Node* root, int minVal, int maxVal) {
        if (root == nullptr) return true;
        
        if (root->data <= minVal || root->data >= maxVal)
            return false;
        
        return isValidBST(root->left, minVal, root->data) &&
               isValidBST(root->right, root->data, maxVal);
    }

    bool isBST(Node* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
