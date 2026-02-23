/*
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
    vector<int> leftView(Node *root) {
    
    vector<int> result;   // This will store the left view nodes
    
    // If tree is empty, return empty result
    if(root == nullptr)
        return result;
    
    queue<Node*> q;       // Queue for level order traversal (BFS)
    q.push(root);         // Start with root node
    
    // Continue until all levels are processed
    while(!q.empty())
    {
        int levelSize = q.size();  
        // Store the number of nodes at current level
        // Important: This must be fixed before the loop because
        // queue size changes when we push child nodes
        
        for(int i = 0; i < levelSize; i++)
        {
            Node* node = q.front();  // Get front node
            q.pop();                 // Remove it from queue
            
            // If it's the first node of this level,
            // then it is visible from the left side
            if(i == 0)
                result.push_back(node->data);
            
            // Push left child first (important for left view)
            if(node->left)
                q.push(node->left);
                
            // Push right child
            if(node->right)
                q.push(node->right);
        }
    }
    
    return result;  // Return the left view list
}
};