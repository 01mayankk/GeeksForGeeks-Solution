class Solution {
  public:
   
    void traversal(Node* root, vector<int>& v) {
        if (root != nullptr) {
            traversal(root->left, v);
            v.push_back(root->data);
            traversal(root->right, v);
        }
    }

    
    int inOrderSuccessor(Node *root, Node *x) {
        vector<int> v;
        traversal(root, v);

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == x->data) {
                if (i + 1 < v.size()) {
                    return v[i + 1];  
                } else {
                    return -1; 
                }
            }
        }

        return -1; 
    }
};
