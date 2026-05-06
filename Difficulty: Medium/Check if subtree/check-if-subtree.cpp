/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    // Function to check whether two trees are identical
    bool isIdentical(Node* root1, Node* root2)
    {
        // If both nodes are NULL, trees are identical
        if(root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        
        // If one is NULL and the other is not, not identical
        if(root1 == nullptr || root2 == nullptr)
        {
            return false;
        }
        
        // Check:
        // 1. Current node values are same
        // 2. Left subtrees are identical
        // 3. Right subtrees are identical
        return (root1->data == root2->data) &&
               isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    }
  
    bool isSubTree(Node *root1, Node *root2) {
        
        // If subtree is empty, it is always a subtree
        if(root2 == nullptr)
        {
            return true;
        }
        
        // If main tree becomes empty, subtree cannot exist
        if(root1 == nullptr)
        {
            return false;
        }
        
        // Check if trees rooted at current node are identical
        if(isIdentical(root1, root2))
        {
            return true;
        }
        
        // Otherwise, check in left subtree OR right subtree
        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
};