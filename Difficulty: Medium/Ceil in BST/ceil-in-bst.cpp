class Solution {
  public:
    int findCeil(Node* root, int x) {
        // Initialize the ceil value as -1 (in case no ceil exists)
        int ceilVal = -1;
        
        // Traverse the tree
        while (root) {
            // Case 1: If current node value equals x, it’s the exact ceil
            if (root->data == x) {
                ceilVal = root->data;
                break;
            }
            
            // Case 2: If current node value is smaller, move right
            // (since larger values may be the ceil)
            else if (root->data < x) {
                root = root->right;
            }
            
            // Case 3: If current node value is greater, record it as a possible ceil
            // and move left to find a smaller one
            else {
                ceilVal = root->data;
                root = root->left;
            }
        }
        
        return ceilVal;
    }
};
