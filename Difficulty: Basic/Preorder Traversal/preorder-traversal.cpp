/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    void traversal(Node* root, vector<int>&result)
    {
        if(root)
        {
            result.push_back(root -> data);
            traversal(root -> left, result);
            traversal(root -> right, result);
        }
    }
    vector<int> preOrder(Node* root) {
        // code here
        
        vector<int>result;
        traversal(root, result);
        
        return result;
    }
};



