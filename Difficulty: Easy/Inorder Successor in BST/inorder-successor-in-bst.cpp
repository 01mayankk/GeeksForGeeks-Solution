class Solution {
  public:
   
    // int traversal(Node* root, Node* x) {
    //     if (root != nullptr) {
    //         traversal(root->left, x);
    //         if(root -> data == x -> data)
    //         {
    //             return (root->right -> data);
    //         }
    //         traversal(root->right, x);
    //     }
        
    //     return -1;
    // }

    
    int inOrderSuccessor(Node *root, Node *x) {
       Node* succ = nullptr;

        while (root) {
            if (x->data < root->data) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return succ ? succ->data : -1;
         
    }
};
